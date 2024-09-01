// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture.h"
#include "RHIResources.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/EngineTypes.h"
#include "MeshBatch.h"
#include "PrimitiveSceneProxy.h"
#include "Runtime/Renderer/Private/SceneRendering.h"
#include "RaytracedTexture.generated.h"


struct FRayTracedMatrices
{
	FRayTracedMatrices() {};
	
	FVector ViewPosition = FVector::ZeroVector	;
	FIntPoint ViewSize = FIntPoint(1,1);
	FMatrix ProjectionMatrix = FMatrix::Identity;
	FMatrix InvProjectionMatrix = FMatrix::Identity;
	FMatrix ViewRotationMatrix = FMatrix::Identity;
	FMatrix ViewProjectionMatrix = FMatrix::Identity;
	FMatrix SVPositionToTranslatedWorld = FMatrix::Identity;
	FMatrix ScreenToClipMatrix = FMatrix::Identity;
	FMatrix ScreenToTranslatedWorld = FMatrix::Identity;
	FVector4 InvDeviceZToWorldZTransform = FVector4::Zero();
};


class FRayTraceTextureResource : public FTextureResource
{
protected:
	uint32 GetSizeX() const override;
	uint32 GetSizeY() const override;

	void ReleaseRHI() override;
public:
	TWeakObjectPtr<class URaytracedTexture> Owner = nullptr;
public:
	FRayTraceTextureResource(class URaytracedTexture* InOwner);

	void SetViewSize(FRHICommandListImmediate& RHICmdList, const FIntPoint& New);
protected:
	virtual void ReleaseTextures();
#if ENGINE_MINOR_VERSION > 2
	virtual void CreateTextures(FRHICommandListBase& RHICmdList) = 0;
#else
	virtual void CreateTextures() = 0;
#endif
public:
	virtual bool IsRaytraceValid() = 0;
protected:
	FIntPoint SizeXY = FIntPoint(1,1);
	FMatrix LocalToWorld;
public:
	FTexture2DRHIRef DepthStencil = nullptr;
	FShaderResourceViewRHIRef SceneDepthSRV = nullptr;

	FTexture2DRHIRef SceneNormal = nullptr;
	FShaderResourceViewRHIRef SceneNormalSRV = nullptr;
};

UCLASS(Abstract)
class RTASSETS_API URaytracedTexture : public UTexture
{
	GENERATED_UCLASS_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = RaytraceAmbientOcclusion, AssetRegistrySearchable)
	int32 SizeX = 1280;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = RaytraceAmbientOcclusion, AssetRegistrySearchable)
	int32 SizeY = 720;

protected:
	//~ Begin UTexture Interface.
	ETextureClass GetTextureClass() const { return ETextureClass::RenderTarget; }
	float GetSurfaceWidth() const override { return (float)SizeX; }
	float GetSurfaceHeight() const override { return (float)SizeY; }
	float GetSurfaceDepth() const override { return 0; }
	uint32 GetSurfaceArraySize() const override { return 0; }
	EMaterialValueType GetMaterialType() const override;
	uint32 CalcTextureMemorySizeEnum(ETextureMipCount Enum) const override;
	//~ End UTexture Interface.

	//~ Begin UObject Interface
	void Serialize(FArchive& Ar) override;
	void PostLoad() override;
	void GetResourceSizeEx(FResourceSizeEx& CumulativeResourceSize) override;
	FString GetDesc() override;
	//~ End UObject Interface

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif 
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Raytraced", meta = (DisplayName = "静态网格"))
	UObject* Asset = nullptr;
	
	UPROPERTY()
	bool bDenoise = true;

	UPROPERTY()
	bool bProjectionMatrixUnadjusted = false;
protected:
	virtual void RenderStaticMesh(const FRayTracedMatrices& View, UStaticMesh* StaticMesh, const FMatrix& LocalToWorld, ERHIFeatureLevel::Type FeatureLevel, const uint32 LODIndex) {};
	virtual void RenderABCPrimitive(const FRayTracedMatrices& View, const FMeshBatch* MeshBatch, const FMatrix& LocalToWorld, const FBox& LocalBounds, ERHIFeatureLevel::Type FeatureLevel) {};
public:
	static FVector4 CreateInvDeviceZToWorldZTransform(const FMatrix& ProjMatrix);
	static FMatrix InvertProjectionMatrix(const FMatrix& M);
	static FMatrix ScreenToClipProjectionMatrix(const FMatrix& ProjectionMatrix, bool bIsPerspectiveProjection);
public:
	struct FRaytracedData
	{
		const FMeshBatch* Mesh = nullptr;
		TWeakObjectPtr<URaytracedTexture> Texture;
		FRayTracedMatrices RenderMatrix;
		const FPrimitiveSceneProxy* Proxy = nullptr;
	};
	static TArray<FRaytracedData>FindRaytracedTextures(const FViewInfo* RenderView, const FMeshBatch* Mesh);
	static void PostOpaqueRender(const class FPostOpaqueRenderParameters& Parameters);
};


 