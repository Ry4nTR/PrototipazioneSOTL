// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PrototipazioneSOTL : ModuleRules
{
	public PrototipazioneSOTL(ReadOnlyTargetRules Target) : base(Target)
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
			"UMG"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"PrototipazioneSOTL",
			"PrototipazioneSOTL/Variant_Platforming",
			"PrototipazioneSOTL/Variant_Combat",
			"PrototipazioneSOTL/Variant_Combat/AI",
			"PrototipazioneSOTL/Variant_SideScrolling",
			"PrototipazioneSOTL/Variant_SideScrolling/Gameplay",
			"PrototipazioneSOTL/Variant_SideScrolling/AI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
