// Author: Antonio Sidenko (Tonetfal), September 2025

using UnrealBuildTool;

public class CVarDrivenLogging : ModuleRules
{
	public CVarDrivenLogging(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
			}
		);
	}
}
