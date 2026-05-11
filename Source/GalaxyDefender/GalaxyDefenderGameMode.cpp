// Copyright Epic Games, Inc. All Rights Reserved.

#include "GalaxyDefenderGameMode.h"
#include "GalaxyDefenderPawn.h"

AGalaxyDefenderGameMode::AGalaxyDefenderGameMode()
{
	// set default pawn class to our flying pawn
	DefaultPawnClass = AGalaxyDefenderPawn::StaticClass();
}
