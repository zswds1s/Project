// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ExtContentBrowser/Private/Adapters/ExtContentBrowserMenuContexts.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeExtContentBrowserMenuContexts() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	EXTCONTENTBROWSER_API UClass* Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext();
	EXTCONTENTBROWSER_API UClass* Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ExtContentBrowser();
// End Cross Module References
	DEFINE_FUNCTION(UExtContentBrowserAssetContextMenuContext::execGetSelectedObjects)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UObject*>*)Z_Param__Result=P_THIS->GetSelectedObjects();
		P_NATIVE_END;
	}
	void UExtContentBrowserAssetContextMenuContext::StaticRegisterNativesUExtContentBrowserAssetContextMenuContext()
	{
		UClass* Class = UExtContentBrowserAssetContextMenuContext::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetSelectedObjects", &UExtContentBrowserAssetContextMenuContext::execGetSelectedObjects },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects_Statics
	{
		struct ExtContentBrowserAssetContextMenuContext_eventGetSelectedObjects_Parms
		{
			TArray<UObject*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ExtContentBrowserAssetContextMenuContext_eventGetSelectedObjects_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects_Statics::Function_MetaDataParams[] = {
		{ "Category", "Tool Menus" },
		{ "ModuleRelativePath", "Private/Adapters/ExtContentBrowserMenuContexts.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext, nullptr, "GetSelectedObjects", nullptr, nullptr, Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects_Statics::PropPointers), sizeof(Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects_Statics::ExtContentBrowserAssetContextMenuContext_eventGetSelectedObjects_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects_Statics::Function_MetaDataParams), Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects_Statics::ExtContentBrowserAssetContextMenuContext_eventGetSelectedObjects_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UExtContentBrowserAssetContextMenuContext);
	UClass* Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_NoRegister()
	{
		return UExtContentBrowserAssetContextMenuContext::StaticClass();
	}
	struct Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_SelectedObjects_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SelectedObjects_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_SelectedObjects;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CommonClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_CommonClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_ExtContentBrowser,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UExtContentBrowserAssetContextMenuContext_GetSelectedObjects, "GetSelectedObjects" }, // 4196780815
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Adapters/ExtContentBrowserMenuContexts.h" },
		{ "ModuleRelativePath", "Private/Adapters/ExtContentBrowserMenuContexts.h" },
	};
#endif
	const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::NewProp_SelectedObjects_Inner = { "SelectedObjects", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::NewProp_SelectedObjects_MetaData[] = {
		{ "ModuleRelativePath", "Private/Adapters/ExtContentBrowserMenuContexts.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::NewProp_SelectedObjects = { "SelectedObjects", nullptr, (EPropertyFlags)0x0014000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UExtContentBrowserAssetContextMenuContext, SelectedObjects), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::NewProp_SelectedObjects_MetaData), Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::NewProp_SelectedObjects_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::NewProp_CommonClass_MetaData[] = {
		{ "ModuleRelativePath", "Private/Adapters/ExtContentBrowserMenuContexts.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::NewProp_CommonClass = { "CommonClass", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UExtContentBrowserAssetContextMenuContext, CommonClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::NewProp_CommonClass_MetaData), Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::NewProp_CommonClass_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::NewProp_SelectedObjects_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::NewProp_SelectedObjects,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::NewProp_CommonClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UExtContentBrowserAssetContextMenuContext>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::ClassParams = {
		&UExtContentBrowserAssetContextMenuContext::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::Class_MetaDataParams), Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext()
	{
		if (!Z_Registration_Info_UClass_UExtContentBrowserAssetContextMenuContext.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UExtContentBrowserAssetContextMenuContext.OuterSingleton, Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UExtContentBrowserAssetContextMenuContext.OuterSingleton;
	}
	template<> EXTCONTENTBROWSER_API UClass* StaticClass<UExtContentBrowserAssetContextMenuContext>()
	{
		return UExtContentBrowserAssetContextMenuContext::StaticClass();
	}
	UExtContentBrowserAssetContextMenuContext::UExtContentBrowserAssetContextMenuContext(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UExtContentBrowserAssetContextMenuContext);
	UExtContentBrowserAssetContextMenuContext::~UExtContentBrowserAssetContextMenuContext() {}
	struct Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Private_Adapters_ExtContentBrowserMenuContexts_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Private_Adapters_ExtContentBrowserMenuContexts_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UExtContentBrowserAssetContextMenuContext, UExtContentBrowserAssetContextMenuContext::StaticClass, TEXT("UExtContentBrowserAssetContextMenuContext"), &Z_Registration_Info_UClass_UExtContentBrowserAssetContextMenuContext, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UExtContentBrowserAssetContextMenuContext), 1964983990U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Private_Adapters_ExtContentBrowserMenuContexts_h_2548585399(TEXT("/Script/ExtContentBrowser"),
		Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Private_Adapters_ExtContentBrowserMenuContexts_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Build_U5M_Marketplace_Mac_Sync_LocalBuilds_PluginTemp_HostProject_Plugins_UAssetBrowser_Source_ExtContentBrowser_Private_Adapters_ExtContentBrowserMenuContexts_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
