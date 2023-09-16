using UnrealBuildTool;
using System.Collections.Generic;

[SupportedPlatforms(UnrealPlatformClass.Server)]
public class PingPongServerTarget : TargetRules
{
	public PingPongServerTarget( TargetInfo target) : base(target)
	{
		Type = TargetType.Server;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "PingPongTestProject" } );
	}
}