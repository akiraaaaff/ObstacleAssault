// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class ObstacleAssaultEditorTarget : TargetRules
{
	public ObstacleAssaultEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
        bOverrideBuildEnvironment = true;

		ExtraModuleNames.AddRange( new string[] { "ObstacleAssault" } );
	}
}
