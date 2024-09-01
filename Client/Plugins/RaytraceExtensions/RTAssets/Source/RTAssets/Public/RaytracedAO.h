// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture.h"
#include "RHIResources.h"
#include "RHICommandList.h"
#include "RaytracedTexture.h"
#include "RayTracingDefinitions.h" 
#include "RayTracingInstanceBufferUtil.h"
#include "BuiltInRayTracingShaders.h"
#include "Shader.h"
#include "ShaderParameterMacros.h"
#include "ShaderParameterUtils.h"
#include "ShaderParameterStruct.h"
#if ENGINE_MINOR_VERSION > 1
#include "RayTracingPayloadType.h"
#endif
#include "RayTracedAO.generated.h"

class FRaytracedAOStaticVertexDeclaration : public FRenderResource
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

class FRaytracedAOABCVertexDeclaration : public FRenderResource
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

class FRaytracedAOSceneVS : public FGlobalShader
{
	DECLARE_SHADER_TYPE(FRaytracedAOSceneVS, Global)
	SHADER_USE_PARAMETER_STRUCT(FRaytracedAOSceneVS, FGlobalShader);
	BEGIN_SHADER_PARAMETER_STRUCT(FParameters,)
    SHADER_PARAMETER(FMatrix44f, LocalToWorld)
	SHADER_PARAMETER(FMatrix44f, LocalToWorldInverseTranspose)
	SHADER_PARAMETER(FMatrix44f, PrevVPMatrix)
    SHADER_PARAMETER(FMatrix44f, VPMatrix)
	END_SHADER_PARAMETER_STRUCT()
public:
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return true;
	}
};

class FRaytracedDynamicAOSceneVS : public FGlobalShader
{
	DECLARE_SHADER_TYPE(FRaytracedDynamicAOSceneVS, Global)
	SHADER_USE_PARAMETER_STRUCT(FRaytracedDynamicAOSceneVS, FGlobalShader);
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

class FRaytracedAOScenePS : public FGlobalShader
{
	DECLARE_SHADER_TYPE(FRaytracedAOScenePS, Global)
	SHADER_USE_PARAMETER_STRUCT(FRaytracedAOScenePS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(FIntPoint, Resolution)
	END_SHADER_PARAMETER_STRUCT()

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return true;
	}
};


class FComputeAmbientOcclusionRGS : public FBuiltInRayTracingShader
{
	DECLARE_GLOBAL_SHADER(FComputeAmbientOcclusionRGS);
	SHADER_USE_ROOT_PARAMETER_STRUCT(FComputeAmbientOcclusionRGS, FBuiltInRayTracingShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_SRV(RaytracingAccelerationStructure, TLAS)
		SHADER_PARAMETER_UAV(RWTexture2D<float2>, RWHitResult)
		SHADER_PARAMETER_SRV(Texture2D<float3>, SceneNormalSRV)
		SHADER_PARAMETER_SRV(Texture2D<float>, DepthStencilSRV)
		SHADER_PARAMETER(FMatrix44f,SVPositionToTranslatedWorld)
		SHADER_PARAMETER(FVector4f, InvDeviceZToWorldZTransform)
		SHADER_PARAMETER(int, SamplesPerPixel)
		SHADER_PARAMETER(float, MaxRayDistance)
		SHADER_PARAMETER(float, Intensity)
		SHADER_PARAMETER(float, MaxNormalBias)
		SHADER_PARAMETER(uint32, FrameIndex)
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
};

class FComputeAmbientOcclusionCHS : public FBuiltInRayTracingShader
{
	DECLARE_GLOBAL_SHADER(FComputeAmbientOcclusionCHS);
public:

	FComputeAmbientOcclusionCHS() = default;
	FComputeAmbientOcclusionCHS(const ShaderMetaType::CompiledShaderInitializerType& Initializer):FBuiltInRayTracingShader(Initializer)
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

class FComputeAmbientOcclusionMS : public FBuiltInRayTracingShader
{
	DECLARE_GLOBAL_SHADER(FComputeAmbientOcclusionMS);
public:
	FComputeAmbientOcclusionMS() = default;
	FComputeAmbientOcclusionMS(const ShaderMetaType::CompiledShaderInitializerType& Initializer)
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

class FAOSpatialAccumulationCS : public FGlobalShader
{
	DECLARE_GLOBAL_SHADER(FAOSpatialAccumulationCS);
	SHADER_USE_PARAMETER_STRUCT(FAOSpatialAccumulationCS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER(FIntPoint, Resolution)
		SHADER_PARAMETER(FVector4f, SceneBufferUVToScreenPosition)
		SHADER_PARAMETER_SRV(Texture2D<float3>, SceneNormalSRV)
		SHADER_PARAMETER_SRV(Texture2D, DepthStencilSRV)
		SHADER_PARAMETER_SRV(Texture2D<float2>, SignalInput)
		SHADER_PARAMETER_UAV(RWTexture2D<float4>, SignalOutput)
		SHADER_PARAMETER(FMatrix44f, SVPositionToTranslatedWorld)
		SHADER_PARAMETER(FVector4f, InvDeviceZToWorldZTransform)
		SHADER_PARAMETER(float, WorldDepthToPixelWorldRadius)
		SHADER_PARAMETER(FMatrix44f, ScreenToTranslatedWorld)
		SHADER_PARAMETER(int, SamplesPerPixel)
	END_SHADER_PARAMETER_STRUCT()
		
	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return true;
	}
};

class FRenderAmbientOcclusionPS : public FGlobalShader
{
	DECLARE_SHADER_TYPE(FRenderAmbientOcclusionPS, Global)
	SHADER_USE_PARAMETER_STRUCT(FRenderAmbientOcclusionPS, FGlobalShader);

	BEGIN_SHADER_PARAMETER_STRUCT(FParameters, )
		SHADER_PARAMETER_TEXTURE(Texture2D, AmbientOcclusion)
		SHADER_PARAMETER_SAMPLER(SamplerState, AmbientOcclusionSampler)
	END_SHADER_PARAMETER_STRUCT()

	static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& Parameters)
	{
		return true;
	}
};


class FRTAOResource : public FRayTraceTextureResource
{
protected:
#if ENGINE_MINOR_VERSION > 2
	virtual void InitRHI(FRHICommandListBase& RHICmdList)override;
#else
	virtual void InitRHI()override;
#endif
public:
	FRTAOResource(class URaytracedAmbientOcclusion* InOwner);

	void PrepareSceneValuesStatic(FRHICommandListImmediate& RHICmdList, TWeakObjectPtr<UStaticMesh> StaticMesh, int32 LODIndex, FTransform WorldTransform, const FMatrix44f& VPMatrix);
	void PrepareSceneValuesABC(FRHICommandListImmediate& RHICmdList, FBufferRHIRef _VertexBuffer, FShaderResourceViewRHIRef _TangentBuffer, FShaderResourceViewRHIRef _NormalBuffer, FBufferRHIRef _IndexBuffer,
	uint32 NumVertices, uint32 NumPrimitives, ERenderTargetActions RenderTargetActions, EDepthStencilTargetActions DepthStencilTargetActions, 
	const FMatrix44f& LocalToRelativeWorld, const FMatrix44f& VPMatrix, ERHIFeatureLevel::Type InFeatureLevel);

	void RayTraced(FRHICommandListImmediate& RHICmdList, ERHIFeatureLevel::Type FeatureLevel,
	FBufferRHIRef _VertexBuffer, FBufferRHIRef _IndexBuffer, uint32 NumVertices, uint32 NumPrimitives, const FMatrix44f& LocalToRelativeWorld,
	const struct FRayTracedMatrices& Matrices, int32 SamplesPerPixel, float Intensity, float MaxRayDistance, float MaxNormalBias, bool bClearUAV);

	void RenderAmbientOcclusion(FRHICommandListImmediate& RHICmdList, bool bDenoise);

	void SpatialAccumulation(FRHICommandListImmediate& RHICmdList, FShaderResourceViewRHIRef Input, FUnorderedAccessViewRHIRef Output, const struct FRayTracedMatrices& Matrices, int32 SamplesPerPixel);
private:
	void ReleaseTextures() override;
#if ENGINE_MINOR_VERSION > 2
	void CreateTextures(FRHICommandListBase& RHICmdList)override;
#else
	void CreateTextures()override;
#endif
public:
	bool IsRaytraceValid()override;
public:
	FTexture2DRHIRef HitResult;
	FUnorderedAccessViewRHIRef HitResultUAV;
	FShaderResourceViewRHIRef HitResultSRV;

	FTexture2DRHIRef DenoiseResult[3];
	FUnorderedAccessViewRHIRef DenoiseUAV[3];
	FShaderResourceViewRHIRef DenoiseSRV[3];
};

UCLASS(BlueprintType,Blueprintable,hidecategories= Compression,hidecategories= Texture,hidecategories= Adjustments,hidecategories= Compositing,hidecategories= LevelOfDetail, hidecategories= FilePath)
class RTASSETS_API URaytracedAmbientOcclusion : public URaytracedTexture
{
	GENERATED_BODY()

protected:
	FTextureResource* CreateResource() override;
public:
	UPROPERTY()
	int32 SamplesPerPixel = 8;

	UPROPERTY()
	float Intensity = 5;

	UPROPERTY()
	float MaxRayDistance = 500.f;

	UPROPERTY()
	float MaxNormalBias = 0.1f;
private:
	void RenderStaticMesh(const FRayTracedMatrices& View, UStaticMesh* StaticMesh, const FMatrix& LocalToWorld, ERHIFeatureLevel::Type InFeatureLevel, uint32 LODIndex) override;
	void RenderABCPrimitive(const FRayTracedMatrices& View, const FMeshBatch* MeshBatch, const FMatrix& LocalToWorld, const FBox& LocalBounds, ERHIFeatureLevel::Type InFeatureLevel) override;
};


 