// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GameMode/TP_ThirdPersonGameMode.h"
#include "Character/TP_ThirdPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATP_ThirdPersonGameMode::ATP_ThirdPersonGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Character/BP_Character")); 
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
