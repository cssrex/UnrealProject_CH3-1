// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DreamTeam : ModuleRules
{
	public DreamTeam(ReadOnlyTargetRules Target) : base(Target)
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
			"DreamTeam",
			"DreamTeam/Variant_Platforming",
			"DreamTeam/Variant_Platforming/Animation",
			"DreamTeam/Variant_Combat",
			"DreamTeam/Variant_Combat/AI",
			"DreamTeam/Variant_Combat/Animation",
			"DreamTeam/Variant_Combat/Gameplay",
			"DreamTeam/Variant_Combat/Interfaces",
			"DreamTeam/Variant_Combat/UI",
			"DreamTeam/Variant_SideScrolling",
			"DreamTeam/Variant_SideScrolling/AI",
			"DreamTeam/Variant_SideScrolling/Gameplay",
			"DreamTeam/Variant_SideScrolling/Interfaces",
			"DreamTeam/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
