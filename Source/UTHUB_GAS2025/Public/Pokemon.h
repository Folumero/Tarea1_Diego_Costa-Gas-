#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "PokeAttack.h"
#include "Pokemon.generated.h"

UCLASS(Blueprintable)
class UTHUB_GAS2025_API APokemon : public AActor
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pokemon")
    FGameplayTag PokemonType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pokemon")
    TArray<UPokeAttack*> Attacks;

    UFUNCTION(BlueprintCallable, Category = "Pokemon")
    void InitializeAttacks(UDataTable* AttackDataTable);


protected:
    virtual void BeginPlay() override;
};

