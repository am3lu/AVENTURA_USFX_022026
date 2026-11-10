// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class AVENTURA_USFX_022026EditorTarget : TargetRules
{
	public AVENTURA_USFX_022026EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("AVENTURA_USFX_022026");
	}
}
