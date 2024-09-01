// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using System.IO;
namespace UnrealBuildTool.Rules
{
	[SupportedPlatforms("Win64")]
	public class CinewareAssetInstanceEditor : ModuleRules
	{

		public CinewareAssetInstanceEditor(ReadOnlyTargetRules Target) : base(Target)
		{
			bUsePrecompiled = true;

			DynamicallyLoadedModuleNames.AddRange(
				new string[] {
				"AssetTools",
				"MainFrame",
				});
		}
	}
}