// Copyright Epic Games, Inc. All Rights Reserved.

#include "RTEditor.h"
#include "Interfaces/IPluginManager.h"
#include "RaytracedAssetFactory.h"
#include "AssetToolsModule.h"
#include "RayTracedAO.h"
#include "RayTracedBevel.h"
#include "ThumbnailRendering/ThumbnailManager.h"
#include "ThumbnailRendering/TextureThumbnailRenderer.h"

#define LOCTEXT_NAMESPACE "FRTEditorModule"

void FRTEditorModule::StartupModule()
{
	{
		TSharedPtr<FAssetTypeActions_RaytracedAmbientOcclusion> AssetTypeAction = MakeShareable(new FAssetTypeActions_RaytracedAmbientOcclusion);
		FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get().RegisterAssetTypeActions(AssetTypeAction.ToSharedRef());
		UThumbnailManager::Get().RegisterCustomRenderer(URaytracedAmbientOcclusion::StaticClass(), UTextureThumbnailRenderer::StaticClass());
	}

	{
		TSharedPtr<FAssetTypeActions_RaytracedBevelNormal> AssetTypeAction = MakeShareable(new FAssetTypeActions_RaytracedBevelNormal);
		FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get().RegisterAssetTypeActions(AssetTypeAction.ToSharedRef());
		UThumbnailManager::Get().RegisterCustomRenderer(URaytracedBevelNormal::StaticClass(), UTextureThumbnailRenderer::StaticClass());
	}
}

void FRTEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRTEditorModule, RTEditor)