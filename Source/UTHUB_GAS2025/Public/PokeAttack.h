#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataTable.h"
#include "PokeAttack.generated.h"


USTRUCT(BlueprintType)
struct FTypeEffectiveness : public FTableRowBase
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Type")
    FGameplayTag AttackType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Type")
    TArray<FGameplayTag> VeryEffectiveAgainst;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Type")
    TArray<FGameplayTag> NotVeryEffectiveAgainst;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Type")
    float Damage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Type")
    int32 RemainingUsesTable;

};


UCLASS(Blueprintable)
class UTHUB_GAS2025_API UPokeAttack : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
    FGameplayTag AttackType;

    /**UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
    float Damage;*/

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
    int32 RemainingUses;

    UFUNCTION(BlueprintCallable, Category = "Attack")
    float Attack(FGameplayTag TargetType, UDataTable* TypeCorrelationTable);
};
