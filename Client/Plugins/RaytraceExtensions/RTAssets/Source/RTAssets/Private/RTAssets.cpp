// Copyright Epic Games, Inc. All Rights Reserved.

#include "RTAssets.h"
#include "Interfaces/IPluginManager.h"
#include "EngineModule.h"
#include "RaytracedTexture.h"

#define LOCTEXT_NAMESPACE "FRTAssetsModule"

void FRTAssetsModule::StartupModule()
{
	FString PluginShaderDir = FPaths::Combine(IPluginManager::Get().FindPlugin(TEXT("RTAssets"))->GetBaseDir(), TEXT("Shaders"));
	AddShaderSourceDirectoryMapping(TEXT("/Plugin/RTAssets"), PluginShaderDir);

	FPostOpaqueRenderDelegate Render;
	Render.BindLambda([](FPostOpaqueRenderParameters& Parameters) {URaytracedTexture::PostOpaqueRender(Parameters); });
	RenderHandle = GetRendererModule().RegisterOverlayRenderDelegate(Render);
}

void FRTAssetsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRTAssetsModule, RTAssets)