#include "Pokemon.h"
#include "PokeAttack.h"


void APokemon::InitializeAttacks(UDataTable* AttackDataTable)
{

    Attacks.Empty();

    static const FString ContextString(TEXT("Loading Attacks from DataTable"));
    TArray<FName> RowNames = AttackDataTable->GetRowNames();

    int32 MaxAttacks = FMath::Min(4, RowNames.Num());

    for (int32 i = 0; i < MaxAttacks; i++)
    {
        FName RowName = RowNames[i];
        FTypeEffectiveness* AttackData = AttackDataTable->FindRow<FTypeEffectiveness>(RowName, ContextString);

        if (AttackData)
        {

            UPokeAttack* NewAttack = NewObject<UPokeAttack>(this);
            if (NewAttack)
            {
                NewAttack->AttackType = AttackData->AttackType;
                NewAttack->RemainingUses = AttackData->RemainingUsesTable;
                Attacks.Add(NewAttack);

                UE_LOG(LogTemp, Log, TEXT("Added attack: %s"), *AttackData->AttackType.ToString());
            }
        }
    }

    UE_LOG(LogTemp, Log, TEXT("Finished initializing attacks. Total attacks assigned: %d"), Attacks.Num());
}



void APokemon::BeginPlay()
{
    Super::BeginPlay();

    if (Attacks.Num() > 4)
    {
        Attacks.SetNum(4);
        UE_LOG(LogTemp, Warning, TEXT("Pokemon had more than 4 attacks. Extra attacks were removed."));
    }
}
