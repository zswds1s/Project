using System.IO;

namespace UnrealBuildTool.Rules
{
	[SupportedPlatforms("Win64")]
	public class CinewareAssetInstance : ModuleRules
	{
		public CinewareAssetInstance(ReadOnlyTargetRules Target) : base(Target)
		{
			bUsePrecompiled = true;
			
			PublicDependencyModuleNames.AddRange(
				new string[] {
					"Core",
					"CoreUObject",
				});

			if (Target.Platform == UnrealTargetPlatform.Mac)
			{
				PublicDefinitions.Add("__MAC");
				PublicFrameworks.Add("CoreAudio"); // MDL uses some multimedia timers from Core.Audio
			}
		}
	}
}