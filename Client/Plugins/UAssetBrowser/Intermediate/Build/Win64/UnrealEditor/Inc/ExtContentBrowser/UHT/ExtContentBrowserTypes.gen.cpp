// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ExtContentBrowser/Public/ExtContentBrowserTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExtContentBrowserTypes() {}
// Cross Module References
	EXTCONTENTBROWSER_API UScriptStruct* Z_Construct_UScriptStruct_FUAssetImportSetting();
	UPackage* Z_Construct_UPackage__Script_ExtContentBrowser();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_UAssetImportSetting;
class UScriptStruct* FUAssetImportSetting::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_UAssetImportSetting.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_UAssetImportSetting.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FUAssetImportSetting, (UObject*)Z_Construct_UPackage__Script_ExtContentBrowser(), TEXT("UAssetImportSetting"));
	}
	return Z_Registration_Info_UScriptStruct_UAssetImportSetting.OuterSingleton;
}
template<> EXTCONTENTBROWSER_API UScriptStruct* StaticStruct<FUAssetImportSetting>()
{
	return FUAssetImportSetting::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FUAssetImportSetting_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSkipImportIfAnyDependencyMissing_MetaData[];
#endif
		static void NewProp_bSkipImportIfAnyDependencyMissing_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSkipImportIfAnyDependencyMissing;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIgnoreSoftReferencesError_MetaData[];
#endif
		static void NewProp_bIgnoreSoftReferencesError_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIgnoreSoftReferencesError;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bOverwriteExistingFiles_MetaData[];
#endif
		static void NewProp_bOverwriteExistingFiles_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverwriteExistingFiles;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bRollbackIfFailed_MetaData[];
#endif
		static void NewProp_bRollbackIfFailed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bRollbackIfFailed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bImportFolderColor_MetaData[];
#endif
		static void NewProp_bImportFolderColor_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bImportFolderColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bOverrideExistingFolderColor_MetaData[];
#endif
		static void NewProp_bOverrideExistingFolderColor_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOverrideExistingFolderColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bImportToPluginFolder_MetaData[];
#endif
		static void NewProp_bImportToPluginFolder_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bImportToPluginFolder;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bWarnBeforeImportToPluginFolder_MetaData[];
#endif
		static void NewProp_bWarnBeforeImportToPluginFolder_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bWarnBeforeImportToPluginFolder;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImportToPluginName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_ImportToPluginName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSyncAssetsInContentBrowser_MetaData[];
#endif
		static void NewProp_bSyncAssetsInContentBrowser_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSyncAssetsInContentBrowser;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bSyncExistingAssets_MetaData[];
#endif
		static void NewProp_bSyncExistingAssets_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bSyncExistingAssets;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bLoadAssetAfterImport_MetaData[];
#endif
		static void NewProp_bLoadAssetAfterImport_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bLoadAssetAfterImport;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAddImportedAssetsToCollection_MetaData[];
#endif
		static void NewProp_bAddImportedAssetsToCollection_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAddImportedAssetsToCollection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUniqueCollectionNameForEachImportSession_MetaData[];
#endif
		static void NewProp_bUniqueCollectionNameForEachImportSession_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUniqueCollectionNameForEachImportSession;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImportedUAssetCollectionName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_ImportedUAssetCollectionName;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Asset Import Setting\n */" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserTypes.h" },
		{ "ToolTip", "Asset Import Setting" },
	};
#endif
	void* Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FUAssetImportSetting>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSkipImportIfAnyDependencyMissing_MetaData[] = {
		{ "Category", "Import" },
		{ "DisplayName", "Abort If Dependency Missing" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserTypes.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSkipImportIfAnyDependencyMissing_SetBit(void* Obj)
	{
		((FUAssetImportSetting*)Obj)->bSkipImportIfAnyDependencyMissing = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSkipImportIfAnyDependencyMissing = { "bSkipImportIfAnyDependencyMissing", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FUAssetImportSetting), &Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSkipImportIfAnyDependencyMissing_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSkipImportIfAnyDependencyMissing_MetaData), Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSkipImportIfAnyDependencyMissing_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bIgnoreSoftReferencesError_MetaData[] = {
		{ "Category", "Import" },
		{ "Comment", "//#if ECB_FEA_IMPORT_IGNORE_SOFT_ERROR\n" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserTypes.h" },
		{ "ToolTip", "#if ECB_FEA_IMPORT_IGNORE_SOFT_ERROR" },
	};
#endif
	void Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bIgnoreSoftReferencesError_SetBit(void* Obj)
	{
		((FUAssetImportSetting*)Obj)->bIgnoreSoftReferencesError = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bIgnoreSoftReferencesError = { "bIgnoreSoftReferencesError", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FUAssetImportSetting), &Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bIgnoreSoftReferencesError_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bIgnoreSoftReferencesError_MetaData), Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bIgnoreSoftReferencesError_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bOverwriteExistingFiles_MetaData[] = {
		{ "Category", "Import" },
		{ "Comment", "//#endif\n" },
		{ "DisplayName", "Overwrite Existing Assets" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserTypes.h" },
		{ "ToolTip", "#endif" },
	};
#endif
	void Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bOverwriteExistingFiles_SetBit(void* Obj)
	{
		((FUAssetImportSetting*)Obj)->bOverwriteExistingFiles = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bOverwriteExistingFiles = { "bOverwriteExistingFiles", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FUAssetImportSetting), &Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bOverwriteExistingFiles_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bOverwriteExistingFiles_MetaData), Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bOverwriteExistingFiles_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bRollbackIfFailed_MetaData[] = {
		{ "Category", "Import" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserTypes.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bRollbackIfFailed_SetBit(void* Obj)
	{
		((FUAssetImportSetting*)Obj)->bRollbackIfFailed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bRollbackIfFailed = { "bRollbackIfFailed", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FUAssetImportSetting), &Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bRollbackIfFailed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bRollbackIfFailed_MetaData), Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bRollbackIfFailed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bImportFolderColor_MetaData[] = {
		{ "Category", "Folder" },
		{ "Comment", "//#if ECB_WIP_IMPORT_FOLDER_COLOR\n" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserTypes.h" },
		{ "ToolTip", "#if ECB_WIP_IMPORT_FOLDER_COLOR" },
	};
#endif
	void Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bImportFolderColor_SetBit(void* Obj)
	{
		((FUAssetImportSetting*)Obj)->bImportFolderColor = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bImportFolderColor = { "bImportFolderColor", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FUAssetImportSetting), &Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bImportFolderColor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bImportFolderColor_MetaData), Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bImportFolderColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bOverrideExistingFolderColor_MetaData[] = {
		{ "Category", "Folder" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserTypes.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bOverrideExistingFolderColor_SetBit(void* Obj)
	{
		((FUAssetImportSetting*)Obj)->bOverrideExistingFolderColor = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bOverrideExistingFolderColor = { "bOverrideExistingFolderColor", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FUAssetImportSetting), &Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bOverrideExistingFolderColor_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bOverrideExistingFolderColor_MetaData), Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bOverrideExistingFolderColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bImportToPluginFolder_MetaData[] = {
		{ "Category", "Plugin" },
		{ "Comment", "//#if ECB_WIP_IMPORT_TO_PLUGIN_FOLDER\n" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserTypes.h" },
		{ "ToolTip", "#if ECB_WIP_IMPORT_TO_PLUGIN_FOLDER" },
	};
#endif
	void Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bImportToPluginFolder_SetBit(void* Obj)
	{
		((FUAssetImportSetting*)Obj)->bImportToPluginFolder = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bImportToPluginFolder = { "bImportToPluginFolder", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FUAssetImportSetting), &Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bImportToPluginFolder_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bImportToPluginFolder_MetaData), Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bImportToPluginFolder_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bWarnBeforeImportToPluginFolder_MetaData[] = {
		{ "Category", "Plugin" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserTypes.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bWarnBeforeImportToPluginFolder_SetBit(void* Obj)
	{
		((FUAssetImportSetting*)Obj)->bWarnBeforeImportToPluginFolder = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bWarnBeforeImportToPluginFolder = { "bWarnBeforeImportToPluginFolder", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FUAssetImportSetting), &Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bWarnBeforeImportToPluginFolder_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bWarnBeforeImportToPluginFolder_MetaData), Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bWarnBeforeImportToPluginFolder_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_ImportToPluginName_MetaData[] = {
		{ "Category", "Plugin" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserTypes.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_ImportToPluginName = { "ImportToPluginName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FUAssetImportSetting, ImportToPluginName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_ImportToPluginName_MetaData), Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_ImportToPluginName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSyncAssetsInContentBrowser_MetaData[] = {
		{ "Category", "PostImport" },
		{ "Comment", "//#endif\n" },
		{ "DisplayName", "Sync Imporrted Assets in Content Browser" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserTypes.h" },
		{ "ToolTip", "#endif" },
	};
#endif
	void Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSyncAssetsInContentBrowser_SetBit(void* Obj)
	{
		((FUAssetImportSetting*)Obj)->bSyncAssetsInContentBrowser = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSyncAssetsInContentBrowser = { "bSyncAssetsInContentBrowser", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FUAssetImportSetting), &Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSyncAssetsInContentBrowser_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSyncAssetsInContentBrowser_MetaData), Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSyncAssetsInContentBrowser_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSyncExistingAssets_MetaData[] = {
		{ "Category", "PostImport" },
		{ "DisplayName", "Sync Skipped Existing Assets" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserTypes.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSyncExistingAssets_SetBit(void* Obj)
	{
		((FUAssetImportSetting*)Obj)->bSyncExistingAssets = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSyncExistingAssets = { "bSyncExistingAssets", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FUAssetImportSetting), &Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSyncExistingAssets_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSyncExistingAssets_MetaData), Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSyncExistingAssets_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bLoadAssetAfterImport_MetaData[] = {
		{ "Category", "PostImport" },
		{ "DisplayName", "Load/Reload Assets After Import" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserTypes.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bLoadAssetAfterImport_SetBit(void* Obj)
	{
		((FUAssetImportSetting*)Obj)->bLoadAssetAfterImport = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bLoadAssetAfterImport = { "bLoadAssetAfterImport", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FUAssetImportSetting), &Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bLoadAssetAfterImport_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bLoadAssetAfterImport_MetaData), Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bLoadAssetAfterImport_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bAddImportedAssetsToCollection_MetaData[] = {
		{ "Category", "Collection" },
		{ "Comment", "//#if ECB_WIP_IMPORT_ADD_TO_COLLECTION\n" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserTypes.h" },
		{ "ToolTip", "#if ECB_WIP_IMPORT_ADD_TO_COLLECTION" },
	};
#endif
	void Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bAddImportedAssetsToCollection_SetBit(void* Obj)
	{
		((FUAssetImportSetting*)Obj)->bAddImportedAssetsToCollection = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bAddImportedAssetsToCollection = { "bAddImportedAssetsToCollection", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FUAssetImportSetting), &Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bAddImportedAssetsToCollection_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bAddImportedAssetsToCollection_MetaData), Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bAddImportedAssetsToCollection_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bUniqueCollectionNameForEachImportSession_MetaData[] = {
		{ "Category", "Collection" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserTypes.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bUniqueCollectionNameForEachImportSession_SetBit(void* Obj)
	{
		((FUAssetImportSetting*)Obj)->bUniqueCollectionNameForEachImportSession = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bUniqueCollectionNameForEachImportSession = { "bUniqueCollectionNameForEachImportSession", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FUAssetImportSetting), &Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bUniqueCollectionNameForEachImportSession_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bUniqueCollectionNameForEachImportSession_MetaData), Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bUniqueCollectionNameForEachImportSession_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_ImportedUAssetCollectionName_MetaData[] = {
		{ "Category", "Collection" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserTypes.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_ImportedUAssetCollectionName = { "ImportedUAssetCollectionName", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FUAssetImportSetting, ImportedUAssetCollectionName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_ImportedUAssetCollectionName_MetaData), Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_ImportedUAssetCollectionName_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSkipImportIfAnyDependencyMissing,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bIgnoreSoftReferencesError,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bOverwriteExistingFiles,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bRollbackIfFailed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bImportFolderColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bOverrideExistingFolderColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bImportToPluginFolder,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bWarnBeforeImportToPluginFolder,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_ImportToPluginName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSyncAssetsInContentBrowser,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bSyncExistingAssets,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bLoadAssetAfterImport,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bAddImportedAssetsToCollection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_bUniqueCollectionNameForEachImportSession,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewProp_ImportedUAssetCollectionName,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ExtContentBrowser,
		nullptr,
		&NewStructOps,
		"UAssetImportSetting",
		Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::PropPointers),
		sizeof(FUAssetImportSetting),
		alignof(FUAssetImportSetting),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FUAssetImportSetting()
	{
		if (!Z_Registration_Info_UScriptStruct_UAssetImportSetting.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_UAssetImportSetting.InnerSingleton, Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_UAssetImportSetting.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Public_ExtContentBrowserTypes_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Public_ExtContentBrowserTypes_h_Statics::ScriptStructInfo[] = {
		{ FUAssetImportSetting::StaticStruct, Z_Construct_UScriptStruct_FUAssetImportSetting_Statics::NewStructOps, TEXT("UAssetImportSetting"), &Z_Registration_Info_UScriptStruct_UAssetImportSetting, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FUAssetImportSetting), 2966382491U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Public_ExtContentBrowserTypes_h_3658549519(TEXT("/Script/ExtContentBrowser"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Public_ExtContentBrowserTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Public_ExtContentBrowserTypes_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
