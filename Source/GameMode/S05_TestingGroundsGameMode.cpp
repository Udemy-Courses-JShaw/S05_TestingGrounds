// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GameMode/S05_TestingGroundsGameMode.h"
#include "HUD/S05_TestingGroundsHUD.h"
#include "Character/S05_TestingGroundsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AS05_TestingGroundsGameMode::AS05_TestingGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Character/BP_Character")); 
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AS05_TestingGroundsHUD::StaticClass();
}
