// Copyright Epic Games, Inc. All Rights Reserved.

#include "AVENTURA_USFX_022026GameMode.h"
#include "AVENTURA_USFX_022026Pawn.h"

AAVENTURA_USFX_022026GameMode::AAVENTURA_USFX_022026GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AAVENTURA_USFX_022026Pawn::StaticClass();
}

