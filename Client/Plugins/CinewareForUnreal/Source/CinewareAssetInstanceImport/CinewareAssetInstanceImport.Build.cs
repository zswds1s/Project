using System.IO;

namespace UnrealBuildTool.Rules
{
	[SupportedPlatforms("Win64")]
	public class CinewareAssetInstanceImport : ModuleRules
	{
		public CinewareAssetInstanceImport(ReadOnlyTargetRules Target) : base(Target)
		{
			bUsePrecompiled = true;
		}
	}
}
