// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameplayTagContainer.h"
#include "UTHUB_GAS2025GameMode.generated.h"

UCLASS(minimalapi)
class AUTHUB_GAS2025GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUTHUB_GAS2025GameMode();
protected:

	

	virtual void HandleStartingNewPlayer_Implementation(APlayerController* NewPlayer)override;


private: 
	void CharacterIsAllowedToTicteract(FGameplayTag GameplayTag, int Count);

private:
	
};



