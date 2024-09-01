// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RTAssets/Public/RaytracedAO.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRaytracedAO() {}
// Cross Module References
	RTASSETS_API UClass* Z_Construct_UClass_URaytracedAmbientOcclusion();
	RTASSETS_API UClass* Z_Construct_UClass_URaytracedAmbientOcclusion_NoRegister();
	RTASSETS_API UClass* Z_Construct_UClass_URaytracedTexture();
	UPackage* Z_Construct_UPackage__Script_RTAssets();
// End Cross Module References
	void URaytracedAmbientOcclusion::StaticRegisterNativesURaytracedAmbientOcclusion()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URaytracedAmbientOcclusion);
	UClass* Z_Construct_UClass_URaytracedAmbientOcclusion_NoRegister()
	{
		return URaytracedAmbientOcclusion::StaticClass();
	}
	struct Z_Construct_UClass_URaytracedAmbientOcclusion_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SamplesPerPixel_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_SamplesPerPixel;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Intensity_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Intensity;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxRayDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxRayDistance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxNormalBias_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxNormalBias;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_URaytracedTexture,
		(UObject* (*)())Z_Construct_UPackage__Script_RTAssets,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Compression Texture Adjustments Compositing LevelOfDetail FilePath" },
		{ "IncludePath", "RaytracedAO.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/RaytracedAO.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_SamplesPerPixel_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedAO.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_SamplesPerPixel = { "SamplesPerPixel", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URaytracedAmbientOcclusion, SamplesPerPixel), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_SamplesPerPixel_MetaData), Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_SamplesPerPixel_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_Intensity_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedAO.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_Intensity = { "Intensity", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URaytracedAmbientOcclusion, Intensity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_Intensity_MetaData), Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_Intensity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_MaxRayDistance_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedAO.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_MaxRayDistance = { "MaxRayDistance", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URaytracedAmbientOcclusion, MaxRayDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_MaxRayDistance_MetaData), Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_MaxRayDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_MaxNormalBias_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedAO.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_MaxNormalBias = { "MaxNormalBias", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URaytracedAmbientOcclusion, MaxNormalBias), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_MaxNormalBias_MetaData), Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_MaxNormalBias_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_SamplesPerPixel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_Intensity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_MaxRayDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::NewProp_MaxNormalBias,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URaytracedAmbientOcclusion>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::ClassParams = {
		&URaytracedAmbientOcclusion::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::Class_MetaDataParams), Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_URaytracedAmbientOcclusion()
	{
		if (!Z_Registration_Info_UClass_URaytracedAmbientOcclusion.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URaytracedAmbientOcclusion.OuterSingleton, Z_Construct_UClass_URaytracedAmbientOcclusion_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_URaytracedAmbientOcclusion.OuterSingleton;
	}
	template<> RTASSETS_API UClass* StaticClass<URaytracedAmbientOcclusion>()
	{
		return URaytracedAmbientOcclusion::StaticClass();
	}
	URaytracedAmbientOcclusion::URaytracedAmbientOcclusion(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(URaytracedAmbientOcclusion);
	URaytracedAmbientOcclusion::~URaytracedAmbientOcclusion() {}
	struct Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedAO_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedAO_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_URaytracedAmbientOcclusion, URaytracedAmbientOcclusion::StaticClass, TEXT("URaytracedAmbientOcclusion"), &Z_Registration_Info_UClass_URaytracedAmbientOcclusion, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URaytracedAmbientOcclusion), 194176715U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedAO_h_1946387792(TEXT("/Script/RTAssets"),
		Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedAO_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedAO_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
