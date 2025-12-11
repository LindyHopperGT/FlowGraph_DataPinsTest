// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

using UnrealBuildTool;

public class FlowGraph_DataPinsTest : ModuleRules
{
	public FlowGraph_DataPinsTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core",
			"CoreUObject",
			"Engine",
			"GameplayTags",
			"Flow",
		});

		PrivateDependencyModuleNames.AddRange(new string[] 
		{
		});
	}
}
