// Fill out your copyright notice in the Description page of Project Settings.


#include "RaytracedBevel.h"
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
#include "RayTracingDefinitions.h" 
#include "UnrealClient.h"
#include "Engine/GameViewportClient.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LocalPlayer.h"
#include "Runtime/Renderer/Private/SceneRendering.h"
#include "Runtime/Renderer/Private/ScenePrivate.h"
#if ENGINE_MINOR_VERSION > 1
#include "Materials/MaterialRenderProxy.h"
#else
#include "MaterialShared.h"
#endif
#include "GeometryCacheVertexFactory.h"


TGlobalResource<FRaytracedBevelStaticVertexDeclaration> GRaytracedBevelStaticVertexDeclaration;
TGlobalResource<FRaytracedBevelABCVertexDeclaration> GRaytracedBevelABCVertexDeclaration;

IMPLEMENT_SHADER_TYPE(, FRaytracedBevelSceneVS, TEXT("/Plugin/RTAssets/ScreenSpace.usf"), TEXT("DrawPrimitiveVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FRaytracedDynamicBevelSceneVS, TEXT("/Plugin/RTAssets/ScreenSpace.usf"), TEXT("DrawDynamicPrimitiveVS"), SF_Vertex);
IMPLEMENT_SHADER_TYPE(, FRaytracedBevelScenePS, TEXT("/Plugin/RTAssets/ScreenSpace.usf"), TEXT("DrawPrimitivePS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FRenderBevelNormalPS, TEXT("/Plugin/RTAssets/ScreenSpace.usf"), TEXT("RenderBevelNormalPS"), SF_Pixel);

IMPLEMENT_SHADER_TYPE(, FBevelSpatialAccumulationCS, TEXT("/Plugin/RTAssets/RaytracedBevel.usf"), TEXT("SpatialAccumulationCS"), SF_Compute);

IMPLEMENT_SHADER_TYPE(, FBevelNormalRGS, TEXT("/Plugin/RTAssets/RaytracedBevel.usf"), TEXT("BevelNormalRGS"), SF_RayGen);
IMPLEMENT_SHADER_TYPE(, FBevelNormalRGS_PackedNormal, TEXT("/Plugin/RTAssets/RaytracedBevel.usf"), TEXT("BevelNormalRGS"), SF_RayGen);
IMPLEMENT_SHADER_TYPE(, FBevelNormalCHS, TEXT("/Plugin/RTAssets/RaytracedBevel.usf"), TEXT("closesthit=BevelNormalCHS"), SF_RayHitGroup);
IMPLEMENT_SHADER_TYPE(, FBevelNormalMS, TEXT("/Plugin/RTAssets/RaytracedBevel.usf"), TEXT("BevelNormalMS"), SF_RayMiss);

 
#if ENGINE_MINOR_VERSION > 2
void FBevelResource::InitRHI(FRHICommandListBase& RHICmdList)
#else
void FBevelResource::InitRHI()
#endif
{
	bIgnoreGammaConversions = true;	

	FIntPoint FinalSize = FIntPoint(FMath::Max(GetSizeX(), (uint32)1), FMath::Max(GetSizeY(), (uint32)1));
	SizeXY = FinalSize;

#if ENGINE_MINOR_VERSION > 2
	CreateTextures(RHICmdList);
#else
	CreateTextures();
#endif
}

FBevelResource::FBevelResource(class URaytracedBevelNormal* InOwner)
:FRayTraceTextureResource(InOwner)
{
	Owner = InOwner;
	SizeXY = FIntPoint(InOwner->SizeX, InOwner->SizeY);
	LocalToWorld = FTransform::Identity.ToMatrixWithScale();
};

void FBevelResource::PrepareSceneValuesStatic(FRHICommandListImmediate& RHICmdList, TWeakObjectPtr<UStaticMesh> StaticMesh, int32 LODIndex, FTransform WorldTransform, const FMatrix44f& VPMatrix, FTexture2DRHIRef Output)
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
		PassInfo.ColorRenderTargets[0].RenderTarget = Output;
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
		TShaderMapRef<FRaytracedBevelSceneVS> VertexShader(GlobalShaderMap);
		TShaderMapRef<FRaytracedBevelScenePS> PixelShader(GlobalShaderMap);

		FGraphicsPipelineStateInitializer PSOIniter;
		RHICmdList.ApplyCachedRenderTargets(PSOIniter);
		PSOIniter.DepthStencilState = TStaticDepthStencilState<true, CF_DepthNearOrEqual>::GetRHI();
		PSOIniter.BlendState = TStaticBlendState<CW_RGBA, BO_Add, BF_One, BF_Zero, BO_Add, BF_One, BF_Zero>::GetRHI();
		PSOIniter.RasterizerState = TStaticRasterizerState<FM_Solid, CM_CW>::GetRHI();
		PSOIniter.PrimitiveType = PT_TriangleList;

		PSOIniter.BoundShaderState.VertexDeclarationRHI = GRaytracedBevelStaticVertexDeclaration.VertexDeclarationRHI;
		PSOIniter.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
		PSOIniter.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
		SetGraphicsPipelineState(RHICmdList, PSOIniter, 0);

		{
			FRaytracedBevelSceneVS::FParameters Parameters;
			Parameters.LocalToWorld = FMatrix44f(WorldTransform.ToMatrixWithScale());
			Parameters.LocalToWorldInverseTranspose = (Parameters.LocalToWorld.Inverse()).GetTransposed();
			Parameters.VPMatrix = FMatrix44f(VPMatrix);
			SetShaderParameters(RHICmdList, VertexShader, VertexShader.GetVertexShader(), Parameters);
		}

		RHICmdList.SetStreamSource(0, _VertexBuffer, 0);
		RHICmdList.SetStreamSource(1, _NormalBuffer, 0);
		RHICmdList.DrawIndexedPrimitive(_IndexBuffer, 0, 0, NumVertices, 0, NumPrimitives, 1);

		RHICmdList.EndRenderPass();
		RHICmdList.Transition(FRHITransitionInfo(Output, ERHIAccess::Unknown, ERHIAccess::SRVMask));
		RHICmdList.Transition(FRHITransitionInfo(DepthStencil, ERHIAccess::Unknown, ERHIAccess::SRVMask));
	}
};

void FBevelResource::PrepareSceneValuesABC(FRHICommandListImmediate& RHICmdList, FBufferRHIRef _VertexBuffer, FShaderResourceViewRHIRef _TangentBuffer, FShaderResourceViewRHIRef _NormalBuffer, FBufferRHIRef _IndexBuffer, uint32 NumVertices, uint32 NumPrimitives, ERenderTargetActions RenderTargetActions, EDepthStencilTargetActions DepthStencilTargetActions, const FMatrix44f& LocalToRelativeWorld, const FMatrix44f& VPMatrix, ERHIFeatureLevel::Type InFeatureLevel, FTexture2DRHIRef Output)
{
	FRHIRenderPassInfo PassInfo;
	PassInfo.ColorRenderTargets[0].RenderTarget = Output;
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
	TShaderMapRef<FRaytracedDynamicBevelSceneVS> VertexShader(GlobalShaderMap);
	TShaderMapRef<FRaytracedBevelScenePS> PixelShader(GlobalShaderMap);

	FGraphicsPipelineStateInitializer PSOIniter;
	RHICmdList.ApplyCachedRenderTargets(PSOIniter);
	PSOIniter.DepthStencilState = TStaticDepthStencilState<true, CF_DepthNearOrEqual>::GetRHI();
	PSOIniter.BlendState = TStaticBlendState<CW_RGBA, BO_Add, BF_One, BF_Zero, BO_Add, BF_One, BF_Zero>::GetRHI();
	PSOIniter.RasterizerState = TStaticRasterizerState<FM_Solid, CM_CW>::GetRHI();
	PSOIniter.PrimitiveType = PT_TriangleList;

	PSOIniter.BoundShaderState.VertexDeclarationRHI = GRaytracedBevelABCVertexDeclaration.VertexDeclarationRHI;
	PSOIniter.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
	PSOIniter.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();
	SetGraphicsPipelineState(RHICmdList, PSOIniter, 0);

	{
		FRaytracedDynamicBevelSceneVS::FParameters Parameters;
		Parameters.LocalToWorld = LocalToRelativeWorld.GetMatrixWithoutScale();
		Parameters.LocalToWorldInverseTranspose = (Parameters.LocalToWorld.Inverse()).GetTransposed();
		Parameters.VPMatrix = FMatrix44f(VPMatrix);
		Parameters.TangentBuffer = _TangentBuffer;
		Parameters.NormalBuffer = _NormalBuffer;
		SetShaderParameters(RHICmdList, VertexShader, VertexShader.GetVertexShader(), Parameters);
	}

	RHICmdList.SetStreamSource(0, _VertexBuffer, 0);
	RHICmdList.DrawIndexedPrimitive(_IndexBuffer, 0, 0, NumVertices, 0, NumPrimitives, 1);

	RHICmdList.EndRenderPass();
	RHICmdList.Transition(FRHITransitionInfo(Output, ERHIAccess::Unknown, ERHIAccess::SRVMask));
	RHICmdList.Transition(FRHITransitionInfo(DepthStencil, ERHIAccess::Unknown, ERHIAccess::SRVMask));
}

void FBevelResource::RayTraced(FRHICommandListImmediate& RHICmdList, ERHIFeatureLevel::Type InFeatureLevel,
FBufferRHIRef _VertexBuffer, FBufferRHIRef _IndexBuffer, FShaderResourceViewRHIRef Tangents, uint32 NumVertices, uint32 NumPrimitives, const FMatrix44f& LocalToRelativeWorld, const FRayTracedMatrices& Matrices,
float MaxAngle, float Roundness, float Radius, int32 NumSamples, bool bPackedTangents, bool bClearUAV)
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
		PipelineInitializer.MaxPayloadSizeInBytes = 24;

		FRayTracingShaderBindingsWriter GlobalResources;
		FRHIRayTracingShader* AmbientOcclusionRGS = nullptr;
		if (bPackedTangents)
		{
			FBevelNormalRGS_PackedNormal::FParameters BevelParameters;
			BevelParameters.Frame = GFrameCounter;
			BevelParameters.Resolution = this->TextureRHI->GetSizeXY();
			BevelParameters.MaxAngle = FMath::Cos(MaxAngle * (PI / 180.0));
			BevelParameters.Roundness = Roundness;
			BevelParameters.Radius = Radius;
			BevelParameters.NumSamples = NumSamples;
			BevelParameters.TLAS = RayTracingSceneView;
			BevelParameters.RWBevelNormal = BevelUAV[0];
			BevelParameters.DepthStencilSRV = SceneDepthSRV;
			BevelParameters.SceneNormalSRV = SceneNormalSRV;
			BevelParameters.SVPositionToTranslatedWorld = FMatrix44f(Matrices.SVPositionToTranslatedWorld);
			BevelParameters.InvDeviceZToWorldZTransform = FVector4f(Matrices.InvDeviceZToWorldZTransform);
			BevelParameters.TangentsBuffer = Tangents;
			BevelParameters.LocalToWorldInverseTranspose = FMatrix44f((LocalToWorld.Inverse()).GetTransposed());

			auto AmbientOcclusionRGSRef = ShaderMap->GetShader<FBevelNormalRGS_PackedNormal>();
			AmbientOcclusionRGS = AmbientOcclusionRGSRef.GetRayTracingShader();
			FRHIRayTracingShader* RayGenShaderTable[] = { AmbientOcclusionRGS };
			PipelineInitializer.SetRayGenShaderTable(RayGenShaderTable);
			SetShaderParameters(GlobalResources, AmbientOcclusionRGSRef, BevelParameters);
		}
		else
		{
			FBevelNormalRGS::FParameters BevelParameters;
			BevelParameters.Frame = GFrameCounter;
			BevelParameters.Resolution = this->TextureRHI->GetSizeXY();
			BevelParameters.MaxAngle = FMath::Cos(MaxAngle * (PI / 180.0));
			BevelParameters.Roundness = Roundness;
			BevelParameters.Radius = Radius;
			BevelParameters.NumSamples = NumSamples;
			BevelParameters.TLAS = RayTracingSceneView;
			BevelParameters.RWBevelNormal = BevelUAV[0];
			BevelParameters.DepthStencilSRV = SceneDepthSRV;
			BevelParameters.SceneNormalSRV = SceneNormalSRV;
			BevelParameters.SVPositionToTranslatedWorld = FMatrix44f(Matrices.SVPositionToTranslatedWorld);
			BevelParameters.InvDeviceZToWorldZTransform = FVector4f(Matrices.InvDeviceZToWorldZTransform);
			BevelParameters.TangentsBuffer = Tangents;
			BevelParameters.LocalToWorldInverseTranspose = FMatrix44f((LocalToWorld.Inverse()).GetTransposed());

			auto AmbientOcclusionRGSRef = ShaderMap->GetShader<FBevelNormalRGS>();
			AmbientOcclusionRGS = AmbientOcclusionRGSRef.GetRayTracingShader();
			FRHIRayTracingShader* RayGenShaderTable[] = { AmbientOcclusionRGS };
			PipelineInitializer.SetRayGenShaderTable(RayGenShaderTable);
			SetShaderParameters(GlobalResources, AmbientOcclusionRGSRef, BevelParameters);
		}

		auto ClosestHitShader = ShaderMap->GetShader<FBevelNormalCHS>();
		FRHIRayTracingShader* HitShaderTable[] = { ClosestHitShader.GetRayTracingShader() };
		PipelineInitializer.SetHitGroupTable(HitShaderTable);
		PipelineInitializer.bAllowHitGroupIndexing = true;

		auto MissShader = ShaderMap->GetShader<FBevelNormalMS>();
		FRHIRayTracingShader* MissShaderTable[] = { MissShader.GetRayTracingShader() };
		PipelineInitializer.SetMissShaderTable(MissShaderTable);

		FRayTracingPipelineState* PipelineState = PipelineStateCache::GetAndOrCreateRayTracingPipelineState(RHICmdList, PipelineInitializer);

		RHICmdList.SetRayTracingHitGroup(RayTracingScene.Scene, 0, 0, 0, PipelineState, 0, 0, nullptr, 0, nullptr, 0);
		RHICmdList.SetRayTracingMissShader(RayTracingScene.Scene, 0, PipelineState, 0, 0, nullptr, 0);

		RHICmdList.Transition(FRHITransitionInfo(BevelResult[0], ERHIAccess::Unknown, ERHIAccess::UAVMask));
		if(bClearUAV)
			RHICmdList.ClearUAVFloat(BevelUAV[0], FVector4f::Zero());

		RHICmdList.RayTraceDispatch(PipelineState, AmbientOcclusionRGS, RayTracingScene.Scene, GlobalResources, SizeXY.X, SizeXY.Y);
	}
}

void FBevelResource::SpatialAccumulation(FRHICommandListImmediate& RHICmdList, const struct FRayTracedMatrices& View, const float Radius)
{
	RHICmdList.Transition(FRHITransitionInfo(BevelResult[0], ERHIAccess::Unknown, ERHIAccess::SRVMask));
	RHICmdList.Transition(FRHITransitionInfo(BevelResult[1], ERHIAccess::Unknown, ERHIAccess::UAVMask));
	RHICmdList.ClearUAVFloat(BevelUAV[1], FVector4f::Zero());

	FBevelSpatialAccumulationCS::FParameters Parameters;
	Parameters.Resolution = View.ViewSize;
	Parameters.Radius = Radius;
	Parameters.SceneNormalSRV = SceneNormalSRV;
	Parameters.DepthStencilSRV = SceneDepthSRV;
	Parameters.SignalInput = BevelResult[0];
	Parameters.InputSampler = TStaticSamplerState< SF_Point, AM_Clamp, AM_Clamp, AM_Clamp >::GetRHI();
	Parameters.SignalOutput = BevelUAV[1];
	Parameters.SVPositionToTranslatedWorld = FMatrix44f(View.SVPositionToTranslatedWorld);
	Parameters.InvDeviceZToWorldZTransform = FVector4f(View.InvDeviceZToWorldZTransform);
	Parameters.WorldDepthToPixelWorldRadius = (2.0*(1.0/ View.InvProjectionMatrix.M[0][0]) / float(View.ViewSize.X));

	FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	TShaderMapRef<FBevelSpatialAccumulationCS> ComputerShader(GlobalShaderMap);
	SetComputePipelineState(RHICmdList, ComputerShader.GetComputeShader());
	SetShaderParameters(RHICmdList, ComputerShader, ComputerShader.GetComputeShader(), Parameters);

	int32 GroupSizeX = FMath::CeilToInt(View.ViewSize.X / 8.f);
	int32 GroupSizeY = FMath::CeilToInt(View.ViewSize.Y / 8.f);
	DispatchComputeShader(RHICmdList, ComputerShader, GroupSizeX, GroupSizeY, 1);
	UnsetShaderUAVs(RHICmdList, ComputerShader, ComputerShader.GetComputeShader());
}

void FBevelResource::RenderBevel(FRHICommandListImmediate& RHICmdList, bool bDenoise)
{
	RHICmdList.Transition(FRHITransitionInfo(BevelResult[0], ERHIAccess::Unknown, ERHIAccess::SRVMask));
	RHICmdList.Transition(FRHITransitionInfo(BevelResult[1], ERHIAccess::Unknown, ERHIAccess::SRVMask));

	FRHIRenderPassInfo PassInfo;
	PassInfo.ColorRenderTargets[0].RenderTarget = TextureRHI;
	PassInfo.ColorRenderTargets[0].ResolveTarget = nullptr;
	PassInfo.ColorRenderTargets[0].ArraySlice = -1;
	PassInfo.ColorRenderTargets[0].MipIndex = 0;
	PassInfo.ColorRenderTargets[0].Action = ERenderTargetActions::Clear_Store;
	TransitionRenderPassTargets(RHICmdList, PassInfo);
	RHICmdList.BeginRenderPass(PassInfo, TEXT("RenderBevel"));
	RHICmdList.SetViewport(0, 0, 0, TextureRHI->GetSizeX(), TextureRHI->GetSizeY(), 1.f);

	FGlobalShaderMap* GlobalShaderMap = GetGlobalShaderMap(GMaxRHIFeatureLevel);
	TShaderMapRef<FScreenVS> VertexShader(GlobalShaderMap);
	TShaderMapRef<FRenderBevelNormalPS> PixelShader(GlobalShaderMap);

	FGraphicsPipelineStateInitializer PSOIniter;
	PSOIniter.DepthStencilState = TStaticDepthStencilState<false, CF_Always>::GetRHI();
	PSOIniter.BlendState = TStaticBlendState<CW_RGBA, BO_Add, BF_One, BF_Zero, BO_Add, BF_One, BF_Zero>::GetRHI();
	PSOIniter.RasterizerState = TStaticRasterizerState<FM_Solid, CM_None>::GetRHI();
	PSOIniter.PrimitiveType = PT_TriangleList;

	PSOIniter.BoundShaderState.VertexDeclarationRHI = GFilterVertexDeclaration.VertexDeclarationRHI;
	PSOIniter.BoundShaderState.VertexShaderRHI = VertexShader.GetVertexShader();
	PSOIniter.BoundShaderState.PixelShaderRHI = PixelShader.GetPixelShader();

	RHICmdList.ApplyCachedRenderTargets(PSOIniter);
	SetGraphicsPipelineState(RHICmdList, PSOIniter, 0);

	{
		FRenderBevelNormalPS::FParameters Parameters;
		Parameters.Resolution = TextureRHI->GetSizeXY();
		Parameters.ModelBevel = bDenoise ? BevelResult[1] : BevelResult[0];
		Parameters.ModelBevelSampler = TStaticSamplerState< SF_Point, AM_Clamp, AM_Clamp, AM_Clamp >::GetRHI();
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

void FBevelResource::ReleaseTextures()
{
	FRayTraceTextureResource::ReleaseTextures();
	BevelResult[0].SafeRelease();
	BevelResult[1].SafeRelease();
}

#if ENGINE_MINOR_VERSION > 2
void FBevelResource::CreateTextures(FRHICommandListBase& RHICmdList)
#else
void FBevelResource::CreateTextures()
#endif
{
	if (!Owner.IsValid())
		return;
		 
#if ENGINE_MINOR_VERSION > 2
	FRayTraceTextureResource::CreateTextures(RHICmdList);
#else
	FRayTraceTextureResource::CreateTextures();
#endif

	FSamplerStateInitializerRHI SamplerStateInitializer
	(
		Owner->Filter==TextureFilter::TF_Nearest ? ESamplerFilter::SF_Point : ESamplerFilter::SF_Bilinear,
		ESamplerAddressMode::AM_Clamp,
		ESamplerAddressMode::AM_Clamp,
		ESamplerAddressMode::AM_Clamp
	);
	SamplerStateRHI = GetOrCreateSamplerState(SamplerStateInitializer);

	this->bSRGB = true;

	{
		const static FLazyName ClassName(TEXT("FBevelResource"));

		FString ResourceName = Owner->GetName();
		FRHITextureCreateDesc OwnerDesc =
		FRHITextureCreateDesc::Create2D(*ResourceName)
		.SetExtent(SizeXY.X, SizeXY.Y)
		.SetFormat(EPixelFormat::PF_FloatRGBA)
		.SetNumMips(1)
		.SetFlags(ETextureCreateFlags::RenderTargetable | ETextureCreateFlags::ShaderResource)
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
		FRHITextureCreateDesc::Create2D(TEXT("BevelResult"), SizeXY, EPixelFormat::PF_FloatRGBA)
		.SetFlags(ETextureCreateFlags::ShaderResource | ETextureCreateFlags::UAV)
		.SetClearValue(FClearValueBinding(FLinearColor(0, 0, 0, 0)))
		.SetInitialState(ERHIAccess::SRVMask);

		this->BevelResult[0] = RHICreateTexture(Desc);
#if ENGINE_MINOR_VERSION > 2
		this->BevelSRV[0] = RHICmdList.CreateShaderResourceView(this->BevelResult[0], 0);
		this->BevelUAV[0] = RHICmdList.CreateUnorderedAccessView(this->BevelResult[0], 0);
#else
		this->BevelSRV[0] = RHICreateShaderResourceView(this->BevelResult[0], 0);
		this->BevelUAV[0] = RHICreateUnorderedAccessView(this->BevelResult[0], 0);
#endif

		this->BevelResult[1] = RHICreateTexture(Desc);
#if ENGINE_MINOR_VERSION > 2
		this->BevelSRV[1] = RHICmdList.CreateShaderResourceView(this->BevelResult[1], 0);
		this->BevelUAV[1] = RHICmdList.CreateUnorderedAccessView(this->BevelResult[1], 0);
#else
		this->BevelSRV[1] = RHICreateShaderResourceView(this->BevelResult[1], 0);
		this->BevelUAV[1] = RHICreateUnorderedAccessView(this->BevelResult[1], 0);
#endif
	}
}

bool FBevelResource::IsRaytraceValid()
{
	return Owner.IsValid() && SizeXY.X > 0 && SizeXY.Y > 0 && DepthStencil.IsValid() && SceneNormal.IsValid() && BevelResult[0].IsValid() && BevelResult[1].IsValid();
}

URaytracedBevelNormal::URaytracedBevelNormal(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	this->Filter = BevelFilter;
	this->bProjectionMatrixUnadjusted = false;
}

FTextureResource* URaytracedBevelNormal::CreateResource()
{
	return new FBevelResource(this);
}


void URaytracedBevelNormal::PostLoad()
{
	Filter = BevelFilter;
	Super::PostLoad();
}

#if WITH_EDITOR
void URaytracedBevelNormal::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(URaytracedBevelNormal, BevelFilter))
	{
		OnBevelFilterChanged();
	}
}
#endif

#if WITH_EDITOR
void URaytracedBevelNormal::OnBevelFilterChanged()
{
	this->Filter = BevelFilter;
	UpdateResource();
	NotifyMaterials();
}
#endif

void URaytracedBevelNormal::RenderStaticMesh(const FRayTracedMatrices& View, UStaticMesh* StaticMesh, const FMatrix& LocalToWorld, ERHIFeatureLevel::Type InFeatureLevel, uint32 LODIndex)
{
	FTransform WorldTransform = FTransform(LocalToWorld);
	SizeX = View.ViewSize.X;
	SizeY = View.ViewSize.Y;
	if (!GetResource())
	{
		return;
	}

	FBevelResource* BevelResource = (FBevelResource*)GetResource();
	if (!BevelResource->IsRaytraceValid())
		return;

	BevelResource->SetViewSize(FRHICommandListExecutor::GetImmediateCommandList(), View.ViewSize);

	if (!StaticMesh || StaticMesh->HasPendingInitOrStreaming() || !StaticMesh->HasValidRenderData() || !StaticMesh->GetRenderData())
		return;

	FVector WorldScale = WorldTransform.GetScale3D();
	FVector LocalSize = StaticMesh->GetBounds().BoxExtent;
	bool bValidSize = ((WorldScale.X!=0.0) && (WorldScale.Y!=0.0) && (WorldScale.Z!=0.0)) && ((LocalSize.X>0.01f) && (LocalSize.Y>0.01f) && (LocalSize.Z>0.01f));

	bool bHasBevel = (Radius > 0.0) && bValidSize;
	FTexture2DRHIRef NormalOutput = bHasBevel ? BevelResource->SceneNormal : BevelResource->TextureRHI;

	BevelResource->PrepareSceneValuesStatic(FRHICommandListExecutor::GetImmediateCommandList(),
	StaticMesh,
	LODIndex,
	WorldTransform,
	FMatrix44f(View.ViewProjectionMatrix),
	NormalOutput);

	if (!bHasBevel)
	{
		return;
	}

	if (!StaticMesh->GetRenderData()->LODResources.IsValidIndex(LODIndex))
		LODIndex = 0;

	FBufferRHIRef _VertexBuffer = StaticMesh->GetRenderData()->LODResources[LODIndex].VertexBuffers.PositionVertexBuffer.VertexBufferRHI;
	FBufferRHIRef _IndexBuffer = StaticMesh->GetRenderData()->LODResources[LODIndex].IndexBuffer.IndexBufferRHI;
	FShaderResourceViewRHIRef Tangents = FRHICommandListExecutor::GetImmediateCommandList().CreateShaderResourceView(FShaderResourceViewInitializer(StaticMesh->GetRenderData()->LODResources[LODIndex].VertexBuffers.StaticMeshVertexBuffer.TangentsVertexBuffer.VertexBufferRHI, EPixelFormat::PF_R8G8B8A8_SNORM, 0, StaticMesh->GetRenderData()->LODResources[LODIndex].VertexBuffers.StaticMeshVertexBuffer.TangentsVertexBuffer.VertexBufferRHI->GetSize() / 4));
	uint32 NumVertices = StaticMesh->GetRenderData()->LODResources[LODIndex].GetNumVertices();
	uint32 NumPrimitives = StaticMesh->GetRenderData()->LODResources[LODIndex].GetNumTriangles();

	BevelResource->RayTraced
	(
		FRHICommandListExecutor::GetImmediateCommandList(),
		InFeatureLevel,
		_VertexBuffer,
		_IndexBuffer,
		Tangents,
		NumVertices,
		NumPrimitives,
		FMatrix44f(LocalToWorld),
		View,
		MaxAngle,
		Roundness,
		Radius,
		NumSamples,
		true,
		true
	);

	if (bDenoise)
	{
		BevelResource->SpatialAccumulation(FRHICommandListExecutor::GetImmediateCommandList(), View, Radius);
	}

	BevelResource->RenderBevel(FRHICommandListExecutor::GetImmediateCommandList(), bDenoise);
}

void URaytracedBevelNormal::RenderABCPrimitive(const FRayTracedMatrices& View, const FMeshBatch* MeshBatch, const FMatrix& LocalToWorld, const FBox& LocalBounds, ERHIFeatureLevel::Type InFeatureLevel)
{
	SizeX = View.ViewSize.X;
	SizeY = View.ViewSize.Y;
	if (!GetResource())
	{
		return;
	}

	FBevelResource* BevelResource = (FBevelResource*)GetResource();
	if (!BevelResource->IsRaytraceValid())
		return;

	BevelResource->SetViewSize(FRHICommandListExecutor::GetImmediateCommandList(), View.ViewSize);

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
		FTransform WorldTransform = FTransform(FMatrix(Primitive.LocalToRelativeWorld));
#else
		FTransform WorldTransform = FTransform(LocalToWorld);
#endif
		
		FRotator Rotator = WorldTransform.Rotator();
		FVector WorldScale = WorldTransform.GetScale3D();
#if ENGINE_MINOR_VERSION < 4
		FVector LocalSize = FVector(Primitive.LocalObjectBoundsMax - Primitive.LocalObjectBoundsMin);
#else
		FVector LocalSize = LocalBounds.GetSize();
#endif
		bool bValidSize = ((WorldScale.X != 0.0) && (WorldScale.Y != 0.0) && (WorldScale.Z != 0.0)) && ((LocalSize.X > 0.01f) && (LocalSize.Y > 0.01f) && (LocalSize.Z > 0.01f));

		bRaytraced = bRaytraced && ((Radius > 0.0) && bValidSize);
		FTexture2DRHIRef NormalOutput = bRaytraced ? BevelResource->SceneNormal : BevelResource->TextureRHI;

		BevelResource->PrepareSceneValuesABC(FRHICommandListExecutor::GetImmediateCommandList(),
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
		InFeatureLevel,
		NormalOutput);

		RenderTargetActions = ERenderTargetActions::Load_Store;
		DepthStencilTargetActions = EDepthStencilTargetActions::LoadDepthNotStencil_StoreDepthNotStencil;

		if (!bRaytraced)
		{
			continue;
		}

		BevelResource->RayTraced
		(
			FRHICommandListExecutor::GetImmediateCommandList(),
			InFeatureLevel,
			Data->PositionBuffer->VertexBufferRHI,
			_IndexBuffer,
			Data->TangentZSRV,
			NumVertices,
			NumPrimitives,
#if ENGINE_MINOR_VERSION < 4
			Primitive.LocalToRelativeWorld,
#else
			FMatrix44f(LocalToWorld),
#endif
			View,
			MaxAngle,
			Roundness,
			Radius,
			NumSamples,
			false,
			bClearUAV
		);

		bClearUAV = false;
	}

	if(bRaytraced)
	{
		if (bDenoise)
		{
			BevelResource->SpatialAccumulation(FRHICommandListExecutor::GetImmediateCommandList(), View, Radius);
		}

		BevelResource->RenderBevel(FRHICommandListExecutor::GetImmediateCommandList(), bDenoise);
	}
}
