// Copyright Epic Games, Inc. All Rights Reserved.

#include "AiConGameMode.h"
#include "AiConCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAiConGameMode::AAiConGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
