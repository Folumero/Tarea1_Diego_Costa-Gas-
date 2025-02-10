// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AbilitySystemComponent.h"
#include "CoreMinimal.h"
#include "UTHUB_ASC.generated.h"

UINTERFACE(NotBlueprintable)
class UGameplayTagCustomInterface : public UGameplayTagAssetInterface
{
	GENERATED_BODY()
};

class IGameplayTagCustomInterface : public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category="GameplayTags")
	virtual void AddTag(const FGameplayTag& InTag) = 0;

	UFUNCTION(BlueprintCallable, Category="GameplayTags")
	virtual void RemoveTag(const FGameplayTag& InTag) = 0;
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UTHUB_GAS2025_API UUTHUB_ASC : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	
	UUTHUB_ASC();

protected:
	
	virtual void BeginPlay() override;
	
public:

	virtual void InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor) override;

	void InitializeAttribute(AActor* InOwnerActor);
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
