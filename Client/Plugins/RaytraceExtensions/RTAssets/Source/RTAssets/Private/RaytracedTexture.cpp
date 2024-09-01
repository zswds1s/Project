// Fill out your copyright notice in the Description page of Project Settings.


#include "RaytracedTexture.h"
#include "RHICommandList.h"
#include "RHI.h"
#include "RendererInterface.h"
#include "Runtime/Renderer/Private/ScenePrivate.h"

#include "UnrealClient.h"
#include "Engine/GameViewportClient.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LocalPlayer.h"
#if ENGINE_MINOR_VERSION > 1
#include "Materials/MaterialRenderProxy.h"
#else
#include "MaterialShared.h"
#endif

uint32 FRayTraceTextureResource::GetSizeX() const
{
	return Owner->SizeX;
}


uint32 FRayTraceTextureResource::GetSizeY() const
{
	return Owner->SizeY;
}

void FRayTraceTextureResource::ReleaseRHI()
{
	FTextureResource::ReleaseRHI();
	ReleaseTextures();
	Owner = nullptr;
}

FRayTraceTextureResource::FRayTraceTextureResource(class URaytracedTexture* InOwner)
{
	Owner = InOwner;
	SizeXY = FIntPoint(InOwner->SizeX, InOwner->SizeY);
	LocalToWorld = FTransform::Identity.ToMatrixWithScale();
};

void FRayTraceTextureResource::SetViewSize(FRHICommandListImmediate& RHICmdList, const FIntPoint& New)
{
	FIntPoint FinalSize = FIntPoint(FMath::Max(New.X, 1), FMath::Max(New.Y, 1));
	if (FinalSize.X != SizeXY.X || FinalSize.Y != SizeXY.Y)
	{
		SizeXY = FinalSize;
		ReleaseTextures();
#if ENGINE_MINOR_VERSION > 2
		CreateTextures(RHICmdList);
#else
		CreateTextures();
#endif
	}
}

void FRayTraceTextureResource::ReleaseTextures()
{
	if(Owner.IsValid())
		RHIUpdateTextureReference(Owner->TextureReference.TextureReferenceRHI, nullptr);

	TextureRHI.SafeRelease();
	DepthStencil.SafeRelease();
	SceneNormal.SafeRelease();
}

#if ENGINE_MINOR_VERSION > 2
void FRayTraceTextureResource::CreateTextures(FRHICommandListBase& RHICmdList)
#else
void FRayTraceTextureResource::CreateTextures()
#endif
{
	{
		FRHITextureCreateDesc Desc =
		FRHITextureCreateDesc::Create2D(TEXT("DepthStencil"), SizeXY, EPixelFormat::PF_DepthStencil)
		.SetFlags(ETextureCreateFlags::DepthStencilTargetable | ETextureCreateFlags::ShaderResource)
		.SetClearValue(FClearValueBinding::DepthFar)
		.SetInitialState(ERHIAccess::SRVMask);

		this->DepthStencil = RHICreateTexture(Desc);
#if ENGINE_MINOR_VERSION > 2
		this->SceneDepthSRV = RHICmdList.CreateShaderResourceView(this->DepthStencil, 0);
#else
		this->SceneDepthSRV = RHICreateShaderResourceView(this->DepthStencil, 0);
#endif
	}

	{
		FRHITextureCreateDesc Desc =
		FRHITextureCreateDesc::Create2D(TEXT("NormalBuffer"), SizeXY, EPixelFormat::PF_A32B32G32R32F)
		.SetFlags(ETextureCreateFlags::RenderTargetable | ETextureCreateFlags::ShaderResource)
		.SetClearValue(FClearValueBinding(FLinearColor(0, 0, 0, 0)))
		.SetInitialState(ERHIAccess::SRVMask);

		this->SceneNormal = RHICreateTexture(Desc);
#if ENGINE_MINOR_VERSION > 2
		this->SceneNormalSRV = RHICmdList.CreateShaderResourceView(this->SceneNormal, 0);
#else
		this->SceneNormalSRV = RHICreateShaderResourceView(this->SceneNormal, 0);
#endif
	}
}


URaytracedTexture::URaytracedTexture(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	SizeX = 340;
	SizeY = 180;

	this->NeverStream = true;
	this->bForceMiplevelsToBeResident = true;
}

EMaterialValueType URaytracedTexture::GetMaterialType() const
{
	return MCT_Texture2D;
}

uint32 URaytracedTexture::CalcTextureMemorySizeEnum(ETextureMipCount Enum) const
{
	return SizeX*SizeY*sizeof(float);
}

void URaytracedTexture::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);

	Ar.UsingCustomVersion(FRenderingObjectVersion::GUID);
}

void URaytracedTexture::PostLoad()
{
	float OriginalSizeX = SizeX;
	float OriginalSizeY = SizeY;

	SizeX = FMath::Min<int32>(SizeX, 1024);
	SizeY = FMath::Min<int32>(SizeY, 1024);

	// Maintain aspect ratio if clamped
	if (SizeX != OriginalSizeX || SizeY != OriginalSizeY)
	{
		float ScaleX = SizeX / OriginalSizeX;
		float ScaleY = SizeY / OriginalSizeY;

		if (ScaleX < ScaleY)
		{
			SizeY = OriginalSizeY * ScaleX;
		}
		else
		{
			SizeX = OriginalSizeX * ScaleY;
		}
	}

	Super::PostLoad();

	if (UStaticMesh* StaticMesh = Cast<UStaticMesh>(Asset))
		StaticMesh->WaitForPendingInitOrStreaming();
}


FString URaytracedTexture::GetDesc()
{
	return FString::Printf(TEXT("Raytraced Texture %dx%d"), SizeX, SizeY);
}

#if WITH_EDITOR
void URaytracedTexture::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(URaytracedTexture, Asset))
	{
		if (UStaticMesh* StaticMesh = Cast<UStaticMesh>(Asset))
			StaticMesh->WaitForPendingInitOrStreaming();
	}
	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

void URaytracedTexture::GetResourceSizeEx(FResourceSizeEx& CumulativeResourceSize)
{
	Super::GetResourceSizeEx(CumulativeResourceSize);

	int32 NumBytes = CalcTextureMemorySizeEnum(TMC_AllMips);

	CumulativeResourceSize.AddUnknownMemoryBytes(NumBytes);
}

FVector4 URaytracedTexture::CreateInvDeviceZToWorldZTransform(const FMatrix& ProjMatrix)
{
	float DepthMul = (float)ProjMatrix.M[2][2];
	float DepthAdd = (float)ProjMatrix.M[3][2];

	if (DepthAdd == 0.f)
	{
		DepthAdd = 0.00000001f;
	}

	bool bIsPerspectiveProjection = ProjMatrix.M[3][3] < 1.0f;

	if (bIsPerspectiveProjection)
	{
		float SubtractValue = DepthMul / DepthAdd;

		SubtractValue -= 0.00000001f;

		return FVector4(
			0.0f,
			0.0f,
			1.0f / DepthAdd,
			SubtractValue
		);
	}
	else
	{
		return FVector4(
			(float)(1.0f / ProjMatrix.M[2][2]),
			(float)(-ProjMatrix.M[3][2] / ProjMatrix.M[2][2] + 1.0f),
			0.0f,
			1.0f
		);
	}
}

FMatrix URaytracedTexture::InvertProjectionMatrix(const FMatrix& M)
{
	if (M.M[1][0] == 0.0f &&
		M.M[3][0] == 0.0f &&
		M.M[0][1] == 0.0f &&
		M.M[3][1] == 0.0f &&
		M.M[0][2] == 0.0f &&
		M.M[1][2] == 0.0f &&
		M.M[0][3] == 0.0f &&
		M.M[1][3] == 0.0f &&
		M.M[2][3] == 1.0f &&
		M.M[3][3] == 0.0f)
	{
		double a = M.M[0][0];
		double b = M.M[1][1];
		double c = M.M[2][2];
		double d = M.M[3][2];
		double s = M.M[2][0];
		double t = M.M[2][1];

		return FMatrix(
			FPlane(1.0 / a, 0.0f, 0.0f, 0.0f),
			FPlane(0.0f, 1.0 / b, 0.0f, 0.0f),
			FPlane(0.0f, 0.0f, 0.0f, 1.0 / d),
			FPlane(-s / a, -t / b, 1.0f, -c / d)
		);
	}
	else
	{
		return M.Inverse();
	}
}

FMatrix URaytracedTexture::ScreenToClipProjectionMatrix(const FMatrix& ProjectionMatrix, bool bIsPerspectiveProjection)
{
	if (bIsPerspectiveProjection)
	{
		return FMatrix(
			FPlane(1, 0, 0, 0),
			FPlane(0, 1, 0, 0),
			FPlane(0, 0, ProjectionMatrix.M[2][2], 1.0f),
			FPlane(0, 0, ProjectionMatrix.M[3][2], 0.0f));
	}
	else
	{
		return FMatrix(
			FPlane(1, 0, 0, 0),
			FPlane(0, 1, 0, 0),
			FPlane(0, 0, ProjectionMatrix.M[2][2], 0.0f),
			FPlane(0, 0, ProjectionMatrix.M[3][2], 1.0f));
	}
}


TArray<URaytracedTexture::FRaytracedData> URaytracedTexture::FindRaytracedTextures(const FViewInfo* RenderView, const FMeshBatch* Mesh)
{
	TArray<URaytracedTexture*> RaytracedTextures;
	TArray<FGuid> ParameterIds;
	TArray<FMaterialParameterInfo> TextureParameterInfos;
	Mesh->MaterialRenderProxy->GetMaterialInterface()->GetAllTextureParameterInfo(TextureParameterInfos, ParameterIds);

	for (FMaterialParameterInfo& Info : TextureParameterInfos)
	{
		UTexture* Texture = nullptr;
		if (Mesh->MaterialRenderProxy->GetMaterialInterface()->GetTextureParameterValue(Info, Texture, true))
		{
			if (URaytracedTexture* RTTex = Cast<URaytracedTexture>(Texture))
			{
				RaytracedTextures.AddUnique(RTTex);
			}
		}
	}

	TArrayView<const TObjectPtr<UObject>> Textures = Mesh->MaterialRenderProxy->GetMaterialInterface()->GetReferencedTextures();
	for (TObjectPtr<UObject> Texture : Textures)
	{
		if (URaytracedTexture* RaytraceTex = Cast<URaytracedTexture>(Texture))
		{
			RaytracedTextures.AddUnique(RaytraceTex);
		}
	}

	TArray<FRaytracedData> Output;
	for (URaytracedTexture* Texture : RaytracedTextures)
	{
		FRaytracedData Raytraced;
		Raytraced.Mesh = Mesh;
		Raytraced.Texture = Texture;

		FRayTracedMatrices& Matrix = Raytraced.RenderMatrix;
		Matrix.ViewPosition = RenderView->ViewLocation;
		Matrix.ViewSize = RenderView->UnscaledViewRect.Size();
		Matrix.ViewRotationMatrix = RenderView->ViewMatrices.GetViewMatrix();
		Matrix.ScreenToClipMatrix = ScreenToClipProjectionMatrix(RenderView->ProjectionMatrixUnadjustedForRHI, RenderView->ViewMatrices.IsPerspectiveProjection());

		if (Texture->bProjectionMatrixUnadjusted)
		{
			Matrix.ProjectionMatrix = RenderView->ProjectionMatrixUnadjustedForRHI;
			Matrix.InvProjectionMatrix = InvertProjectionMatrix(RenderView->ProjectionMatrixUnadjustedForRHI);
			Matrix.ViewProjectionMatrix = RenderView->ViewMatrices.GetViewMatrix() * RenderView->ProjectionMatrixUnadjustedForRHI;

			FMatrix InvTranslatedViewProjectionMatrix = Matrix.InvProjectionMatrix * RenderView->ViewMatrices.GetInvTranslatedViewMatrix();
			{
				FVector4f ViewSizeAndInvSize = FVector4f(Matrix.ViewSize.X, Matrix.ViewSize.Y, 1.0f / float(Matrix.ViewSize.X), 1.0f / float(Matrix.ViewSize.Y));
				float Mx = 2.0f * ViewSizeAndInvSize.Z;
				float My = -2.0f * ViewSizeAndInvSize.W;
				float Ax = -1.0f;
				float Ay = 1.0f;

				Matrix.SVPositionToTranslatedWorld =
				FMatrix(FPlane(Mx, 0, 0, 0), FPlane(0, My, 0, 0), FPlane(0, 0, 1, 0), FPlane(Ax, Ay, 0, 1)) * InvTranslatedViewProjectionMatrix;
			}

			Matrix.ScreenToTranslatedWorld = Matrix.ScreenToClipMatrix * InvTranslatedViewProjectionMatrix;
			Matrix.InvDeviceZToWorldZTransform = CreateInvDeviceZToWorldZTransform(RenderView->ProjectionMatrixUnadjustedForRHI);
		}
		else
		{
			Matrix.ProjectionMatrix = RenderView->ViewMatrices.GetProjectionMatrix();
			Matrix.InvProjectionMatrix = RenderView->ViewMatrices.GetInvProjectionMatrix();
			Matrix.ViewProjectionMatrix = RenderView->ViewMatrices.GetViewProjectionMatrix();

			FMatrix InvTranslatedViewProjectionMatrix = RenderView->ViewMatrices.GetInvTranslatedViewProjectionMatrix();
			{
				FVector4f ViewSizeAndInvSize = FVector4f(Matrix.ViewSize.X, Matrix.ViewSize.Y, 1.0f / float(Matrix.ViewSize.X), 1.0f / float(Matrix.ViewSize.Y));
				float Mx = 2.0f * ViewSizeAndInvSize.Z;
				float My = -2.0f * ViewSizeAndInvSize.W;
				float Ax = -1.0f;
				float Ay = 1.0f;

				Matrix.SVPositionToTranslatedWorld =
				FMatrix(FPlane(Mx, 0, 0, 0), FPlane(0, My, 0, 0), FPlane(0, 0, 1, 0), FPlane(Ax, Ay, 0, 1)) * InvTranslatedViewProjectionMatrix;
			}

			Matrix.ScreenToTranslatedWorld = Matrix.ScreenToClipMatrix * InvTranslatedViewProjectionMatrix;
			Matrix.InvDeviceZToWorldZTransform = CreateInvDeviceZToWorldZTransform(RenderView->ProjectionMatrixUnadjustedForRHI);
		}

		Output.Add(Raytraced);
	}
	return Output;
}

void URaytracedTexture::PostOpaqueRender(const FPostOpaqueRenderParameters& Parameters)
{
	{
		TArray<FPrimitiveSceneProxy*> Proxies = Parameters.View->Family->Scene->GetRenderScene()->PrimitiveSceneProxies;
		for (FPrimitiveSceneProxy* Proxy : Proxies)
		{
			TArray<FRaytracedData> Raytraced;

			TArray<FMeshBatch> MeshElements;
			Proxy->GetMeshDescription(Proxy->GetLOD(Parameters.View), MeshElements);
			for (FMeshBatch& Mesh : MeshElements)
			{
				TArray<FRaytracedData> Result = URaytracedTexture::FindRaytracedTextures(Parameters.View, &Mesh);
				for (FRaytracedData& Raytrace : Result)
				{
					Raytrace.Proxy = Proxy;
				}
				Raytraced.Append(Result);
			}

			for (FRaytracedData& Raytrace : Raytraced)
			{
				if (!Raytrace.Texture.IsValid() || !Raytrace.Texture->Asset)
					continue;

				if (UStaticMesh* StaticMesh = Cast<UStaticMesh>(Raytrace.Texture->Asset))
					Raytrace.Texture->RenderStaticMesh(Raytrace.RenderMatrix, StaticMesh, Proxy->GetLocalToWorld(), Parameters.View->FeatureLevel, Proxy->GetLOD(Parameters.View));
			}
		}
	}

	{
		TArray<FRaytracedData> Raytraced;
		for (const FMeshBatchAndRelevance& Value : Parameters.View->DynamicMeshElements)
		{
			if (Value.Mesh->GetNumPrimitives() == 0 || Value.Mesh->bWireframe)
				continue;
			TArray<FRaytracedData> Result = URaytracedTexture::FindRaytracedTextures(Parameters.View, Value.Mesh);
			for (FRaytracedData& Raytrace : Result)
			{
				Raytrace.Proxy = Value.PrimitiveSceneProxy;
			}
			Raytraced.Append(Result);
		}

		for (FRaytracedData& Raytrace : Raytraced)
		{
			if (!Raytrace.Texture.IsValid() || !Raytrace.Texture->Asset)
				continue;

			FString ClassName = Raytrace.Texture->Asset->GetClass()->GetName();
			if (ClassName == TEXT("GeometryCache"))
				Raytrace.Texture->RenderABCPrimitive(Raytrace.RenderMatrix, Raytrace.Mesh, Raytrace.Proxy->GetLocalToWorld(), Raytrace.Proxy->GetLocalBounds().GetBox(), Parameters.View->FeatureLevel);
		}
	}
}

