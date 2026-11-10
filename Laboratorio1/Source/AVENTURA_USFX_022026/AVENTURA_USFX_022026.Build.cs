// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AVENTURA_USFX_022026 : ModuleRules
{
	public AVENTURA_USFX_022026(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
