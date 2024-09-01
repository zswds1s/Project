// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RTAssets/Public/RaytracedBevel.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRaytracedBevel() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_TextureFilter();
	RTASSETS_API UClass* Z_Construct_UClass_URaytracedBevelNormal();
	RTASSETS_API UClass* Z_Construct_UClass_URaytracedBevelNormal_NoRegister();
	RTASSETS_API UClass* Z_Construct_UClass_URaytracedTexture();
	RTASSETS_API UScriptStruct* Z_Construct_UScriptStruct_FBevelRandomResult();
	UPackage* Z_Construct_UPackage__Script_RTAssets();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_BevelRandomResult;
class UScriptStruct* FBevelRandomResult::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_BevelRandomResult.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_BevelRandomResult.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FBevelRandomResult, (UObject*)Z_Construct_UPackage__Script_RTAssets(), TEXT("BevelRandomResult"));
	}
	return Z_Registration_Info_UScriptStruct_BevelRandomResult.OuterSingleton;
}
template<> RTASSETS_API UScriptStruct* StaticStruct<FBevelRandomResult>()
{
	return FBevelRandomResult::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FBevelRandomResult_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Position_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Position;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Direction_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Length_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Length;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBevelRandomResult_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/RaytracedBevel.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FBevelRandomResult>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewProp_Position_MetaData[] = {
		{ "Category", "Model Bevel" },
		{ "ModuleRelativePath", "Public/RaytracedBevel.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewProp_Position = { "Position", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBevelRandomResult, Position), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewProp_Position_MetaData), Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewProp_Position_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewProp_Direction_MetaData[] = {
		{ "Category", "Model Bevel" },
		{ "ModuleRelativePath", "Public/RaytracedBevel.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBevelRandomResult, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewProp_Direction_MetaData), Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewProp_Direction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewProp_Length_MetaData[] = {
		{ "Category", "Model Bevel" },
		{ "ModuleRelativePath", "Public/RaytracedBevel.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewProp_Length = { "Length", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FBevelRandomResult, Length), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewProp_Length_MetaData), Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewProp_Length_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FBevelRandomResult_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewProp_Position,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewProp_Direction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewProp_Length,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FBevelRandomResult_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_RTAssets,
		nullptr,
		&NewStructOps,
		"BevelRandomResult",
		Z_Construct_UScriptStruct_FBevelRandomResult_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBevelRandomResult_Statics::PropPointers),
		sizeof(FBevelRandomResult),
		alignof(FBevelRandomResult),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBevelRandomResult_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FBevelRandomResult_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBevelRandomResult_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FBevelRandomResult()
	{
		if (!Z_Registration_Info_UScriptStruct_BevelRandomResult.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_BevelRandomResult.InnerSingleton, Z_Construct_UScriptStruct_FBevelRandomResult_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_BevelRandomResult.InnerSingleton;
	}
	void URaytracedBevelNormal::StaticRegisterNativesURaytracedBevelNormal()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URaytracedBevelNormal);
	UClass* Z_Construct_UClass_URaytracedBevelNormal_NoRegister()
	{
		return URaytracedBevelNormal::StaticClass();
	}
	struct Z_Construct_UClass_URaytracedBevelNormal_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxAngle_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxAngle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Roundness_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Roundness;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NumSamples_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_NumSamples;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BevelFilter_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_BevelFilter;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URaytracedBevelNormal_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_URaytracedTexture,
		(UObject* (*)())Z_Construct_UPackage__Script_RTAssets,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedBevelNormal_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedBevelNormal_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Compression Texture Adjustments Compositing LevelOfDetail FilePath" },
		{ "IncludePath", "RaytracedBevel.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/RaytracedBevel.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_MaxAngle_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedBevel.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_MaxAngle = { "MaxAngle", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URaytracedBevelNormal, MaxAngle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_MaxAngle_MetaData), Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_MaxAngle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_Roundness_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedBevel.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_Roundness = { "Roundness", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URaytracedBevelNormal, Roundness), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_Roundness_MetaData), Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_Roundness_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_Radius_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedBevel.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URaytracedBevelNormal, Radius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_Radius_MetaData), Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_Radius_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_NumSamples_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedBevel.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_NumSamples = { "NumSamples", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URaytracedBevelNormal, NumSamples), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_NumSamples_MetaData), Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_NumSamples_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_BevelFilter_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedBevel.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_BevelFilter = { "BevelFilter", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URaytracedBevelNormal, BevelFilter), Z_Construct_UEnum_Engine_TextureFilter, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_BevelFilter_MetaData), Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_BevelFilter_MetaData) }; // 2612248343
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URaytracedBevelNormal_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_MaxAngle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_Roundness,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_Radius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_NumSamples,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedBevelNormal_Statics::NewProp_BevelFilter,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_URaytracedBevelNormal_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URaytracedBevelNormal>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_URaytracedBevelNormal_Statics::ClassParams = {
		&URaytracedBevelNormal::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_URaytracedBevelNormal_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedBevelNormal_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedBevelNormal_Statics::Class_MetaDataParams), Z_Construct_UClass_URaytracedBevelNormal_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedBevelNormal_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_URaytracedBevelNormal()
	{
		if (!Z_Registration_Info_UClass_URaytracedBevelNormal.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URaytracedBevelNormal.OuterSingleton, Z_Construct_UClass_URaytracedBevelNormal_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_URaytracedBevelNormal.OuterSingleton;
	}
	template<> RTASSETS_API UClass* StaticClass<URaytracedBevelNormal>()
	{
		return URaytracedBevelNormal::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(URaytracedBevelNormal);
	URaytracedBevelNormal::~URaytracedBevelNormal() {}
	struct Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedBevel_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedBevel_h_Statics::ScriptStructInfo[] = {
		{ FBevelRandomResult::StaticStruct, Z_Construct_UScriptStruct_FBevelRandomResult_Statics::NewStructOps, TEXT("BevelRandomResult"), &Z_Registration_Info_UScriptStruct_BevelRandomResult, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FBevelRandomResult), 2197337688U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedBevel_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_URaytracedBevelNormal, URaytracedBevelNormal::StaticClass, TEXT("URaytracedBevelNormal"), &Z_Registration_Info_UClass_URaytracedBevelNormal, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URaytracedBevelNormal), 813496407U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedBevel_h_3828882630(TEXT("/Script/RTAssets"),
		Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedBevel_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedBevel_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedBevel_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedBevel_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
