// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TPSTimeAttack : ModuleRules
{
	public TPSTimeAttack(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });

        PublicIncludePaths.Add(ModuleDirectory);
        PrivateIncludePaths.Add(ModuleDirectory);
    }
}
