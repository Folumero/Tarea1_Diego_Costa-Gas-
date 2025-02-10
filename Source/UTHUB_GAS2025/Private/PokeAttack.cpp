#include "PokeAttack.h"

float UPokeAttack::Attack(FGameplayTag TargetType, UDataTable* TypeCorrelationTable)
{
    if (RemainingUses <= 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No remaining uses for this attack!"));
        return 0.0f;
    }


    RemainingUses--;

    static const FString ContextString(TEXT("Type Correlation Context"));
    FTypeEffectiveness* CorrelationRow = TypeCorrelationTable->FindRow<FTypeEffectiveness>(AttackType.GetTagName(), ContextString);

    if (!CorrelationRow)
    {
        UE_LOG(LogTemp, Warning, TEXT("Attack type %s not found in correlation table!"), *AttackType.ToString());
        return 0.0f; 
    }


    float Effectiveness = 1.0f;

    if (CorrelationRow->VeryEffectiveAgainst.Contains(TargetType))
    {
        Effectiveness = 2.0f; 
    }
    else if (CorrelationRow->NotVeryEffectiveAgainst.Contains(TargetType))
    {
        Effectiveness = 0.5f; 
    }


    float FinalDamage = CorrelationRow->Damage * Effectiveness;

    UE_LOG(LogTemp, Log, TEXT("Attack of type %s dealt %f damage to target type %s"),
        *AttackType.ToString(), FinalDamage, *TargetType.ToString());

    return FinalDamage;
}
