// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AiCon : ModuleRules
{
	public AiCon(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
