using System.IO;

namespace UnrealBuildTool.Rules
{
	[SupportedPlatforms("Win64")]
	public class DatasmithCinewareTranslator : ModuleRules
	{
		public DatasmithCinewareTranslator(ReadOnlyTargetRules Target) : base(Target)
		{
			bUsePrecompiled = true;	
		}
	}
}

