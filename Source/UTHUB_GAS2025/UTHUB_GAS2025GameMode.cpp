// Copyright Epic Games, Inc. All Rights Reserved.

#include "UTHUB_GAS2025GameMode.h"
#include "UTHUB_GAS2025PlayerController.h"
#include "UTHUB_GAS2025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "GameplayStatesManager.h"

AUTHUB_GAS2025GameMode::AUTHUB_GAS2025GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AUTHUB_GAS2025PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != nullptr)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}

void AUTHUB_GAS2025GameMode::HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)
{
	Super::HandleStartingNewPlayer_Implementation(NewPlayer);

	//auto funcnae = __FUNCTION__;
	APawn* PlayerPawn = NewPlayer->GetPawn();

		//ensureMsgf(PlayerPawn,TEXT("AUTHUB_GAS2025GameMode::HandleStartingNewPlayer_Implementation- WE dont have a proper pawn initialized yet... Oh boy xd"));
		//ensureMsgf(PlayerPawn, TEXT(" %s WE dont have a proper pawn initialized yet... Oh boy xd"), ANSI_TO_TCHAR(__FUNTION__));

		UUTHUB_ASC* ASC = PlayerPawn->FindComponentByClass<UUTHUB_ASC>();
			if(ASC)
			{
				auto& Delegate=ASC->RegisterGameplayTagEvent(FGameplayStatesManager::Get().Tag_InteractEnabled);
				Delegate.AddUObject(this, &ThisClass::CharacterIsAllowedToTicteract);
				 //Delegate = ASC->RegisterGameplayTagEvent(FGameplayStatesManager::Get().Tag_InteractEnabled);


			}



	
}

void AUTHUB_GAS2025GameMode::CharacterIsAllowedToTicteract(FGameplayTag GameplayTag, int Count)
{
	UE_LOG(LogTemp, Display, TEXT("NOW I can interact!!!"));
}
