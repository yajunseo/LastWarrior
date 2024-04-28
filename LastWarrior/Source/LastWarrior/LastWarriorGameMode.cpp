// Copyright Epic Games, Inc. All Rights Reserved.

#include "LastWarriorGameMode.h"
#include "LastWarriorCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALastWarriorGameMode::ALastWarriorGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
