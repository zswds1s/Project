// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RTEditor/Public/RaytracedAssetFactory.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRaytracedAssetFactory() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UMaterialExpression();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialExpression_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialExpressionTextureSample_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialExpressionTransform_NoRegister();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_TextureFilter();
	RTASSETS_API UClass* Z_Construct_UClass_URaytracedAmbientOcclusion_NoRegister();
	RTASSETS_API UClass* Z_Construct_UClass_URaytracedBevelNormal_NoRegister();
	RTEDITOR_API UClass* Z_Construct_UClass_UMaterialExpressionRTAO();
	RTEDITOR_API UClass* Z_Construct_UClass_UMaterialExpressionRTAO_NoRegister();
	RTEDITOR_API UClass* Z_Construct_UClass_UMaterialExpressionRTBevel();
	RTEDITOR_API UClass* Z_Construct_UClass_UMaterialExpressionRTBevel_NoRegister();
	RTEDITOR_API UClass* Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew();
	RTEDITOR_API UClass* Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_NoRegister();
	RTEDITOR_API UClass* Z_Construct_UClass_URaytracedBevelNormallFactoryNew();
	RTEDITOR_API UClass* Z_Construct_UClass_URaytracedBevelNormallFactoryNew_NoRegister();
	UNREALED_API UClass* Z_Construct_UClass_UFactory();
	UPackage* Z_Construct_UPackage__Script_RTEditor();
// End Cross Module References
	void UMaterialExpressionRTAO::StaticRegisterNativesUMaterialExpressionRTAO()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMaterialExpressionRTAO);
	UClass* Z_Construct_UClass_UMaterialExpressionRTAO_NoRegister()
	{
		return UMaterialExpressionRTAO::StaticClass();
	}
	struct Z_Construct_UClass_UMaterialExpressionRTAO_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Asset_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_Asset;
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
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDenoise_MetaData[];
#endif
		static void NewProp_bDenoise_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDenoise;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bProjectionMatrixUnadjusted_MetaData[];
#endif
		static void NewProp_bProjectionMatrixUnadjusted_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bProjectionMatrixUnadjusted;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPosition_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ScreenPosition;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RaytracedAO_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RaytracedAO;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMaterialExpressionRTAO_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UMaterialExpression,
		(UObject* (*)())Z_Construct_UPackage__Script_RTEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTAO_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTAO_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n *\n */" },
#endif
		{ "HideCategories", "Object ParameterCustomization MaterialExpressionTextureSample MaterialExpressionTextureBase Object" },
		{ "IncludePath", "RaytracedAssetFactory.h" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_Asset_MetaData[] = {
		{ "Category", "Asset" },
		{ "DisplayName", "\xe9\xa2\x84\xe8\xae\xbe" },
		{ "DisplayPriority", "0" },
		{ "DisplayThumbnail", "false" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMaterialExpressionRTAO, Asset), Z_Construct_UClass_URaytracedAmbientOcclusion_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_Asset_MetaData), Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_Asset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_SamplesPerPixel_MetaData[] = {
		{ "Category", "Asset" },
		{ "DisplayName", "\xe5\x83\x8f\xe7\xb4\xa0\xe9\x87\x87\xe6\xa0\xb7(SPP)" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
		{ "UIMax", "64" },
		{ "UIMin", "1" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_SamplesPerPixel = { "SamplesPerPixel", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMaterialExpressionRTAO, SamplesPerPixel), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_SamplesPerPixel_MetaData), Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_SamplesPerPixel_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_Intensity_MetaData[] = {
		{ "Category", "Asset" },
		{ "DisplayName", "\xe5\xbc\xba\xe5\xba\xa6" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
		{ "UIMin", "0.01" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_Intensity = { "Intensity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMaterialExpressionRTAO, Intensity), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_Intensity_MetaData), Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_Intensity_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_MaxRayDistance_MetaData[] = {
		{ "Category", "Asset" },
		{ "DisplayName", "\xe5\x8f\x8d\xe5\xb0\x84\xe8\xb7\x9d\xe7\xa6\xbb" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
#if !UE_BUILD_SHIPPING
		{ "tooltip", "unit : cm" },
#endif
		{ "UIMin", "1.0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_MaxRayDistance = { "MaxRayDistance", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMaterialExpressionRTAO, MaxRayDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_MaxRayDistance_MetaData), Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_MaxRayDistance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_MaxNormalBias_MetaData[] = {
		{ "Category", "Asset" },
		{ "DisplayName", "\xe6\xb3\x95\xe7\xba\xbf\xe5\x81\x8f\xe7\xa7\xbb" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
#if !UE_BUILD_SHIPPING
		{ "tooltip", "\xe5\xb0\x84\xe7\xba\xbf\xe8\xb5\xb7\xe7\x82\xb9\xe6\x8c\x89\xe6\xb3\x95\xe7\xba\xbf\xe6\x96\xb9\xe5\x90\x91\xe5\x81\x8f\xe7\xa7\xbb\xe8\xb7\x9d\xe7\xa6\xbb(cm)" },
#endif
		{ "UIMax", "100" },
		{ "UIMin", "0.01" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_MaxNormalBias = { "MaxNormalBias", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMaterialExpressionRTAO, MaxNormalBias), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_MaxNormalBias_MetaData), Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_MaxNormalBias_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_bDenoise_MetaData[] = {
		{ "Category", "Asset" },
		{ "DisplayName", "\xe9\x99\x8d\xe5\x99\xaa" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
	};
#endif
	void Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_bDenoise_SetBit(void* Obj)
	{
		((UMaterialExpressionRTAO*)Obj)->bDenoise = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_bDenoise = { "bDenoise", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UMaterialExpressionRTAO), &Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_bDenoise_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_bDenoise_MetaData), Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_bDenoise_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_bProjectionMatrixUnadjusted_MetaData[] = {
		{ "Category", "Asset" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
	};
#endif
	void Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_bProjectionMatrixUnadjusted_SetBit(void* Obj)
	{
		((UMaterialExpressionRTAO*)Obj)->bProjectionMatrixUnadjusted = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_bProjectionMatrixUnadjusted = { "bProjectionMatrixUnadjusted", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UMaterialExpressionRTAO), &Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_bProjectionMatrixUnadjusted_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_bProjectionMatrixUnadjusted_MetaData), Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_bProjectionMatrixUnadjusted_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_ScreenPosition_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_ScreenPosition = { "ScreenPosition", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMaterialExpressionRTAO, ScreenPosition), Z_Construct_UClass_UMaterialExpression_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_ScreenPosition_MetaData), Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_ScreenPosition_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_RaytracedAO_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_RaytracedAO = { "RaytracedAO", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMaterialExpressionRTAO, RaytracedAO), Z_Construct_UClass_UMaterialExpressionTextureSample_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_RaytracedAO_MetaData), Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_RaytracedAO_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMaterialExpressionRTAO_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_SamplesPerPixel,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_Intensity,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_MaxRayDistance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_MaxNormalBias,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_bDenoise,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_bProjectionMatrixUnadjusted,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_ScreenPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTAO_Statics::NewProp_RaytracedAO,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMaterialExpressionRTAO_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMaterialExpressionRTAO>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMaterialExpressionRTAO_Statics::ClassParams = {
		&UMaterialExpressionRTAO::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMaterialExpressionRTAO_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTAO_Statics::PropPointers),
		0,
		0x000820B0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTAO_Statics::Class_MetaDataParams), Z_Construct_UClass_UMaterialExpressionRTAO_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTAO_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UMaterialExpressionRTAO()
	{
		if (!Z_Registration_Info_UClass_UMaterialExpressionRTAO.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMaterialExpressionRTAO.OuterSingleton, Z_Construct_UClass_UMaterialExpressionRTAO_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMaterialExpressionRTAO.OuterSingleton;
	}
	template<> RTEDITOR_API UClass* StaticClass<UMaterialExpressionRTAO>()
	{
		return UMaterialExpressionRTAO::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMaterialExpressionRTAO);
	UMaterialExpressionRTAO::~UMaterialExpressionRTAO() {}
	void URaytracedAmbientOcclusionFactoryNew::StaticRegisterNativesURaytracedAmbientOcclusionFactoryNew()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URaytracedAmbientOcclusionFactoryNew);
	UClass* Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_NoRegister()
	{
		return URaytracedAmbientOcclusionFactoryNew::StaticClass();
	}
	struct Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Width_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Width;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Height;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_RTEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "RaytracedAssetFactory.h" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::NewProp_Width_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Width of the texture render target" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URaytracedAmbientOcclusionFactoryNew, Width), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::NewProp_Width_MetaData), Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::NewProp_Width_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::NewProp_Height_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Height of the texture render target" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URaytracedAmbientOcclusionFactoryNew, Height), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::NewProp_Height_MetaData), Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::NewProp_Height_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::NewProp_Width,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::NewProp_Height,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URaytracedAmbientOcclusionFactoryNew>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::ClassParams = {
		&URaytracedAmbientOcclusionFactoryNew::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::Class_MetaDataParams), Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew()
	{
		if (!Z_Registration_Info_UClass_URaytracedAmbientOcclusionFactoryNew.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URaytracedAmbientOcclusionFactoryNew.OuterSingleton, Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_URaytracedAmbientOcclusionFactoryNew.OuterSingleton;
	}
	template<> RTEDITOR_API UClass* StaticClass<URaytracedAmbientOcclusionFactoryNew>()
	{
		return URaytracedAmbientOcclusionFactoryNew::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(URaytracedAmbientOcclusionFactoryNew);
	URaytracedAmbientOcclusionFactoryNew::~URaytracedAmbientOcclusionFactoryNew() {}
	void UMaterialExpressionRTBevel::StaticRegisterNativesUMaterialExpressionRTBevel()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMaterialExpressionRTBevel);
	UClass* Z_Construct_UClass_UMaterialExpressionRTBevel_NoRegister()
	{
		return UMaterialExpressionRTBevel::StaticClass();
	}
	struct Z_Construct_UClass_UMaterialExpressionRTBevel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Asset_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_Asset;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxAngle_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxAngle;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Radius_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Radius;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NumSamples_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_NumSamples;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bDenoise_MetaData[];
#endif
		static void NewProp_bDenoise_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bDenoise;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BevelFilter_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_BevelFilter;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreenPosition_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ScreenPosition;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BevelNormal_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BevelNormal;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TransformVector_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TransformVector;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UMaterialExpression,
		(UObject* (*)())Z_Construct_UPackage__Script_RTEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object ParameterCustomization MaterialExpressionTextureSample MaterialExpressionTextureBase Object" },
		{ "IncludePath", "RaytracedAssetFactory.h" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_Asset_MetaData[] = {
		{ "Category", "Asset" },
		{ "DisplayName", "\xe9\xa2\x84\xe8\xae\xbe" },
		{ "DisplayPriority", "0" },
		{ "DisplayThumbnail", "false" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_Asset = { "Asset", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMaterialExpressionRTBevel, Asset), Z_Construct_UClass_URaytracedBevelNormal_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_Asset_MetaData), Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_Asset_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_MaxAngle_MetaData[] = {
		{ "Category", "Asset" },
		{ "DisplayName", "\xe6\x9c\x80\xe5\xa4\xa7\xe8\xa7\x92\xe5\xba\xa6" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
		{ "UIMax", "180" },
		{ "UIMin", "0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_MaxAngle = { "MaxAngle", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMaterialExpressionRTBevel, MaxAngle), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_MaxAngle_MetaData), Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_MaxAngle_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_Radius_MetaData[] = {
		{ "Category", "Asset" },
		{ "DisplayName", "\xe5\x8d\x8a\xe5\xbe\x84" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
		{ "UIMin", "0.0" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_Radius = { "Radius", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMaterialExpressionRTBevel, Radius), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_Radius_MetaData), Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_Radius_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_NumSamples_MetaData[] = {
		{ "Category", "Asset" },
		{ "DisplayName", "\xe5\x83\x8f\xe7\xb4\xa0\xe9\x87\x87\xe6\xa0\xb7(SPP)" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
		{ "UIMax", "64" },
		{ "UIMin", "1" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_NumSamples = { "NumSamples", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMaterialExpressionRTBevel, NumSamples), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_NumSamples_MetaData), Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_NumSamples_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_bDenoise_MetaData[] = {
		{ "Category", "Asset" },
		{ "DisplayName", "\xe9\x99\x8d\xe5\x99\xaa" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
	};
#endif
	void Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_bDenoise_SetBit(void* Obj)
	{
		((UMaterialExpressionRTBevel*)Obj)->bDenoise = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_bDenoise = { "bDenoise", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UMaterialExpressionRTBevel), &Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_bDenoise_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_bDenoise_MetaData), Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_bDenoise_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_BevelFilter_MetaData[] = {
		{ "Category", "Asset" },
		{ "DisplayName", "\xe9\x87\x87\xe6\xa0\xb7" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_BevelFilter = { "BevelFilter", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMaterialExpressionRTBevel, BevelFilter), Z_Construct_UEnum_Engine_TextureFilter, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_BevelFilter_MetaData), Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_BevelFilter_MetaData) }; // 2612248343
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_ScreenPosition_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_ScreenPosition = { "ScreenPosition", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMaterialExpressionRTBevel, ScreenPosition), Z_Construct_UClass_UMaterialExpression_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_ScreenPosition_MetaData), Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_ScreenPosition_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_BevelNormal_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_BevelNormal = { "BevelNormal", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMaterialExpressionRTBevel, BevelNormal), Z_Construct_UClass_UMaterialExpressionTextureSample_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_BevelNormal_MetaData), Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_BevelNormal_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_TransformVector_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_TransformVector = { "TransformVector", nullptr, (EPropertyFlags)0x0020080000002000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UMaterialExpressionRTBevel, TransformVector), Z_Construct_UClass_UMaterialExpressionTransform_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_TransformVector_MetaData), Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_TransformVector_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_Asset,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_MaxAngle,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_Radius,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_NumSamples,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_bDenoise,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_BevelFilter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_ScreenPosition,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_BevelNormal,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::NewProp_TransformVector,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMaterialExpressionRTBevel>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::ClassParams = {
		&UMaterialExpressionRTBevel::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::PropPointers),
		0,
		0x000820B0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::Class_MetaDataParams), Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UMaterialExpressionRTBevel()
	{
		if (!Z_Registration_Info_UClass_UMaterialExpressionRTBevel.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMaterialExpressionRTBevel.OuterSingleton, Z_Construct_UClass_UMaterialExpressionRTBevel_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMaterialExpressionRTBevel.OuterSingleton;
	}
	template<> RTEDITOR_API UClass* StaticClass<UMaterialExpressionRTBevel>()
	{
		return UMaterialExpressionRTBevel::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMaterialExpressionRTBevel);
	UMaterialExpressionRTBevel::~UMaterialExpressionRTBevel() {}
	void URaytracedBevelNormallFactoryNew::StaticRegisterNativesURaytracedBevelNormallFactoryNew()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URaytracedBevelNormallFactoryNew);
	UClass* Z_Construct_UClass_URaytracedBevelNormallFactoryNew_NoRegister()
	{
		return URaytracedBevelNormallFactoryNew::StaticClass();
	}
	struct Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Width_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Width;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Height_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_Height;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFactory,
		(UObject* (*)())Z_Construct_UPackage__Script_RTEditor,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "RaytracedAssetFactory.h" },
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::NewProp_Width_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Width of the texture render target" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URaytracedBevelNormallFactoryNew, Width), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::NewProp_Width_MetaData), Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::NewProp_Width_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::NewProp_Height_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedAssetFactory.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Height of the texture render target" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URaytracedBevelNormallFactoryNew, Height), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::NewProp_Height_MetaData), Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::NewProp_Height_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::NewProp_Width,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::NewProp_Height,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URaytracedBevelNormallFactoryNew>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::ClassParams = {
		&URaytracedBevelNormallFactoryNew::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::Class_MetaDataParams), Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_URaytracedBevelNormallFactoryNew()
	{
		if (!Z_Registration_Info_UClass_URaytracedBevelNormallFactoryNew.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URaytracedBevelNormallFactoryNew.OuterSingleton, Z_Construct_UClass_URaytracedBevelNormallFactoryNew_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_URaytracedBevelNormallFactoryNew.OuterSingleton;
	}
	template<> RTEDITOR_API UClass* StaticClass<URaytracedBevelNormallFactoryNew>()
	{
		return URaytracedBevelNormallFactoryNew::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(URaytracedBevelNormallFactoryNew);
	URaytracedBevelNormallFactoryNew::~URaytracedBevelNormallFactoryNew() {}
	struct Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTEditor_Source_RTEditor_Public_RaytracedAssetFactory_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTEditor_Source_RTEditor_Public_RaytracedAssetFactory_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMaterialExpressionRTAO, UMaterialExpressionRTAO::StaticClass, TEXT("UMaterialExpressionRTAO"), &Z_Registration_Info_UClass_UMaterialExpressionRTAO, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMaterialExpressionRTAO), 3106802004U) },
		{ Z_Construct_UClass_URaytracedAmbientOcclusionFactoryNew, URaytracedAmbientOcclusionFactoryNew::StaticClass, TEXT("URaytracedAmbientOcclusionFactoryNew"), &Z_Registration_Info_UClass_URaytracedAmbientOcclusionFactoryNew, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URaytracedAmbientOcclusionFactoryNew), 847880057U) },
		{ Z_Construct_UClass_UMaterialExpressionRTBevel, UMaterialExpressionRTBevel::StaticClass, TEXT("UMaterialExpressionRTBevel"), &Z_Registration_Info_UClass_UMaterialExpressionRTBevel, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMaterialExpressionRTBevel), 1179515546U) },
		{ Z_Construct_UClass_URaytracedBevelNormallFactoryNew, URaytracedBevelNormallFactoryNew::StaticClass, TEXT("URaytracedBevelNormallFactoryNew"), &Z_Registration_Info_UClass_URaytracedBevelNormallFactoryNew, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URaytracedBevelNormallFactoryNew), 2796405111U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTEditor_Source_RTEditor_Public_RaytracedAssetFactory_h_151382588(TEXT("/Script/RTEditor"),
		Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTEditor_Source_RTEditor_Public_RaytracedAssetFactory_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTEditor_Source_RTEditor_Public_RaytracedAssetFactory_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
