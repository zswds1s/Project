// Fill out your copyright notice in the Description page of Project Settings.


#include "RayTracedAO.h"
#include "RHIStaticStates.h"
#include "RenderingThread.h"
#include "RHICommandList.h"
#include "RHI.h"
#if ENGINE_MINOR_VERSION > 1
#include "GlobalRenderResources.h" 
#endif
#include "ClearQuad.h"
#include "ScreenRendering.h"
#include "CommonRenderResources.h"
#if ENGINE_MINOR_VERSION > 1
#include "RayTracingPayloadType.h"
#endif
#include "RayTracingInstanceBufferUtil.h"
#include "BuiltInRayTracingShaders.h"
#include "Runtime/Renderer/Private/SceneRendering.h"
#include "Runtime/Renderer/Private/ScenePrivate.h"
#if ENGINE_MINOR_VERSION > 1
#include "Materials/MaterialRenderProxy.h"
#else
#include "MaterialShared.h"
#endif
#include "GeometryCacheVertexFactory.h"

TGlobalResource<FRaytracedAOStaticVertexDeclaration> GRaytracedAOStaticVertexDeclaration;
TGlobalResource<FRaytracedAOABCVertexDeclaration> GRaytracedAOABCVertexDeclaration;

IMPLEMENT_SHADER_TYPE(, FRaytracedAOSceneVS, TEXT("/Plugin/RTAssets/ScreenSpace.usf"), TEXT("DrawPrimitiveVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FRaytracedDynamicAOSceneVS, TEXT("/Plugin/RTAssets/ScreenSpace.usf"), TEXT("DrawDynamicPrimitiveVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FRaytracedAOScenePS, TEXT("/Plugin/RTAssets/ScreenSpace.usf"), TEXT("DrawPrimitivePS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FRenderAmbientOcclusionPS, TEXT("/Plugin/RTAssets/ScreenSpace.usf"), TEXT("RenderRTAmbientOcclusionPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FAOSpatialAccumulationCS, TEXT("/Plugin/RTAssets/RaytracedAO.usf"), TEXT("SpatialAccumulationCS"), SF_Compute);

IMPLEMENT_SHADER_TYPE(, FComputeAmbientOcclusionRGS, TEXT("/Plugin/RTAssets/RaytracedAO.usf"), TEXT("ComputeAmbientOcclusionRGS"), SF_RayGen);
IMPLEMENT_SHADER_TYPE(, FComputeAmbientOcclusionCHS, TEXT("/Plugin/RTAssets/RaytracedAO.usf"), TEXT("ComputeAmbientOcclusionCHS"), SF_RayHitGroup);
IMPLEMENT_SHADER_TYPE(, FComputeAmbientOcclusionMS, TEXT("/Plugin/RTAssets/RaytracedAO.usf"), TEXT("ComputeAmbientOcclusionMS"), SF_RayMiss);
 

#if ENGINE_MINOR_VERSION > 2
void FRTAOResource::InitRHI(FRHICommandListBase& RHICmdList)
#else
void FRTAOResource::InitRHI()
#endif
{
	FSamplerStateInitializerRHI SamplerStateInitializer
	(
		ESamplerFilter::SF_Bilinear,
		ESamplerAddressMode::AM_Clamp,
		ESamplerAddressMode::AM_Clamp,
		ESamplerAddressMode::AM_Clamp
	);
	SamplerStateRHI = GetOrCreateSamplerState(SamplerStateInitializer);


	bIgnoreGammaConversions = true;	

	FIntPoint FinalSize = FIntPoint(FMath::Max(GetSizeX(), (uint32)1), FMath::Max(GetSizeY(), (uint32)1));
	SizeXY = FinalSize;

#if ENGINE_MINOR_VERSION > 2
	CreateTextures(RHICmdList);
#else
	CreateTextures();
#endif
}

FRTAOResource::FRTAOResource(class URaytracedAmbientOcclusion* InOwner)
:FRayTraceTextureResource(InOwner)
{
	Owner = InOwner;
	SizeXY = FIntPoint(InOwner->SizeX, InOwner->SizeY);
	LocalToWorld = FTransform::Identity.ToMatrixWithScale();
};

void FRTAOResource::PrepareSceneValuesStatic(FRHICommandListImmediate& RHICmdList, TWeakObjectPtr<UStaticMesh> StaticMesh, int32 LODIndex, FTransform WorldTransform, const FMatrix44f& VPMatrix)
{
	if (!StaticMesh->GetRenderData()->LODResources.IsValidIndex(LODIndex))
		LODIndex = 0;

	FBufferRHIRef _VertexBuffer = StaticMesh->GetRenderData()->LODResources[LODIndex].VertexBuffers.PositionVertexBuffer.VertexBufferRHI;
	FBufferRHIRef _NormalBuffer = StaticMesh->GetRenderData()->LODResources[LODIndex].VertexBuffers.StaticMeshVertexBuffer.TangentsVertexBuffer.VertexBufferRHI;
	FBufferRHIRef _IndexBuffer = StaticMesh->GetRenderData()->LODResources[LODIndex].IndexBuffer.IndexBufferRHI;

	uint32 NumVertices = StaticMesh->GetRenderData()->LODResources[LODIndex].GetNumVertices();
	uint32 NumPrimitives = StaticMesh->GetRenderData()->LODResources[LODIndex].GetNumTriangles();

	{
		FRHIRenderPassInfo PassInfo;
		PassInfo.ColorRenderTargets[0].RenderTarget = SceneNormal;
		PassInfo.ColorRenderTargets[0].ResolveTarget = nullptr;
		PassInfo.ColorRenderTargets[0].ArraySlice = -1;
		PassInfo.ColorRenderTargets[0].MipIndex = 0;
		PassInfo.ColorRenderTargets[0].Action = ERenderTargetActions::Clear_Store;

		PassInfo.DepthStencilRenderTarget.DepthStencilTarget = DepthStencil;
		PassInfo.DepthStencilRenderTarget.ResolveTarget = nullptr;
		PassInfo.DepthStencilRenderTarget.Action = EDepthStencilTargetActions::ClearDepthStencil_StoreDepthStencil;
		PassInfo.DepthStencilRenderTarget.ExclusiveDepthStencil = FExclusiveDepthStencil::DepthWrite_StencilWrite;

		TransitionRenderPassTargets(RHICmdList, PassInfo);
		RHICmdList.BeginRenderPass(PassInfo, TEXT("PrepareSceneValues1"));
		RHICmdList.SetViewport(0, 0, 0, SizeXY.X, SizeXY.Y, 1.f);

		FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
		TShaderMapRef<FRaytracedAOSceneVS> VertexShader(GlobalShaderMap);
		TShaderMapRef<FRaytracedAOScenePS> PixelShader(GlobalShaderMap);

		FGraphicsPipelineStateInitializer PSOIniter;
		RHICmdList.ApplyCachedRenderTargets(PSOIniter);
		PSOIniter.DepthStencilState = TStaticDepthStencilState<true, CF_DepthNearOrEqual>::GetRHI();
		PSOIniter.BlendState = TStaticBlendState<CW_RGBA, BO_Add, BF_One, BF_Zero, BO_Add, BF_One, BF_Zero>::GetRHI();
		PSOIniter.RasterizerState = TStaticRasterizerState<FM_Solid, CM_CW>::GetRHI();
		PSOIniter.PrimitiveType = PT_TriangleList;

		PSOIniter.BoundShaderState.VertexDeclarationRHI = GRaytracedAOStaticVertexDeclaration.VertexDeclarationRHI;
		PSOIniter.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
		PSOIniter.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
		SetGraphicsPipelineState(RHICmdList, PSOIniter, 0);

		{
			FRaytracedAOSceneVS::FParameters Parameters;
			Parameters.LocalToWorld = FMatrix44f(WorldTransform.ToMatrixWithScale());
			Parameters.LocalToWorldInverseTranspose = (Parameters.LocalToWorld.Inverse()).GetTransposed();
			Parameters.VPMatrix = FMatrix44f(VPMatrix);
			SetShaderParameters(RHICmdList, VertexShader, VertexShader.GetVertexShader(), Parameters);
		}

		{
			FRaytracedAOScenePS::FParameters Parameters;
			Parameters.Resolution = DepthStencil->GetSizeXY();
			SetShaderParameters(RHICmdList, PixelShader, PixelShader.GetPixelShader(), Parameters);
		}

		RHICmdList.SetStreamSource(0, _VertexBuffer, 0);
		RHICmdList.SetStreamSource(1, _NormalBuffer, 0);
		RHICmdList.DrawIndexedPrimitive(_IndexBuffer, 0, 0, NumVertices, 0, NumPrimitives, 1);

		RHICmdList.EndRenderPass();
		RHICmdList.Transition(FRHITransitionInfo(SceneNormal, ERHIAccess::Unknown, ERHIAccess::SRVMask));
		RHICmdList.Transition(FRHITransitionInfo(DepthStencil, ERHIAccess::Unknown, ERHIAccess::SRVMask));
	}
};

void FRTAOResource::PrepareSceneValuesABC(FRHICommandListImmediate& RHICmdList, 
FBufferRHIRef _VertexBuffer, FShaderResourceViewRHIRef _TangentBuffer, FShaderResourceViewRHIRef _NormalBuffer, FBufferRHIRef _IndexBuffer, uint32 NumVertices, uint32 NumPrimitives,
ERenderTargetActions RenderTargetActions, EDepthStencilTargetActions DepthStencilTargetActions, const FMatrix44f& LocalToRelativeWorld, 
const FMatrix44f& VPMatrix, ERHIFeatureLevel::Type InFeatureLevel)
{
	FRHIRenderPassInfo PassInfo;
	PassInfo.ColorRenderTargets[0].RenderTarget = SceneNormal;
	PassInfo.ColorRenderTargets[0].ResolveTarget = nullptr;
	PassInfo.ColorRenderTargets[0].ArraySlice = -1;
	PassInfo.ColorRenderTargets[0].MipIndex = 0;
	PassInfo.ColorRenderTargets[0].Action = RenderTargetActions;

	PassInfo.DepthStencilRenderTarget.DepthStencilTarget = DepthStencil;
	PassInfo.DepthStencilRenderTarget.ResolveTarget = nullptr;
	PassInfo.DepthStencilRenderTarget.Action = DepthStencilTargetActions;
	PassInfo.DepthStencilRenderTarget.ExclusiveDepthStencil = FExclusiveDepthStencil::DepthWrite_StencilWrite;

	TransitionRenderPassTargets(RHICmdList, PassInfo);
	RHICmdList.BeginRenderPass(PassInfo, TEXT("PrepareSceneValues1"));
	RHICmdList.SetViewport(0, 0, 0, SizeXY.X, SizeXY.Y, 1.f);

	FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	TShaderMapRef<FRaytracedDynamicAOSceneVS> VertexShader(GlobalShaderMap);
	TShaderMapRef<FRaytracedAOScenePS> PixelShader(GlobalShaderMap);

	FGraphicsPipelineStateInitializer PSOIniter;
	RHICmdList.ApplyCachedRenderTargets(PSOIniter);
	PSOIniter.DepthStencilState = TStaticDepthStencilState<true, CF_DepthNearOrEqual>::GetRHI();
	PSOIniter.BlendState = TStaticBlendState<CW_RGBA, BO_Add, BF_One, BF_Zero, BO_Add, BF_One, BF_Zero>::GetRHI();
	PSOIniter.RasterizerState = TStaticRasterizerState<FM_Solid, CM_CW>::GetRHI();
	PSOIniter.PrimitiveType = PT_TriangleList;

	PSOIniter.BoundShaderState.VertexDeclarationRHI = GRaytracedAOABCVertexDeclaration.VertexDeclarationRHI;
	PSOIniter.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
	PSOIniter.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
	SetGraphicsPipelineState(RHICmdList, PSOIniter, 0);

	{
		FRaytracedDynamicAOSceneVS::FParameters Parameters;
		Parameters.LocalToWorld = LocalToRelativeWorld.GetMatrixWithoutScale();
		Parameters.LocalToWorldInverseTranspose = (Parameters.LocalToWorld.Inverse()).GetTransposed();
		Parameters.VPMatrix = FMatrix44f(VPMatrix);
		Parameters.TangentBuffer = _TangentBuffer;
		Parameters.NormalBuffer = _NormalBuffer;
		SetShaderParameters(RHICmdList, VertexShader, VertexShader.GetVertexShader(), Parameters);
	}

	{
		FRaytracedAOScenePS::FParameters Parameters;
		Parameters.Resolution = DepthStencil->GetSizeXY();
		SetShaderParameters(RHICmdList, PixelShader, PixelShader.GetPixelShader(), Parameters);
	}

	RHICmdList.SetStreamSource(0, _VertexBuffer, 0);
	RHICmdList.DrawIndexedPrimitive(_IndexBuffer, 0, 0, NumVertices, 0, NumPrimitives, 1);

	RHICmdList.EndRenderPass();
	RHICmdList.Transition(FRHITransitionInfo(SceneNormal, ERHIAccess::Unknown, ERHIAccess::SRVMask));
	RHICmdList.Transition(FRHITransitionInfo(DepthStencil, ERHIAccess::Unknown, ERHIAccess::SRVMask));
}

void FRTAOResource::RayTraced(FRHICommandListImmediate& RHICmdList, ERHIFeatureLevel::Type InFeatureLevel,
FBufferRHIRef _VertexBuffer, FBufferRHIRef _IndexBuffer, uint32 NumVertices, uint32 NumPrimitives, const FMatrix44f& LocalToRelativeWorld,
const FRayTracedMatrices& Matrices, int32 SamplesPerPixel, float Intensity, float MaxRayDistance, float MaxNormalBias, bool bClearUAV)
{
	FRayTracingGeometryInitializer GeometryInitializer;
	GeometryInitializer.DebugName = FName("DebugRayTracedAO");
	GeometryInitializer.IndexBuffer = _IndexBuffer;
	GeometryInitializer.GeometryType = RTGT_Triangles;
	GeometryInitializer.bFastBuild = false;

	FRayTracingGeometrySegment Segment;
	Segment.VertexBuffer = _VertexBuffer;
	Segment.NumPrimitives = NumPrimitives;
	Segment.MaxVertices = NumVertices;
	GeometryInitializer.Segments.Add(Segment);
	GeometryInitializer.TotalPrimitiveCount = Segment.NumPrimitives;

#if ENGINE_MINOR_VERSION > 2
	FRayTracingGeometryRHIRef Geometry = RHICmdList.CreateRayTracingGeometry(GeometryInitializer);
#else
	FRayTracingGeometryRHIRef Geometry = RHICreateRayTracingGeometry(GeometryInitializer);
#endif


	LocalToWorld = FMatrix(LocalToRelativeWorld);

	static constexpr uint32 RTAO_NumTransforms = 1;
	static constexpr uint32 RTAO_NumInstances = 1;
	FRayTracingGeometryInstance Instance;
	Instance.GeometryRHI = Geometry;
	Instance.NumTransforms = RTAO_NumTransforms;
	Instance.Transforms = MakeArrayView(&LocalToWorld, 1);

	FRayTracingSceneWithGeometryInstances RayTracingScene = CreateRayTracingSceneWithGeometryInstances
	(
		{ Instance },
		1,
		RAY_TRACING_NUM_SHADER_SLOTS,
		1
	);


	const FRayTracingSceneInitializer2& SceneInitializer = RayTracingScene.Scene->GetInitializer();

	ERayTracingAccelerationStructureFlags SceneBuildFlags = ERayTracingAccelerationStructureFlags::FastTrace;
	FRayTracingAccelerationStructureSize SceneSizeInfo = RHICalcRayTracingSceneSize(1, SceneBuildFlags);
	FRHIResourceCreateInfo SceneBufferCreateInfo(TEXT("RayTracedAOSceneBuffer"));
	FBufferRHIRef SceneBuffer = RHICmdList.CreateBuffer(
	uint32(SceneSizeInfo.ResultSize),
	BUF_AccelerationStructure, 0 /*Stride*/, ERHIAccess::BVHWrite,
	SceneBufferCreateInfo);

	FRHIResourceCreateInfo ScratchBufferCreateInfo(TEXT("RayTracedAOScratchBuffer"));
	FBufferRHIRef ScratchBuffer = RHICmdList.CreateBuffer(
	uint32(SceneSizeInfo.BuildScratchSize),
	BUF_UnorderedAccess, GRHIRayTracingScratchBufferAlignment, ERHIAccess::UAVCompute,
	ScratchBufferCreateInfo);

	FRWBufferStructured InstanceBuffer;
#if ENGINE_MINOR_VERSION > 2
	InstanceBuffer.Initialize(RHICmdList, TEXT("RayTracedAOInstanceBuffer"), GRHIRayTracingInstanceDescriptorSize, SceneInitializer.NumNativeInstancesPerLayer[0]);
#else
	InstanceBuffer.Initialize( TEXT("RayTracedAOInstanceBuffer"), GRHIRayTracingInstanceDescriptorSize, SceneInitializer.NumNativeInstancesPerLayer[0]);
#endif
	
	FByteAddressBuffer AccelerationStructureAddressesBuffer;
#if ENGINE_MINOR_VERSION > 2
	AccelerationStructureAddressesBuffer.Initialize(RHICmdList, TEXT("RayTracedAOAccelerationStructureAddressesBuffer"), sizeof(FRayTracingAccelerationStructureAddress), BUF_Volatile);
#else
	AccelerationStructureAddressesBuffer.Initialize(TEXT("RayTracedAOAccelerationStructureAddressesBuffer"), sizeof(FRayTracingAccelerationStructureAddress), BUF_Volatile);
#endif
	

	const uint32 InstanceUploadBufferSize = SceneInitializer.NumNativeInstancesPerLayer[0] * sizeof(FRayTracingInstanceDescriptorInput);
	FRHIResourceCreateInfo InstanceCreateInfo(TEXT("RayTracedAOInstanceUploadBuffer"));
#if ENGINE_MINOR_VERSION > 2
	FBufferRHIRef InstanceUploadBuffer = RHICmdList.CreateStructuredBuffer(sizeof(FRayTracingInstanceDescriptorInput), InstanceUploadBufferSize, BUF_ShaderResource | BUF_Volatile, InstanceCreateInfo);
	FShaderResourceViewRHIRef InstanceUploadSRV = RHICmdList.CreateShaderResourceView(InstanceUploadBuffer);
#else
	FBufferRHIRef InstanceUploadBuffer = RHICreateStructuredBuffer(sizeof(FRayTracingInstanceDescriptorInput), InstanceUploadBufferSize, BUF_ShaderResource | BUF_Volatile, InstanceCreateInfo);
	FShaderResourceViewRHIRef InstanceUploadSRV = RHICreateShaderResourceView(InstanceUploadBuffer);
#endif


	const uint32 TransformUploadBufferSize = RayTracingScene.NumNativeCPUInstances * 3 * sizeof(FVector4f);
	FRHIResourceCreateInfo TransformCreateInfo(TEXT("RayTracedAOInstanceUploadBuffer"));
#if ENGINE_MINOR_VERSION > 2
	FBufferRHIRef TransformUploadBuffer = RHICmdList.CreateStructuredBuffer(sizeof(FVector4f), TransformUploadBufferSize, BUF_ShaderResource | BUF_Volatile, TransformCreateInfo);
	FShaderResourceViewRHIRef TransformUploadSRV = RHICmdList.CreateShaderResourceView(TransformUploadBuffer);
#else
	FBufferRHIRef TransformUploadBuffer = RHICreateStructuredBuffer(sizeof(FVector4f), TransformUploadBufferSize, BUF_ShaderResource | BUF_Volatile, TransformCreateInfo);
	FShaderResourceViewRHIRef TransformUploadSRV = RHICreateShaderResourceView(TransformUploadBuffer);
#endif



	RHICmdList.EnqueueLambda([BufferRHIRef = AccelerationStructureAddressesBuffer.Buffer, &SceneInitializer](FRHICommandListImmediate& RHICmdList)
	{
		FRayTracingAccelerationStructureAddress* AddressesPtr = (FRayTracingAccelerationStructureAddress*)RHICmdList.LockBuffer(
		BufferRHIRef,
		0,
		SceneInitializer.ReferencedGeometries.Num() * sizeof(FRayTracingAccelerationStructureAddress), RLM_WriteOnly);

		const uint32 NumGeometries = SceneInitializer.ReferencedGeometries.Num();
		for (uint32 GeometryIndex = 0; GeometryIndex < NumGeometries; ++GeometryIndex)
		{
			AddressesPtr[GeometryIndex] = SceneInitializer.ReferencedGeometries[GeometryIndex]->GetAccelerationStructureAddress(RHICmdList.GetGPUMask().ToIndex());
		}

		RHICmdList.UnlockBuffer(BufferRHIRef);
	});

	{
		FRayTracingInstanceDescriptorInput* InstanceUploadData = (FRayTracingInstanceDescriptorInput*)RHICmdList.LockBuffer(InstanceUploadBuffer, 0, InstanceUploadBufferSize, RLM_WriteOnly);
		FVector4f* TransformUploadData = (FVector4f*)RHICmdList.LockBuffer(TransformUploadBuffer, 0, TransformUploadBufferSize, RLM_WriteOnly);
		FillRayTracingInstanceUploadBuffer(
		RayTracingScene.Scene,
		-Matrices.ViewPosition,
		{ Instance },
		RayTracingScene.InstanceGeometryIndices,
		RayTracingScene.BaseUploadBufferOffsets,
		RayTracingScene.NumNativeGPUSceneInstances,
		RayTracingScene.NumNativeCPUInstances,
		MakeArrayView(InstanceUploadData, SceneInitializer.NumNativeInstancesPerLayer[0]),
		MakeArrayView(TransformUploadData, RayTracingScene.NumNativeCPUInstances * 3));
		RHICmdList.UnlockBuffer(TransformUploadBuffer);
		RHICmdList.UnlockBuffer(InstanceUploadBuffer);
	}

#if ENGINE_MINOR_VERSION >= 4
	BuildRayTracingInstanceBuffer(
		RHICmdList,
		nullptr,
		FVector3f(-Matrices.ViewPosition),
		InstanceBuffer.UAV,
		InstanceUploadSRV,
		AccelerationStructureAddressesBuffer.SRV,
		TransformUploadSRV,
		RayTracingScene.NumNativeGPUSceneInstances,
		RayTracingScene.NumNativeCPUInstances,
		{},
		nullptr,
		nullptr);
#elif ENGINE_MINOR_VERSION > 1
	BuildRayTracingInstanceBuffer(
		RHICmdList,
		nullptr,
		FVector3f::ZeroVector,
		FVector3f(-Matrices.ViewPosition),
		InstanceBuffer.UAV,
		InstanceUploadSRV,
		AccelerationStructureAddressesBuffer.SRV,
		TransformUploadSRV,
		RayTracingScene.NumNativeGPUSceneInstances,
		RayTracingScene.NumNativeCPUInstances,
		{},
		nullptr);
#else
	BuildRayTracingInstanceBuffer(
		RHICmdList,
		nullptr,
		FVector3f::ZeroVector,
		FVector3f(-Matrices.ViewPosition),
		InstanceBuffer.UAV,
		InstanceUploadSRV,
		AccelerationStructureAddressesBuffer.SRV,
		TransformUploadSRV,
		RayTracingScene.NumNativeGPUSceneInstances,
		RayTracingScene.NumNativeCPUInstances,
		{});
#endif


	RHICmdList.BindAccelerationStructureMemory(RayTracingScene.Scene, SceneBuffer, 0);
	RHICmdList.BuildAccelerationStructure(Geometry);

	FRayTracingSceneBuildParams BuildParams;
	BuildParams.Scene = RayTracingScene.Scene;
	BuildParams.ScratchBuffer = ScratchBuffer;
	BuildParams.ScratchBufferOffset = 0;
	BuildParams.InstanceBuffer = InstanceBuffer.Buffer;
	BuildParams.InstanceBufferOffset = 0;

	RHICmdList.BuildAccelerationStructure(BuildParams);
	RHICmdList.Transition(FRHITransitionInfo(RayTracingScene.Scene.GetReference(), ERHIAccess::BVHWrite, ERHIAccess::BVHRead));

	FShaderResourceViewInitializer RayTracingSceneViewInitializer(SceneBuffer, RayTracingScene.Scene->GetLayerBufferOffset(0), 0);
	FShaderResourceViewRHIRef RayTracingSceneView = RHICmdList.CreateShaderResourceView(RayTracingSceneViewInitializer);


	FGlobalShaderMap* ShaderMap = GetGlobalShaderMap(InFeatureLevel);
	{
		FRayTracingPipelineStateInitializer PipelineInitializer;
#if ENGINE_MINOR_VERSION > 2
		PipelineInitializer.MaxPayloadSizeInBytes = GetRayTracingPayloadTypeMaxSize(ERayTracingPayloadType::Minimal);
#else
		PipelineInitializer.MaxPayloadSizeInBytes = 4;
#endif

		auto AmbientOcclusionRGS = ShaderMap->GetShader<FComputeAmbientOcclusionRGS>();
		FRHIRayTracingShader* RayGenShaderTable[] = { AmbientOcclusionRGS.GetRayTracingShader() };
		PipelineInitializer.SetRayGenShaderTable(RayGenShaderTable);

		auto ClosestHitShader = ShaderMap->GetShader<FComputeAmbientOcclusionCHS>();
		FRHIRayTracingShader* HitShaderTable[] = { ClosestHitShader.GetRayTracingShader() };
		PipelineInitializer.SetHitGroupTable(HitShaderTable);
		PipelineInitializer.bAllowHitGroupIndexing = false;

		auto MissShader = ShaderMap->GetShader<FComputeAmbientOcclusionMS>();
		FRHIRayTracingShader* MissShaderTable[] = { MissShader.GetRayTracingShader() };
		PipelineInitializer.SetMissShaderTable(MissShaderTable);

		FRayTracingPipelineState* PipelineState = PipelineStateCache::GetAndOrCreateRayTracingPipelineState(RHICmdList, PipelineInitializer);

		RHICmdList.SetRayTracingHitGroup(RayTracingScene.Scene, 0, 0, 0, PipelineState, 0, 0, nullptr, 0, nullptr, 0);
		RHICmdList.SetRayTracingMissShader(RayTracingScene.Scene, 0, PipelineState, 0, 0, nullptr, 0);

		FComputeAmbientOcclusionRGS::FParameters AmbientOcclusionParameters;
		AmbientOcclusionParameters.TLAS = RayTracingSceneView;
		AmbientOcclusionParameters.RWHitResult = HitResultUAV;
		AmbientOcclusionParameters.SceneNormalSRV = SceneNormalSRV;
		AmbientOcclusionParameters.DepthStencilSRV = SceneDepthSRV;
		AmbientOcclusionParameters.SVPositionToTranslatedWorld = FMatrix44f(Matrices.SVPositionToTranslatedWorld);
		AmbientOcclusionParameters.InvDeviceZToWorldZTransform = FVector4f(Matrices.InvDeviceZToWorldZTransform);
		AmbientOcclusionParameters.SamplesPerPixel = SamplesPerPixel;
		AmbientOcclusionParameters.Intensity = Intensity;
		AmbientOcclusionParameters.MaxRayDistance = MaxRayDistance;
		AmbientOcclusionParameters.MaxNormalBias = MaxNormalBias;//>0.01 
		AmbientOcclusionParameters.FrameIndex = GFrameCounter;
		if (bClearUAV)
			RHICmdList.ClearUAVFloat(HitResultUAV, FVector4f::Zero());

		FRayTracingShaderBindingsWriter GlobalResources;
		SetShaderParameters(GlobalResources, AmbientOcclusionRGS, AmbientOcclusionParameters);
		RHICmdList.RayTraceDispatch(PipelineState, AmbientOcclusionRGS.GetRayTracingShader(), RayTracingScene.Scene, GlobalResources, SizeXY.X, SizeXY.Y);
	}
}

void FRTAOResource::RenderAmbientOcclusion(FRHICommandListImmediate& RHICmdList, bool bDenoise)
{
	RHICmdList.Transition(FRHITransitionInfo(TextureRHI, ERHIAccess::Unknown, ERHIAccess::RTV));
	FRHIRenderPassInfo PassInfo(TextureRHI, ERenderTargetActions::Load_Store);
	RHICmdList.BeginRenderPass(PassInfo, TEXT("FlowFiledDrawTexture"));
	RHICmdList.SetViewport(0, 0, 0, TextureRHI->GetSizeX(), TextureRHI->GetSizeY(), 1.f);

	FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	TShaderMapRef<FScreenVS> VertexShader(GlobalShaderMap);
	TShaderMapRef<FRenderAmbientOcclusionPS> PixelShader(GlobalShaderMap);

	FGraphicsPipelineStateInitializer PSOIniter;
	PSOIniter.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
	PSOIniter.BlendState = TStaticBlendState<CW_RGBA, BO_Add, BF_One, BF_Zero, BO_Add, BF_One, BF_Zero>::GetRHI();
	PSOIniter.RasterizerState = TStaticRasterizerState<>::GetRHI();
	PSOIniter.PrimitiveType = PT_TriangleList;

	PSOIniter.BoundShaderState.VertexDeclarationRHI = GFilterVertexDeclaration.VertexDeclarationRHI;
	PSOIniter.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
	PSOIniter.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();

	RHICmdList.ApplyCachedRenderTargets(PSOIniter);
	SetGraphicsPipelineState(RHICmdList, PSOIniter, 0);

	{
		FRenderAmbientOcclusionPS::FParameters Parameters;
		Parameters.AmbientOcclusion = bDenoise ? DenoiseResult[1] : HitResult;
		Parameters.AmbientOcclusionSampler = TStaticSamplerState< SF_Bilinear, AM_Clamp, AM_Clamp, AM_Clamp >::GetRHI();
		SetShaderParameters(RHICmdList, PixelShader, PixelShader.GetPixelShader(), Parameters);
	}

	FModuleManager::GetModuleChecked<IRendererModule>("Renderer").DrawRectangle
	(
		RHICmdList,
		0, 0, TextureRHI->GetSizeX(), TextureRHI->GetSizeY(),
		0, 0, 1, 1,
		TextureRHI->GetSizeXY(), FIntPoint(1, 1),
		VertexShader,
		EDRF_Default
	);

	RHICmdList.EndRenderPass();
	RHICmdList.Transition(FRHITransitionInfo(TextureRHI, ERHIAccess::Unknown, ERHIAccess::SRVMask));
}


void FRTAOResource::SpatialAccumulation(FRHICommandListImmediate& RHICmdList, FShaderResourceViewRHIRef Input, FUnorderedAccessViewRHIRef Output, const struct FRayTracedMatrices& View, int32 SamplesPerPixel)
{
	FAOSpatialAccumulationCS::FParameters Parameters;
	Parameters.Resolution = View.ViewSize;
	Parameters.SceneBufferUVToScreenPosition.X = 2.0f;
	Parameters.SceneBufferUVToScreenPosition.Y = -2.0f;
	Parameters.SceneBufferUVToScreenPosition.Z = -1.0f;
	Parameters.SceneBufferUVToScreenPosition.W = 1.0f;
	Parameters.SceneNormalSRV = SceneNormalSRV;
	Parameters.DepthStencilSRV = SceneDepthSRV;
	Parameters.SignalInput = Input;
	Parameters.SignalOutput = Output;
	Parameters.SVPositionToTranslatedWorld = FMatrix44f(View.SVPositionToTranslatedWorld);
	Parameters.InvDeviceZToWorldZTransform = FVector4f(View.InvDeviceZToWorldZTransform);
	Parameters.WorldDepthToPixelWorldRadius = View.InvProjectionMatrix.M[0][0] / float(View.ViewSize.X);
	Parameters.ScreenToTranslatedWorld = FMatrix44f(View.ScreenToTranslatedWorld);
	Parameters.SamplesPerPixel = SamplesPerPixel;

	FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	TShaderMapRef<FAOSpatialAccumulationCS> ComputerShader(GlobalShaderMap);
	SetComputePipelineState(RHICmdList, ComputerShader.GetComputeShader());
	SetShaderParameters(RHICmdList, ComputerShader, ComputerShader.GetComputeShader(), Parameters);

	int32 GroupSizeX = FMath::CeilToInt(View.ViewSize.X / 8.f);
	int32 GroupSizeY = FMath::CeilToInt(View.ViewSize.Y / 8.f);
	DispatchComputeShader(RHICmdList, ComputerShader, GroupSizeX, GroupSizeY, 1);
	UnsetShaderUAVs(RHICmdList, ComputerShader, ComputerShader.GetComputeShader());
}


void FRTAOResource::ReleaseTextures()
{
	FRayTraceTextureResource::ReleaseTextures();
	HitResultUAV.SafeRelease();
	HitResultSRV.SafeRelease();
	HitResult.SafeRelease();


	DenoiseResult[0].SafeRelease();
	DenoiseUAV[0].SafeRelease();
	DenoiseSRV[0].SafeRelease();

	DenoiseResult[1].SafeRelease();
	DenoiseUAV[1].SafeRelease();
	DenoiseSRV[1].SafeRelease();

	DenoiseResult[2].SafeRelease();
	DenoiseUAV[2].SafeRelease();
	DenoiseSRV[2].SafeRelease();
}

#if ENGINE_MINOR_VERSION > 2
void FRTAOResource::CreateTextures(FRHICommandListBase& RHICmdList)
#else
void FRTAOResource::CreateTextures()
#endif
{
	if (!Owner.IsValid())
		return;

#if ENGINE_MINOR_VERSION > 2
	FRayTraceTextureResource::CreateTextures(RHICmdList);
#else
	FRayTraceTextureResource::CreateTextures();
#endif
	
	{
		const static FLazyName ClassName(TEXT("FRTAOResource"));

		FString ResourceName = Owner->GetName();
		FRHITextureCreateDesc OwnerDesc =
		FRHITextureCreateDesc::Create2D(*ResourceName)
		.SetExtent(SizeXY.X, SizeXY.Y)
		//.SetFormat(EPixelFormat::PF_R32_FLOAT)
		//.SetFormat(EPixelFormat::PF_A32B32G32R32F)
		//.SetFormat(EPixelFormat::PF_FloatRGBA)
		.SetFormat(EPixelFormat::PF_B8G8R8A8)
		.SetNumMips(1)
		.SetFlags(ETextureCreateFlags::RenderTargetable | ETextureCreateFlags::ShaderResource | ETextureCreateFlags::UAV)
		.SetInitialState(ERHIAccess::SRVMask)
		.SetClearValue(FClearValueBinding(FLinearColor(0, 0, 0, 0)))
#if ENGINE_MINOR_VERSION > 2
		.SetClassName(ClassName)
		.SetOwnerName(GetOwnerName());
#else
			;
#endif
		TextureRHI = RHICreateTexture(OwnerDesc);

		RHIUpdateTextureReference(Owner->TextureReference.TextureReferenceRHI, TextureRHI);
#if ENGINE_MINOR_VERSION > 2
		TextureRHI->SetOwnerName(*(Owner->GetName()));
#endif
		TextureRHI->SetName(Owner->GetFName());
	}

	{
		FRHITextureCreateDesc Desc =
		FRHITextureCreateDesc::Create2D(TEXT("HitResults"), SizeXY, EPixelFormat::PF_G32R32F)
		.SetFlags(ETextureCreateFlags::RenderTargetable | ETextureCreateFlags::ShaderResource | ETextureCreateFlags::UAV)
		.SetClearValue(FClearValueBinding(FLinearColor(0, 0, 0, 0)))
		.SetInitialState(ERHIAccess::SRVMask);
		this->HitResult = RHICreateTexture(Desc);

#if ENGINE_MINOR_VERSION > 2
		this->HitResultUAV = RHICmdList.CreateUnorderedAccessView(this->HitResult, 0);
		this->HitResultSRV = RHICmdList.CreateShaderResourceView(this->HitResult, 0);
#else
		this->HitResultUAV = RHICreateUnorderedAccessView(this->HitResult, 0);
		this->HitResultSRV = RHICreateShaderResourceView(this->HitResult, 0);
#endif
	}

	{
		FRHITextureCreateDesc Desc =
		FRHITextureCreateDesc::Create2D(TEXT("DenoiseAmbientOcclusion"), SizeXY, EPixelFormat::PF_B8G8R8A8)
		.SetFlags(ETextureCreateFlags::UAV | ETextureCreateFlags::ShaderResource | ETextureCreateFlags::RenderTargetable)
		.SetClearValue(FClearValueBinding::Black)
		.SetInitialState(ERHIAccess::SRVMask);

		this->DenoiseResult[0] = RHICreateTexture(Desc);
#if ENGINE_MINOR_VERSION > 2
		this->DenoiseUAV[0] = RHICmdList.CreateUnorderedAccessView(this->DenoiseResult[0], 0);
		this->DenoiseSRV[0] = RHICmdList.CreateShaderResourceView(this->DenoiseResult[0], 0);
#else
		this->DenoiseUAV[0] = RHICreateUnorderedAccessView(this->DenoiseResult[0], 0);
		this->DenoiseSRV[0] = RHICreateShaderResourceView(this->DenoiseResult[0], 0);
#endif

		this->DenoiseResult[1] = RHICreateTexture(Desc);
#if ENGINE_MINOR_VERSION > 2
		this->DenoiseUAV[1] = RHICmdList.CreateUnorderedAccessView(this->DenoiseResult[1], 0);
		this->DenoiseSRV[1] = RHICmdList.CreateShaderResourceView(this->DenoiseResult[1], 0);
#else
		this->DenoiseUAV[1] = RHICreateUnorderedAccessView(this->DenoiseResult[1], 0);
		this->DenoiseSRV[1] = RHICreateShaderResourceView(this->DenoiseResult[1], 0);
#endif
	}
}

bool FRTAOResource::IsRaytraceValid()
{
	return Owner.IsValid() && SizeXY.X > 0 && SizeXY.Y > 0 && DepthStencil.IsValid() && SceneNormal.IsValid() && HitResult.IsValid() && DenoiseResult[0].IsValid() && DenoiseResult[1].IsValid();
}

FTextureResource* URaytracedAmbientOcclusion::CreateResource()
{
	return new FRTAOResource(this);
}

void URaytracedAmbientOcclusion::RenderStaticMesh(const FRayTracedMatrices& View, UStaticMesh* StaticMesh, const FMatrix& LocalToWorld, ERHIFeatureLevel::Type InFeatureLevel, uint32 LODIndex)
{
	FTransform WorldTransform = FTransform(LocalToWorld);
	SizeX = View.ViewSize.X;
	SizeY = View.ViewSize.Y;
	if (!GetResource())
		return;

	FRTAOResource* RayTracedResource = (FRTAOResource*)GetResource();
	if (!RayTracedResource->IsRaytraceValid())
		return;

	RayTracedResource->SetViewSize(FRHICommandListExecutor::GetImmediateCommandList(), View.ViewSize);

	if (!StaticMesh || StaticMesh->HasPendingInitOrStreaming() || !StaticMesh->HasValidRenderData() || !StaticMesh->GetRenderData())
		return;

	RayTracedResource->PrepareSceneValuesStatic(FRHICommandListExecutor::GetImmediateCommandList(),
	StaticMesh,
	LODIndex,
	WorldTransform,
	FMatrix44f(View.ViewProjectionMatrix));

	if (!StaticMesh->GetRenderData()->LODResources.IsValidIndex(LODIndex))
		LODIndex = 0;

	FBufferRHIRef _VertexBuffer = StaticMesh->GetRenderData()->LODResources[LODIndex].VertexBuffers.PositionVertexBuffer.VertexBufferRHI;
	FBufferRHIRef _IndexBuffer = StaticMesh->GetRenderData()->LODResources[LODIndex].IndexBuffer.IndexBufferRHI;
	uint32 NumVertices = StaticMesh->GetRenderData()->LODResources[LODIndex].GetNumVertices();
	uint32 NumPrimitives = StaticMesh->GetRenderData()->LODResources[LODIndex].GetNumTriangles();

	RayTracedResource->RayTraced
	(
		FRHICommandListExecutor::GetImmediateCommandList(),
		InFeatureLevel,
		_VertexBuffer,
		_IndexBuffer,
		NumVertices,
		NumPrimitives,
		FMatrix44f(LocalToWorld),
		View,
		SamplesPerPixel,
		Intensity,
		MaxRayDistance,
		MaxNormalBias,
		false
	);

	if (bDenoise)
	{
		RayTracedResource->SpatialAccumulation(FRHICommandListExecutor::GetImmediateCommandList(), RayTracedResource->HitResultSRV, RayTracedResource->DenoiseUAV[0], View, SamplesPerPixel);
		RayTracedResource->SpatialAccumulation(FRHICommandListExecutor::GetImmediateCommandList(), RayTracedResource->DenoiseSRV[0], RayTracedResource->DenoiseUAV[1], View, SamplesPerPixel);
		RayTracedResource->RenderAmbientOcclusion(FRHICommandListExecutor::GetImmediateCommandList(), bDenoise);
	}
	else
	{
		RayTracedResource->RenderAmbientOcclusion(FRHICommandListExecutor::GetImmediateCommandList(), false);
	}
}

void URaytracedAmbientOcclusion::RenderABCPrimitive(const FRayTracedMatrices& View, const FMeshBatch* MeshBatch, const FMatrix& LocalToWorld, const FBox& LocalBounds, ERHIFeatureLevel::Type InFeatureLevel)
{
	SizeX = View.ViewSize.X;
	SizeY = View.ViewSize.Y;
	if (!GetResource())
		return;

	FRTAOResource* RayTracedResource = (FRTAOResource*)GetResource();
	if (!RayTracedResource->IsRaytraceValid())
		return;

	RayTracedResource->SetViewSize(FRHICommandListExecutor::GetImmediateCommandList(), View.ViewSize);

	bool bRaytraced = true;
	ERenderTargetActions RenderTargetActions = ERenderTargetActions::Clear_Store;
	EDepthStencilTargetActions DepthStencilTargetActions = EDepthStencilTargetActions::ClearDepthStencil_StoreDepthStencil;
	bool bClearUAV = true;
	for (const FMeshBatchElement& Element : MeshBatch->Elements)
	{
		FGeometryCacheVertexFactoryUserData* Data = (FGeometryCacheVertexFactoryUserData*)Element.VertexFactoryUserData;
		if (!Element.PrimitiveUniformBufferResource || Element.PrimitiveIdMode != EPrimitiveIdMode::PrimID_DynamicPrimitiveShaderData)
			continue;

		uint32 NumVertices = Element.MaxVertexIndex - Element.MinVertexIndex + 1;
		uint32 NumPrimitives = Element.GetNumPrimitives();
		FBufferRHIRef _IndexBuffer = Element.IndexBuffer->IndexBufferRHI;

#if ENGINE_MINOR_VERSION < 4
		FPrimitiveUniformShaderParameters Primitive = *(FPrimitiveUniformShaderParameters*)Element.PrimitiveUniformBufferResource->GetContents();
#endif

		RayTracedResource->PrepareSceneValuesABC(FRHICommandListExecutor::GetImmediateCommandList(),
		Data->PositionBuffer->VertexBufferRHI,
		Data->TangentXSRV,
		Data->TangentZSRV,
		_IndexBuffer,
		NumVertices,
		NumPrimitives,
		RenderTargetActions,
		DepthStencilTargetActions,
#if ENGINE_MINOR_VERSION < 4
		Primitive.LocalToRelativeWorld,
#else
		FMatrix44f(LocalToWorld),
#endif
		FMatrix44f(View.ViewProjectionMatrix),
		InFeatureLevel);

		RenderTargetActions = ERenderTargetActions::Load_Store;
		DepthStencilTargetActions = EDepthStencilTargetActions::LoadDepthNotStencil_StoreDepthNotStencil;

		RayTracedResource->RayTraced
		(
			FRHICommandListExecutor::GetImmediateCommandList(),
			InFeatureLevel,
			Data->PositionBuffer->VertexBufferRHI,
			_IndexBuffer,
			NumVertices,
			NumPrimitives,
#if ENGINE_MINOR_VERSION < 4
			Primitive.LocalToRelativeWorld,
#else
			FMatrix44f(LocalToWorld),
#endif
			View,
			SamplesPerPixel,
			Intensity,
			MaxRayDistance,
			MaxNormalBias,
			bClearUAV
		);

		bClearUAV = false;
	}

	if (bDenoise)
	{
		RayTracedResource->SpatialAccumulation(FRHICommandListExecutor::GetImmediateCommandList(), RayTracedResource->HitResultSRV, RayTracedResource->DenoiseUAV[0], View, SamplesPerPixel);
		RayTracedResource->SpatialAccumulation(FRHICommandListExecutor::GetImmediateCommandList(), RayTracedResource->DenoiseSRV[0], RayTracedResource->DenoiseUAV[1], View, SamplesPerPixel);
		RayTracedResource->RenderAmbientOcclusion(FRHICommandListExecutor::GetImmediateCommandList(), bDenoise);
	}
	else
	{
		RayTracedResource->RenderAmbientOcclusion(FRHICommandListExecutor::GetImmediateCommandList(), false);
	}
}
