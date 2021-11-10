// Copyright Epic Games, Inc. All Rights Reserved.

#include "TPSTimeAttackGameMode.h"
#include "Characters/TPSTimeAttackCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATPSTimeAttackGameMode::ATPSTimeAttackGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
