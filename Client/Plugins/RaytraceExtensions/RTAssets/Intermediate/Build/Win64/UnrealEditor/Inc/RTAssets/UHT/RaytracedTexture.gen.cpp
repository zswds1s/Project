// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RTAssets/Public/RaytracedTexture.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRaytracedTexture() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture();
	RTASSETS_API UClass* Z_Construct_UClass_URaytracedTexture();
	RTASSETS_API UClass* Z_Construct_UClass_URaytracedTexture_NoRegister();
	UPackage* Z_Construct_UPackage__Script_RTAssets();
// End Cross Module References
	void URaytracedTexture::StaticRegisterNativesURaytracedTexture()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(URaytracedTexture);
	UClass* Z_Construct_UClass_URaytracedTexture_NoRegister()
	{
		return URaytracedTexture::StaticClass();
	}
	struct Z_Construct_UClass_URaytracedTexture_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SizeX_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_SizeX;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SizeY_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_SizeY;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StaticMesh;
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
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_URaytracedTexture_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UTexture,
		(UObject* (*)())Z_Construct_UPackage__Script_RTAssets,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedTexture_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedTexture_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "RaytracedTexture.h" },
		{ "ModuleRelativePath", "Public/RaytracedTexture.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedTexture_Statics::NewProp_SizeX_MetaData[] = {
		{ "Category", "RaytraceAmbientOcclusion" },
		{ "ModuleRelativePath", "Public/RaytracedTexture.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_URaytracedTexture_Statics::NewProp_SizeX = { "SizeX", nullptr, (EPropertyFlags)0x0010010000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URaytracedTexture, SizeX), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedTexture_Statics::NewProp_SizeX_MetaData), Z_Construct_UClass_URaytracedTexture_Statics::NewProp_SizeX_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedTexture_Statics::NewProp_SizeY_MetaData[] = {
		{ "Category", "RaytraceAmbientOcclusion" },
		{ "ModuleRelativePath", "Public/RaytracedTexture.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_URaytracedTexture_Statics::NewProp_SizeY = { "SizeY", nullptr, (EPropertyFlags)0x0010010000020015, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URaytracedTexture, SizeY), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedTexture_Statics::NewProp_SizeY_MetaData), Z_Construct_UClass_URaytracedTexture_Statics::NewProp_SizeY_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedTexture_Statics::NewProp_StaticMesh_MetaData[] = {
		{ "Category", "Raytraced" },
		{ "DisplayName", "\xe9\x9d\x99\xe6\x80\x81\xe7\xbd\x91\xe6\xa0\xbc" },
		{ "ModuleRelativePath", "Public/RaytracedTexture.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_URaytracedTexture_Statics::NewProp_StaticMesh = { "StaticMesh", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(URaytracedTexture, StaticMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedTexture_Statics::NewProp_StaticMesh_MetaData), Z_Construct_UClass_URaytracedTexture_Statics::NewProp_StaticMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedTexture_Statics::NewProp_bDenoise_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedTexture.h" },
	};
#endif
	void Z_Construct_UClass_URaytracedTexture_Statics::NewProp_bDenoise_SetBit(void* Obj)
	{
		((URaytracedTexture*)Obj)->bDenoise = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_URaytracedTexture_Statics::NewProp_bDenoise = { "bDenoise", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(URaytracedTexture), &Z_Construct_UClass_URaytracedTexture_Statics::NewProp_bDenoise_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedTexture_Statics::NewProp_bDenoise_MetaData), Z_Construct_UClass_URaytracedTexture_Statics::NewProp_bDenoise_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_URaytracedTexture_Statics::NewProp_bProjectionMatrixUnadjusted_MetaData[] = {
		{ "ModuleRelativePath", "Public/RaytracedTexture.h" },
	};
#endif
	void Z_Construct_UClass_URaytracedTexture_Statics::NewProp_bProjectionMatrixUnadjusted_SetBit(void* Obj)
	{
		((URaytracedTexture*)Obj)->bProjectionMatrixUnadjusted = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_URaytracedTexture_Statics::NewProp_bProjectionMatrixUnadjusted = { "bProjectionMatrixUnadjusted", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(URaytracedTexture), &Z_Construct_UClass_URaytracedTexture_Statics::NewProp_bProjectionMatrixUnadjusted_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedTexture_Statics::NewProp_bProjectionMatrixUnadjusted_MetaData), Z_Construct_UClass_URaytracedTexture_Statics::NewProp_bProjectionMatrixUnadjusted_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_URaytracedTexture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedTexture_Statics::NewProp_SizeX,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedTexture_Statics::NewProp_SizeY,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedTexture_Statics::NewProp_StaticMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedTexture_Statics::NewProp_bDenoise,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_URaytracedTexture_Statics::NewProp_bProjectionMatrixUnadjusted,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_URaytracedTexture_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URaytracedTexture>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_URaytracedTexture_Statics::ClassParams = {
		&URaytracedTexture::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_URaytracedTexture_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedTexture_Statics::PropPointers),
		0,
		0x009000A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedTexture_Statics::Class_MetaDataParams), Z_Construct_UClass_URaytracedTexture_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URaytracedTexture_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_URaytracedTexture()
	{
		if (!Z_Registration_Info_UClass_URaytracedTexture.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URaytracedTexture.OuterSingleton, Z_Construct_UClass_URaytracedTexture_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_URaytracedTexture.OuterSingleton;
	}
	template<> RTASSETS_API UClass* StaticClass<URaytracedTexture>()
	{
		return URaytracedTexture::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(URaytracedTexture);
	URaytracedTexture::~URaytracedTexture() {}
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(URaytracedTexture)
	struct Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedTexture_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedTexture_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_URaytracedTexture, URaytracedTexture::StaticClass, TEXT("URaytracedTexture"), &Z_Registration_Info_UClass_URaytracedTexture, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URaytracedTexture), 1534681592U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedTexture_h_3379935271(TEXT("/Script/RTAssets"),
		Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedTexture_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_UnrealProjects_Raytraced_Plugins_RaytraceExtensions_RTAssets_Source_RTAssets_Public_RaytracedTexture_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
