// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRTAssets_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_RTAssets;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_RTAssets()
	{
		if (!Z_Registration_Info_UPackage__Script_RTAssets.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/RTAssets",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x89C8D970,
				0xD15FE5D7,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_RTAssets.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_RTAssets.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_RTAssets(Z_Construct_UPackage__Script_RTAssets, TEXT("/Script/RTAssets"), Z_Registration_Info_UPackage__Script_RTAssets, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x89C8D970, 0xD15FE5D7));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
