// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ExtContentBrowser/Public/ExtContentBrowserBlueprintLibrary.h"
#include "ExtContentBrowser/Public/ExtContentBrowserTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExtContentBrowserBlueprintLibrary() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	EXTCONTENTBROWSER_API UClass* Z_Construct_UClass_UExtContentBrowserBlueprintLibrary();
	EXTCONTENTBROWSER_API UClass* Z_Construct_UClass_UExtContentBrowserBlueprintLibrary_NoRegister();
	EXTCONTENTBROWSER_API UScriptStruct* Z_Construct_UScriptStruct_FUAssetImportSetting();
	UPackage* Z_Construct_UPackage__Script_ExtContentBrowser();
// End Cross Module References
	DEFINE_FUNCTION(UExtContentBrowserBlueprintLibrary::execGetSelectedUAssetFilePaths)
	{
		P_GET_TARRAY_REF(FString,Z_Param_Out_AssetFilePaths);
		P_FINISH;
		P_NATIVE_BEGIN;
		UExtContentBrowserBlueprintLibrary::GetSelectedUAssetFilePaths(Z_Param_Out_AssetFilePaths);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UExtContentBrowserBlueprintLibrary::execGetGlobalImportSetting)
	{
		P_GET_STRUCT_REF(FUAssetImportSetting,Z_Param_Out_ImportSetting);
		P_FINISH;
		P_NATIVE_BEGIN;
		UExtContentBrowserBlueprintLibrary::GetGlobalImportSetting(Z_Param_Out_ImportSetting);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UExtContentBrowserBlueprintLibrary::execImportFromFileList)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_FilePath);
		P_GET_STRUCT_REF(FUAssetImportSetting,Z_Param_Out_ImportSetting);
		P_GET_UBOOL(Z_Param_bOneByOne);
		P_FINISH;
		P_NATIVE_BEGIN;
		UExtContentBrowserBlueprintLibrary::ImportFromFileList(Z_Param_FilePath,Z_Param_Out_ImportSetting,Z_Param_bOneByOne);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UExtContentBrowserBlueprintLibrary::execImportUAsset)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_AssetFilePath);
		P_GET_STRUCT_REF(FUAssetImportSetting,Z_Param_Out_ImportSetting);
		P_FINISH;
		P_NATIVE_BEGIN;
		UExtContentBrowserBlueprintLibrary::ImportUAsset(Z_Param_AssetFilePath,Z_Param_Out_ImportSetting);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UExtContentBrowserBlueprintLibrary::execImportUAssets)
	{
		P_GET_TARRAY_REF(FString,Z_Param_Out_AssetFilePaths);
		P_GET_STRUCT_REF(FUAssetImportSetting,Z_Param_Out_ImportSetting);
		P_GET_UBOOL(Z_Param_bOneByOne);
		P_FINISH;
		P_NATIVE_BEGIN;
		UExtContentBrowserBlueprintLibrary::ImportUAssets(Z_Param_Out_AssetFilePaths,Z_Param_Out_ImportSetting,Z_Param_bOneByOne);
		P_NATIVE_END;
	}
	void UExtContentBrowserBlueprintLibrary::StaticRegisterNativesUExtContentBrowserBlueprintLibrary()
	{
		UClass* Class = UExtContentBrowserBlueprintLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetGlobalImportSetting", &UExtContentBrowserBlueprintLibrary::execGetGlobalImportSetting },
			{ "GetSelectedUAssetFilePaths", &UExtContentBrowserBlueprintLibrary::execGetSelectedUAssetFilePaths },
			{ "ImportFromFileList", &UExtContentBrowserBlueprintLibrary::execImportFromFileList },
			{ "ImportUAsset", &UExtContentBrowserBlueprintLibrary::execImportUAsset },
			{ "ImportUAssets", &UExtContentBrowserBlueprintLibrary::execImportUAssets },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetGlobalImportSetting_Statics
	{
		struct ExtContentBrowserBlueprintLibrary_eventGetGlobalImportSetting_Parms
		{
			FUAssetImportSetting ImportSetting;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ImportSetting;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetGlobalImportSetting_Statics::NewProp_ImportSetting = { "ImportSetting", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtContentBrowserBlueprintLibrary_eventGetGlobalImportSetting_Parms, ImportSetting), Z_Construct_UScriptStruct_FUAssetImportSetting, METADATA_PARAMS(0, nullptr) }; // 2966382491
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetGlobalImportSetting_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetGlobalImportSetting_Statics::NewProp_ImportSetting,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetGlobalImportSetting_Statics::Function_MetaDataParams[] = {
		{ "Category", "UAssetBrowser|Get" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserBlueprintLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetGlobalImportSetting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExtContentBrowserBlueprintLibrary, nullptr, "GetGlobalImportSetting", nullptr, nullptr, Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetGlobalImportSetting_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetGlobalImportSetting_Statics::PropPointers), sizeof(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetGlobalImportSetting_Statics::ExtContentBrowserBlueprintLibrary_eventGetGlobalImportSetting_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetGlobalImportSetting_Statics::Function_MetaDataParams), Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetGlobalImportSetting_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetGlobalImportSetting_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetGlobalImportSetting_Statics::ExtContentBrowserBlueprintLibrary_eventGetGlobalImportSetting_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetGlobalImportSetting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetGlobalImportSetting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths_Statics
	{
		struct ExtContentBrowserBlueprintLibrary_eventGetSelectedUAssetFilePaths_Parms
		{
			TArray<FString> AssetFilePaths;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_AssetFilePaths_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AssetFilePaths;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths_Statics::NewProp_AssetFilePaths_Inner = { "AssetFilePaths", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths_Statics::NewProp_AssetFilePaths = { "AssetFilePaths", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtContentBrowserBlueprintLibrary_eventGetSelectedUAssetFilePaths_Parms, AssetFilePaths), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths_Statics::NewProp_AssetFilePaths_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths_Statics::NewProp_AssetFilePaths,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths_Statics::Function_MetaDataParams[] = {
		{ "Category", "UAssetBrowser|Get" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserBlueprintLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExtContentBrowserBlueprintLibrary, nullptr, "GetSelectedUAssetFilePaths", nullptr, nullptr, Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths_Statics::PropPointers), sizeof(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths_Statics::ExtContentBrowserBlueprintLibrary_eventGetSelectedUAssetFilePaths_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths_Statics::Function_MetaDataParams), Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths_Statics::ExtContentBrowserBlueprintLibrary_eventGetSelectedUAssetFilePaths_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics
	{
		struct ExtContentBrowserBlueprintLibrary_eventImportFromFileList_Parms
		{
			FString FilePath;
			FUAssetImportSetting ImportSetting;
			bool bOneByOne;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FilePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_FilePath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImportSetting_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ImportSetting;
		static void NewProp_bOneByOne_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOneByOne;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::NewProp_FilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::NewProp_FilePath = { "FilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtContentBrowserBlueprintLibrary_eventImportFromFileList_Parms, FilePath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::NewProp_FilePath_MetaData), Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::NewProp_FilePath_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::NewProp_ImportSetting_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::NewProp_ImportSetting = { "ImportSetting", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtContentBrowserBlueprintLibrary_eventImportFromFileList_Parms, ImportSetting), Z_Construct_UScriptStruct_FUAssetImportSetting, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::NewProp_ImportSetting_MetaData), Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::NewProp_ImportSetting_MetaData) }; // 2966382491
	void Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::NewProp_bOneByOne_SetBit(void* Obj)
	{
		((ExtContentBrowserBlueprintLibrary_eventImportFromFileList_Parms*)Obj)->bOneByOne = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::NewProp_bOneByOne = { "bOneByOne", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ExtContentBrowserBlueprintLibrary_eventImportFromFileList_Parms), &Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::NewProp_bOneByOne_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::NewProp_FilePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::NewProp_ImportSetting,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::NewProp_bOneByOne,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "ImportSetting" },
		{ "Category", "UAssetBrowser|Import" },
		{ "CPP_Default_bOneByOne", "false" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserBlueprintLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExtContentBrowserBlueprintLibrary, nullptr, "ImportFromFileList", nullptr, nullptr, Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::PropPointers), sizeof(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::ExtContentBrowserBlueprintLibrary_eventImportFromFileList_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::Function_MetaDataParams), Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::ExtContentBrowserBlueprintLibrary_eventImportFromFileList_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics
	{
		struct ExtContentBrowserBlueprintLibrary_eventImportUAsset_Parms
		{
			FString AssetFilePath;
			FUAssetImportSetting ImportSetting;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AssetFilePath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AssetFilePath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImportSetting_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ImportSetting;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::NewProp_AssetFilePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::NewProp_AssetFilePath = { "AssetFilePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtContentBrowserBlueprintLibrary_eventImportUAsset_Parms, AssetFilePath), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::NewProp_AssetFilePath_MetaData), Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::NewProp_AssetFilePath_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::NewProp_ImportSetting_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::NewProp_ImportSetting = { "ImportSetting", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtContentBrowserBlueprintLibrary_eventImportUAsset_Parms, ImportSetting), Z_Construct_UScriptStruct_FUAssetImportSetting, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::NewProp_ImportSetting_MetaData), Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::NewProp_ImportSetting_MetaData) }; // 2966382491
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::NewProp_AssetFilePath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::NewProp_ImportSetting,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "ImportSetting" },
		{ "Category", "UAssetBrowser|Import" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserBlueprintLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExtContentBrowserBlueprintLibrary, nullptr, "ImportUAsset", nullptr, nullptr, Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::PropPointers), sizeof(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::ExtContentBrowserBlueprintLibrary_eventImportUAsset_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::ExtContentBrowserBlueprintLibrary_eventImportUAsset_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics
	{
		struct ExtContentBrowserBlueprintLibrary_eventImportUAssets_Parms
		{
			TArray<FString> AssetFilePaths;
			FUAssetImportSetting ImportSetting;
			bool bOneByOne;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_AssetFilePaths_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AssetFilePaths_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AssetFilePaths;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImportSetting_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_ImportSetting;
		static void NewProp_bOneByOne_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bOneByOne;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::NewProp_AssetFilePaths_Inner = { "AssetFilePaths", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::NewProp_AssetFilePaths_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::NewProp_AssetFilePaths = { "AssetFilePaths", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtContentBrowserBlueprintLibrary_eventImportUAssets_Parms, AssetFilePaths), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::NewProp_AssetFilePaths_MetaData), Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::NewProp_AssetFilePaths_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::NewProp_ImportSetting_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::NewProp_ImportSetting = { "ImportSetting", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtContentBrowserBlueprintLibrary_eventImportUAssets_Parms, ImportSetting), Z_Construct_UScriptStruct_FUAssetImportSetting, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::NewProp_ImportSetting_MetaData), Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::NewProp_ImportSetting_MetaData) }; // 2966382491
	void Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::NewProp_bOneByOne_SetBit(void* Obj)
	{
		((ExtContentBrowserBlueprintLibrary_eventImportUAssets_Parms*)Obj)->bOneByOne = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::NewProp_bOneByOne = { "bOneByOne", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ExtContentBrowserBlueprintLibrary_eventImportUAssets_Parms), &Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::NewProp_bOneByOne_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::NewProp_AssetFilePaths_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::NewProp_AssetFilePaths,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::NewProp_ImportSetting,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::NewProp_bOneByOne,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::Function_MetaDataParams[] = {
		{ "AutoCreateRefTerm", "AssetFilePaths, ImportSetting" },
		{ "Category", "UAssetBrowser|Import" },
		{ "CPP_Default_bOneByOne", "false" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserBlueprintLibrary.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExtContentBrowserBlueprintLibrary, nullptr, "ImportUAssets", nullptr, nullptr, Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::PropPointers), sizeof(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::ExtContentBrowserBlueprintLibrary_eventImportUAssets_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::Function_MetaDataParams), Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::ExtContentBrowserBlueprintLibrary_eventImportUAssets_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UExtContentBrowserBlueprintLibrary);
	UClass* Z_Construct_UClass_UExtContentBrowserBlueprintLibrary_NoRegister()
	{
		return UExtContentBrowserBlueprintLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UExtContentBrowserBlueprintLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UExtContentBrowserBlueprintLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_ExtContentBrowser,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UExtContentBrowserBlueprintLibrary_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UExtContentBrowserBlueprintLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetGlobalImportSetting, "GetGlobalImportSetting" }, // 2142791791
		{ &Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_GetSelectedUAssetFilePaths, "GetSelectedUAssetFilePaths" }, // 415026147
		{ &Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportFromFileList, "ImportFromFileList" }, // 1196490175
		{ &Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAsset, "ImportUAsset" }, // 3255717772
		{ &Z_Construct_UFunction_UExtContentBrowserBlueprintLibrary_ImportUAssets, "ImportUAssets" }, // 1086413873
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UExtContentBrowserBlueprintLibrary_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UExtContentBrowserBlueprintLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ExtContentBrowserBlueprintLibrary.h" },
		{ "ModuleRelativePath", "Public/ExtContentBrowserBlueprintLibrary.h" },
		{ "ScriptName", "UAssetBrowserLibrary" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UExtContentBrowserBlueprintLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UExtContentBrowserBlueprintLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UExtContentBrowserBlueprintLibrary_Statics::ClassParams = {
		&UExtContentBrowserBlueprintLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UExtContentBrowserBlueprintLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UExtContentBrowserBlueprintLibrary_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UExtContentBrowserBlueprintLibrary()
	{
		if (!Z_Registration_Info_UClass_UExtContentBrowserBlueprintLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UExtContentBrowserBlueprintLibrary.OuterSingleton, Z_Construct_UClass_UExtContentBrowserBlueprintLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UExtContentBrowserBlueprintLibrary.OuterSingleton;
	}
	template<> EXTCONTENTBROWSER_API UClass* StaticClass<UExtContentBrowserBlueprintLibrary>()
	{
		return UExtContentBrowserBlueprintLibrary::StaticClass();
	}
	UExtContentBrowserBlueprintLibrary::UExtContentBrowserBlueprintLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UExtContentBrowserBlueprintLibrary);
	UExtContentBrowserBlueprintLibrary::~UExtContentBrowserBlueprintLibrary() {}
	struct Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Public_ExtContentBrowserBlueprintLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Public_ExtContentBrowserBlueprintLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UExtContentBrowserBlueprintLibrary, UExtContentBrowserBlueprintLibrary::StaticClass, TEXT("UExtContentBrowserBlueprintLibrary"), &Z_Registration_Info_UClass_UExtContentBrowserBlueprintLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UExtContentBrowserBlueprintLibrary), 3059265218U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Public_ExtContentBrowserBlueprintLibrary_h_1638197330(TEXT("/Script/ExtContentBrowser"),
		Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Public_ExtContentBrowserBlueprintLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Public_ExtContentBrowserBlueprintLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
