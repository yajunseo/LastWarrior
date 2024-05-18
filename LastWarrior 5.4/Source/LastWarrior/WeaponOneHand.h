// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "WeaponOneHand.generated.h"

/**
 * 
 */
UCLASS()
class LASTWARRIOR_API AWeaponOneHand : public AWeapon
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AWeaponOneHand();
	
private:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Component, meta = (AllowPrivateAccess = true))
	class USceneComponent* StartSceneComp = NULL;
	
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Component, meta = (AllowPrivateAccess = true))
	class USceneComponent* EndSceneComp = NULL;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Stat, meta = (AllowPrivateAccess = true))
	float CapsuleRadius = NULL;

public:
	FVector GetWeaponDamageStartPos();
	FVector GetWeaponDamageEndPos();
	float GetCapsuleRadius();
	
};
