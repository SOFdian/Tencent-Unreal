// Copyright Epic Games, Inc. All Rights Reserved.

#include "RougelikeGameMode.h"
#include "RougelikeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARougelikeGameMode::ARougelikeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
