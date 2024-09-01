// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ExtContentBrowser/Private/ExtAssetData.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExtAssetData() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FAssetData();
	EXTCONTENTBROWSER_API UScriptStruct* Z_Construct_UScriptStruct_FExtAssetData();
	UPackage* Z_Construct_UPackage__Script_ExtContentBrowser();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_ExtAssetData;
class UScriptStruct* FExtAssetData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_ExtAssetData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_ExtAssetData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FExtAssetData, (UObject*)Z_Construct_UPackage__Script_ExtContentBrowser(), TEXT("ExtAssetData"));
	}
	return Z_Registration_Info_UScriptStruct_ExtAssetData.OuterSingleton;
}
template<> EXTCONTENTBROWSER_API UScriptStruct* StaticStruct<FExtAssetData>()
{
	return FExtAssetData::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FExtAssetData_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PackageFilePath_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_PackageFilePath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PackageName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_PackageName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PackagePath_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_PackagePath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ObjectPath_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_ObjectPath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AssetName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_AssetName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AssetClass_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_AssetClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AssetData_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AssetData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExtAssetData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * A struct to hold external asset information\n */" },
		{ "ModuleRelativePath", "Private/ExtAssetData.h" },
		{ "ToolTip", "A struct to hold external asset information" },
	};
#endif
	void* Z_Construct_UScriptStruct_FExtAssetData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FExtAssetData>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_PackageFilePath_MetaData[] = {
		{ "Category", "AssetData" },
		{ "Comment", "/** Full file path to package disk file */" },
		{ "ModuleRelativePath", "Private/ExtAssetData.h" },
		{ "ToolTip", "Full file path to package disk file" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_PackageFilePath = { "PackageFilePath", nullptr, (EPropertyFlags)0x0010000000002014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FExtAssetData, PackageFilePath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_PackageFilePath_MetaData), Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_PackageFilePath_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_PackageName_MetaData[] = {
		{ "Category", "AssetData" },
		{ "Comment", "/** The name of the package in which the asset is found, this is the full long package name such as /Game/Path/Package */" },
		{ "ModuleRelativePath", "Private/ExtAssetData.h" },
		{ "ToolTip", "The name of the package in which the asset is found, this is the full long package name such as /Game/Path/Package" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_PackageName = { "PackageName", nullptr, (EPropertyFlags)0x0010000000002014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FExtAssetData, PackageName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_PackageName_MetaData), Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_PackageName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_PackagePath_MetaData[] = {
		{ "Category", "AssetData" },
		{ "Comment", "/** The path to the package in which the asset is found, this is /Game/Path with the Package stripped off */" },
		{ "ModuleRelativePath", "Private/ExtAssetData.h" },
		{ "ToolTip", "The path to the package in which the asset is found, this is /Game/Path with the Package stripped off" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_PackagePath = { "PackagePath", nullptr, (EPropertyFlags)0x0010000000002014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FExtAssetData, PackagePath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_PackagePath_MetaData), Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_PackagePath_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_ObjectPath_MetaData[] = {
		{ "Category", "AssetData" },
		{ "Comment", "/** The object path for the asset in the form PackageName.AssetName. e.g. /Game/Path/Package.AssetName */" },
		{ "ModuleRelativePath", "Private/ExtAssetData.h" },
		{ "ToolTip", "The object path for the asset in the form PackageName.AssetName. e.g. /Game/Path/Package.AssetName" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_ObjectPath = { "ObjectPath", nullptr, (EPropertyFlags)0x0010000000002014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FExtAssetData, ObjectPath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_ObjectPath_MetaData), Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_ObjectPath_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_AssetName_MetaData[] = {
		{ "Category", "AssetData" },
		{ "Comment", "/** The name of the asset without the package */" },
		{ "ModuleRelativePath", "Private/ExtAssetData.h" },
		{ "ToolTip", "The name of the asset without the package" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_AssetName = { "AssetName", nullptr, (EPropertyFlags)0x0010000000002014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FExtAssetData, AssetName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_AssetName_MetaData), Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_AssetName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_AssetClass_MetaData[] = {
		{ "Category", "AssetData" },
		{ "Comment", "/** The name of the asset's class */" },
		{ "ModuleRelativePath", "Private/ExtAssetData.h" },
		{ "ToolTip", "The name of the asset's class" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_AssetClass = { "AssetClass", nullptr, (EPropertyFlags)0x0010000000002014, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FExtAssetData, AssetClass), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_AssetClass_MetaData), Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_AssetClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_AssetData_MetaData[] = {
		{ "Category", "AssetData" },
		{ "Comment", "/** Asset data to satisfy FAssetData based interface. */" },
		{ "ModuleRelativePath", "Private/ExtAssetData.h" },
		{ "ToolTip", "Asset data to satisfy FAssetData based interface." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_AssetData = { "AssetData", nullptr, (EPropertyFlags)0x0010000000002014, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FExtAssetData, AssetData), Z_Construct_UScriptStruct_FAssetData, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_AssetData_MetaData), Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_AssetData_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FExtAssetData_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_PackageFilePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_PackageName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_PackagePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_ObjectPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_AssetName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_AssetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FExtAssetData_Statics::NewProp_AssetData,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FExtAssetData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ExtContentBrowser,
		nullptr,
		&NewStructOps,
		"ExtAssetData",
		Z_Construct_UScriptStruct_FExtAssetData_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExtAssetData_Statics::PropPointers),
		sizeof(FExtAssetData),
		alignof(FExtAssetData),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExtAssetData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FExtAssetData_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FExtAssetData_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FExtAssetData()
	{
		if (!Z_Registration_Info_UScriptStruct_ExtAssetData.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_ExtAssetData.InnerSingleton, Z_Construct_UScriptStruct_FExtAssetData_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_ExtAssetData.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Private_ExtAssetData_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Private_ExtAssetData_h_Statics::ScriptStructInfo[] = {
		{ FExtAssetData::StaticStruct, Z_Construct_UScriptStruct_FExtAssetData_Statics::NewStructOps, TEXT("ExtAssetData"), &Z_Registration_Info_UScriptStruct_ExtAssetData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FExtAssetData), 2679289834U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Private_ExtAssetData_h_4174692564(TEXT("/Script/ExtContentBrowser"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Private_ExtAssetData_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_build_U5M_Marketplace_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Private_ExtAssetData_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
