// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ExtContentBrowser/Private/DependencyViewer/ExtDependencyViewerSchema.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExtDependencyViewerSchema() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UEdGraphSchema();
	EXTCONTENTBROWSER_API UClass* Z_Construct_UClass_UExtDependencyViewerSchema();
	EXTCONTENTBROWSER_API UClass* Z_Construct_UClass_UExtDependencyViewerSchema_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ExtContentBrowser();
// End Cross Module References
	void UExtDependencyViewerSchema::StaticRegisterNativesUExtDependencyViewerSchema()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UExtDependencyViewerSchema);
	UClass* Z_Construct_UClass_UExtDependencyViewerSchema_NoRegister()
	{
		return UExtDependencyViewerSchema::StaticClass();
	}
	struct Z_Construct_UClass_UExtDependencyViewerSchema_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UExtDependencyViewerSchema_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEdGraphSchema,
		(UObject* (*)())Z_Construct_UPackage__Script_ExtContentBrowser,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UExtDependencyViewerSchema_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UExtDependencyViewerSchema_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "DependencyViewer/ExtDependencyViewerSchema.h" },
		{ "ModuleRelativePath", "Private/DependencyViewer/ExtDependencyViewerSchema.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UExtDependencyViewerSchema_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UExtDependencyViewerSchema>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UExtDependencyViewerSchema_Statics::ClassParams = {
		&UExtDependencyViewerSchema::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000800A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UExtDependencyViewerSchema_Statics::Class_MetaDataParams), Z_Construct_UClass_UExtDependencyViewerSchema_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UExtDependencyViewerSchema()
	{
		if (!Z_Registration_Info_UClass_UExtDependencyViewerSchema.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UExtDependencyViewerSchema.OuterSingleton, Z_Construct_UClass_UExtDependencyViewerSchema_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UExtDependencyViewerSchema.OuterSingleton;
	}
	template<> EXTCONTENTBROWSER_API UClass* StaticClass<UExtDependencyViewerSchema>()
	{
		return UExtDependencyViewerSchema::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UExtDependencyViewerSchema);
	UExtDependencyViewerSchema::~UExtDependencyViewerSchema() {}
	struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Private_DependencyViewer_ExtDependencyViewerSchema_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Private_DependencyViewer_ExtDependencyViewerSchema_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UExtDependencyViewerSchema, UExtDependencyViewerSchema::StaticClass, TEXT("UExtDependencyViewerSchema"), &Z_Registration_Info_UClass_UExtDependencyViewerSchema, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UExtDependencyViewerSchema), 697248969U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Private_DependencyViewer_ExtDependencyViewerSchema_h_4058622874(TEXT("/Script/ExtContentBrowser"),
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Private_DependencyViewer_ExtDependencyViewerSchema_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Private_DependencyViewer_ExtDependencyViewerSchema_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
