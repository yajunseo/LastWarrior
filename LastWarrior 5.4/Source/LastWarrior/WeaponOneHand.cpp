// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponOneHand.h"

#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AWeaponOneHand::AWeaponOneHand()
{
	StartSceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("StartPos"));
	EndSceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("EndPos"));
	
	FVector DamageDirectVector = GetWeaponDamageEndPos() - GetWeaponDamageStartPos();
}

FVector AWeaponOneHand::GetWeaponDamageStartPos()
{
	return StartSceneComp->GetComponentLocation();
}

FVector AWeaponOneHand::GetWeaponDamageEndPos()
{
	return EndSceneComp->GetComponentLocation();
}
