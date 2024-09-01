// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture.h"
#include "Tickable.h"
#include "ShaderParameterMacros.h"
#include "ShaderParameterUtils.h"
#include "ShaderParameterStruct.h"
#include "RHIResources.h"
#include "RenderCommandFence.h"
#include "Delegates/DelegateCombinations.h"
#include "Engine/StaticMesh.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/EngineTypes.h"
#if ENGINE_MINOR_VERSION > 1
#include "RayTracingPayloadType.h"
#endif
#include "RayTracingInstanceBufferUtil.h"
#include "BuiltInRayTracingShaders.h"
#include "RaytracedTexture.h"
#include "RaytracedBevel.generated.h"

/**
 * 
 */
class FRaytracedBevelStaticVertexDeclaration : public FRenderResource
{
public:
	FVertexDeclarationRHIRef VertexDeclarationRHI;

#if ENGINE_MINOR_VERSION > 2
	virtual void InitRHI(FRHICommandListBase& RHICmdList)override
#else
	virtual void InitRHI()override
#endif
	{
		FVertexDeclarationElementList Elements;
		Elements.Add(FVertexElement(0, 0, VET_Float3, 0, sizeof(FVector3f)));
		Elements.Add(FVertexElement(1, 0, VET_PackedNormal, 1, 2 * sizeof(FPackedNormal)));
		Elements.Add(FVertexElement(1, sizeof(FPackedNormal), VET_PackedNormal, 2, 2 * sizeof(FPackedNormal)));
		VertexDeclarationRHI = RHICreateVertexDeclaration(Elements);
	}

	virtual void ReleaseRHI()
	{
		VertexDeclarationRHI.SafeRelease();
	}
};

class FRaytracedBevelABCVertexDeclaration : public FRenderResource
{
public:
	FVertexDeclarationRHIRef VertexDeclarationRHI;

#if ENGINE_MINOR_VERSION > 2
	virtual void InitRHI(FRHICommandListBase& RHICmdList)override
#else
	virtual void InitRHI()override
#endif
	{
		FVertexDeclarationElementList Elements;
		Elements.Add(FVertexElement(0, 0, VET_Float3, 0, sizeof(FVector3f)));
		VertexDeclarationRHI = RHICreateVertexDeclaration(Elements);
	}

	virtual void ReleaseRHI()
	{
		VertexDeclarationRHI.SafeRelease();
	}
};

class FRaytracedBevelSceneVS : public FGlobalShader
{
	DECLARE_SHADER_TYPE(FRaytracedBevelSceneVS, Global)
	SHADER_USE_PARAMETER_STRUCT(FRaytracedBevelSceneVS, FGlobalShader);
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters,)
    SHADER_PARAMETER(FMatrix44f, LocalToWorld)
	SHADER_PARAMETER(FMatrix44f, LocalToWorldInverseTranspose)
    SHADER_PARAMETER(FMatrix44f, VPMatrix)
	END_SHADER_PARAMETER_STRUCT()
public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return true;
	}
};

class FRaytracedDynamicBevelSceneVS : public FGlobalShader
{
	DECLARE_SHADER_TYPE(FRaytracedDynamicBevelSceneVS, Global)
	SHADER_USE_PARAMETER_STRUCT(FRaytracedDynamicBevelSceneVS, FGlobalShader);
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters,)
    SHADER_PARAMETER(FMatrix44f, LocalToWorld)
	SHADER_PARAMETER(FMatrix44f, LocalToWorldInverseTranspose)
    SHADER_PARAMETER(FMatrix44f, VPMatrix)
	SHADER_PARAMETER_SRV(Buffer<SNORM float4>, TangentBuffer)
	SHADER_PARAMETER_SRV(Buffer<SNORM float4>, NormalBuffer)
	END_SHADER_PARAMETER_STRUCT()
public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return true;
	}
};

class FRaytracedBevelScenePS : public FGlobalShader
{
	DECLARE_SHADER_TYPE(FRaytracedBevelScenePS, Global)
	SHADER_USE_PARAMETER_STRUCT(FRaytracedBevelScenePS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
	END_SHADER_PARAMETER_STRUCT()

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return true;
	}
};

class FRenderBevelNormalPS : public FGlobalShader
{
	DECLARE_SHADER_TYPE(FRenderBevelNormalPS, Global)
	SHADER_USE_PARAMETER_STRUCT(FRenderBevelNormalPS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(FIntPoint, Resolution)
		SHADER_PARAMETER_TEXTURE(Texture2D, DepthStencil)
		SHADER_PARAMETER_TEXTURE(Texture2D, ModelBevel)
		SHADER_PARAMETER_SAMPLER(SamplerState, ModelBevelSampler)
	END_SHADER_PARAMETER_STRUCT()

 	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
 	{
 		return true;
 	}
};

class FBevelNormalRGS : public FBuiltInRayTracingShader
{
	DECLARE_GLOBAL_SHADER(FBevelNormalRGS);
	SHADER_USE_ROOT_PARAMETER_STRUCT(FBevelNormalRGS, FBuiltInRayTracingShader);
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(uint32, Frame)
		SHADER_PARAMETER(FIntPoint, Resolution)
		SHADER_PARAMETER(float, MaxAngle)
		SHADER_PARAMETER(float, Roundness)
		SHADER_PARAMETER(float, Radius)
		SHADER_PARAMETER(uint32, NumSamples)
		SHADER_PARAMETER_SRV(RaytracingAccelerationStructure, TLAS)
		SHADER_PARAMETER_UAV(RWTexture2D<float4>, RWBevelNormal)
		SHADER_PARAMETER_SRV(Texture2D<float2>, DepthStencilSRV)		
		SHADER_PARAMETER_SRV(Texture2D, SceneNormalSRV)
		SHADER_PARAMETER(FMatrix44f,SVPositionToTranslatedWorld)
		SHADER_PARAMETER(FVector4f, InvDeviceZToWorldZTransform)
		SHADER_PARAMETER_SRV(Buffer<SNORM float4>, TangentsBuffer)
		SHADER_PARAMETER(FMatrix44f, LocalToWorldInverseTranspose)
	END_SHADER_PARAMETER_STRUCT()

#if ENGINE_MINOR_VERSION > 1
 	static ERayTracingPayloadType GetRayTracingPayloadType(const int32 PermutationId)
 	{
 		return ERayTracingPayloadType::Minimal;
 	}
#endif

// 	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
// 	{
// 		return ShouldCompileRayTracingShadersForProject(Parameters.Platform);
// 	}


	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		OutEnvironment.SetDefine(TEXT("BEVEL_PACKED_NORMAL"), 0);
	}
};

class FBevelNormalRGS_PackedNormal : public FBuiltInRayTracingShader
{
	DECLARE_GLOBAL_SHADER(FBevelNormalRGS_PackedNormal);
	SHADER_USE_ROOT_PARAMETER_STRUCT(FBevelNormalRGS_PackedNormal, FBuiltInRayTracingShader);
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(uint32, Frame)
		SHADER_PARAMETER(FIntPoint, Resolution)
		SHADER_PARAMETER(float, MaxAngle)
		SHADER_PARAMETER(float, Roundness)
		SHADER_PARAMETER(float, Radius)
		SHADER_PARAMETER(uint32, NumSamples)
		SHADER_PARAMETER_SRV(RaytracingAccelerationStructure, TLAS)
		SHADER_PARAMETER_UAV(RWTexture2D<float4>, RWBevelNormal)
		SHADER_PARAMETER_SRV(Texture2D<float2>, DepthStencilSRV)		
		SHADER_PARAMETER_SRV(Texture2D, SceneNormalSRV)
		SHADER_PARAMETER(FMatrix44f,SVPositionToTranslatedWorld)
		SHADER_PARAMETER(FVector4f, InvDeviceZToWorldZTransform)
		SHADER_PARAMETER_SRV(Buffer<SNORM float4>, TangentsBuffer)
		SHADER_PARAMETER(FMatrix44f, LocalToWorldInverseTranspose)
	END_SHADER_PARAMETER_STRUCT()

#if ENGINE_MINOR_VERSION > 1
 	static ERayTracingPayloadType GetRayTracingPayloadType(const int32 PermutationId)
 	{
 		return ERayTracingPayloadType::Minimal;
 	}
#endif

// 	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
// 	{
// 		return ShouldCompileRayTracingShadersForProject(Parameters.Platform);
// 	}

	static void ModifyCompilationEnvironment(const FGlobalShaderPermutationParameters& Parameters, FShaderCompilerEnvironment& OutEnvironment)
	{
		OutEnvironment.SetDefine(TEXT("BEVEL_PACKED_NORMAL"), 1);
	}
};

class FBevelNormalCHS : public FBuiltInRayTracingShader
{
	DECLARE_GLOBAL_SHADER(FBevelNormalCHS);
public:

	FBevelNormalCHS() = default;
	FBevelNormalCHS(const ShaderMetaType::CompiledShaderInitializerType& Initializer):FBuiltInRayTracingShader(Initializer)
	{}

#if ENGINE_MINOR_VERSION > 1
 	static ERayTracingPayloadType GetRayTracingPayloadType(const int32 PermutationId)
 	{
 		return ERayTracingPayloadType::Minimal;
 	}
#endif

// 	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
// 	{
// 		return ShouldCompileRayTracingShadersForProject(Parameters.Platform);
// 	}
};

class FBevelNormalMS : public FBuiltInRayTracingShader
{
	DECLARE_GLOBAL_SHADER(FBevelNormalMS);
public:
	FBevelNormalMS() = default;
	FBevelNormalMS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
		: FBuiltInRayTracingShader(Initializer)
	{}

#if ENGINE_MINOR_VERSION > 1
	static ERayTracingPayloadType GetRayTracingPayloadType(const int32 PermutationId)
	{
		return ERayTracingPayloadType::Minimal;
 	}
#endif

// 	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
// 	{
// 		return ShouldCompileRayTracingShadersForProject(Parameters.Platform);
// 	}
};

class FBevelSpatialAccumulationCS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FBevelSpatialAccumulationCS);
	SHADER_USE_PARAMETER_STRUCT(FBevelSpatialAccumulationCS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(FIntPoint, Resolution)
		SHADER_PARAMETER(float, Radius)
		SHADER_PARAMETER_SRV(Texture2D, SceneNormalSRV)
		SHADER_PARAMETER_SRV(Texture2D, DepthStencilSRV)
		SHADER_PARAMETER_TEXTURE(Texture2D, SignalInput)
		SHADER_PARAMETER_SAMPLER(SamplerState, InputSampler)
		SHADER_PARAMETER_UAV(RWTexture2D<float4>, SignalOutput)
		SHADER_PARAMETER(FMatrix44f, SVPositionToTranslatedWorld)
		SHADER_PARAMETER(FVector4f, InvDeviceZToWorldZTransform)
		SHADER_PARAMETER(float, WorldDepthToPixelWorldRadius)
	END_SHADER_PARAMETER_STRUCT()
		
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return true;
	}
};


class FBevelResource : public FRayTraceTextureResource
{
protected:
#if ENGINE_MINOR_VERSION > 2
	virtual void InitRHI(FRHICommandListBase& RHICmdList)override;
#else
	virtual void InitRHI()override;
#endif
public:
	FBevelResource(class URaytracedBevelNormal* InOwner);

	void PrepareSceneValuesStatic(FRHICommandListImmediate& RHICmdList, TWeakObjectPtr<UStaticMesh> StaticMesh, int32 LODIndex, FTransform WorldTransform, const FMatrix44f& VPMatrix, FTexture2DRHIRef Output);
	void PrepareSceneValuesABC(FRHICommandListImmediate& RHICmdList, FBufferRHIRef _VertexBuffer, FShaderResourceViewRHIRef _TangentBuffer, FShaderResourceViewRHIRef _NormalBuffer, FBufferRHIRef _IndexBuffer,
	uint32 NumVertices, uint32 NumPrimitives, ERenderTargetActions RenderTargetActions, EDepthStencilTargetActions DepthStencilTargetActions, 
	const FMatrix44f& LocalToRelativeWorld, const FMatrix44f& VPMatrix, ERHIFeatureLevel::Type InFeatureLevel, FTexture2DRHIRef Output);

	void RayTraced(FRHICommandListImmediate& RHICmdList, ERHIFeatureLevel::Type FeatureLevel,
	FBufferRHIRef _VertexBuffer, FBufferRHIRef _IndexBuffer, FShaderResourceViewRHIRef Tangents, uint32 NumVertices, uint32 NumPrimitives, const FMatrix44f& LocalToRelativeWorld, const struct FRayTracedMatrices& Matrices,
	float MaxAngle, float Roundness, float Radius, int32 NumSamples, bool bPackedTangents, bool bClearUAV);

	void SpatialAccumulation(FRHICommandListImmediate& RHICmdList, const struct FRayTracedMatrices& Matrices, const float Radius);

	void RenderBevel(FRHICommandListImmediate& RHICmdList, bool bDenoise);
private:
	void ReleaseTextures();
#if ENGINE_MINOR_VERSION > 2
	void CreateTextures(FRHICommandListBase& RHICmdList);
#else
	void CreateTextures();
#endif
public:
	bool IsRaytraceValid();
public:
	FTexture2DRHIRef BevelResult[2];
	FUnorderedAccessViewRHIRef BevelUAV[2];
	FShaderResourceViewRHIRef BevelSRV[2];
};

USTRUCT(BlueprintType)
struct FBevelRandomResult
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Model Bevel")
	FVector Position = FVector::ZeroVector;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Model Bevel")
	FVector Direction = FVector::ZeroVector;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Model Bevel")
	float Length = 1.f;
};


UCLASS(BlueprintType,Blueprintable,hidecategories= Compression,hidecategories= Texture,hidecategories= Adjustments,hidecategories= Compositing,hidecategories= LevelOfDetail, hidecategories = FilePath)
class RTASSETS_API URaytracedBevelNormal : public URaytracedTexture
{
	GENERATED_UCLASS_BODY()

protected:
	FTextureResource* CreateResource() override;

	//~ Begin UObject Interface
	void PostLoad() override;
	//~ End UObject Interface
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif 
public:
#if WITH_EDITOR
	void OnBevelFilterChanged();
#endif 
public:
	UPROPERTY()
	float MaxAngle = 90.0;

	UPROPERTY()
	float Roundness = 1.0;

	UPROPERTY()
	float Radius = 1;

	UPROPERTY()
	int32 NumSamples = 4;

	UPROPERTY()
	TEnumAsByte<enum TextureFilter> BevelFilter = TextureFilter::TF_Nearest;
private:
	void RenderStaticMesh(const FRayTracedMatrices& View, UStaticMesh* StaticMesh, const FMatrix& LocalToWorld, ERHIFeatureLevel::Type InFeatureLevel, uint32 LODIndex) override;
	void RenderABCPrimitive(const FRayTracedMatrices& View, const FMeshBatch* MeshBatch, const FMatrix& LocalToWorld, const FBox& LocalBounds, ERHIFeatureLevel::Type InFeatureLevel) override;
};


 