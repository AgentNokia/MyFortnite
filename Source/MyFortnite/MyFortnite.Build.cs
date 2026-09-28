// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MyFortnite : ModuleRules
{
	public MyFortnite(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"MyFortnite",
			"MyFortnite/Variant_Platforming",
			"MyFortnite/Variant_Platforming/Animation",
			"MyFortnite/Variant_Combat",
			"MyFortnite/Variant_Combat/AI",
			"MyFortnite/Variant_Combat/Animation",
			"MyFortnite/Variant_Combat/Gameplay",
			"MyFortnite/Variant_Combat/Interfaces",
			"MyFortnite/Variant_Combat/UI",
			"MyFortnite/Variant_SideScrolling",
			"MyFortnite/Variant_SideScrolling/AI",
			"MyFortnite/Variant_SideScrolling/Gameplay",
			"MyFortnite/Variant_SideScrolling/Interfaces",
			"MyFortnite/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
