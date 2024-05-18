// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponOneHand.h"

#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AWeaponOneHand::AWeaponOneHand()
{
	StartSceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("StartPos"));
	StartSceneComp->SetupAttachment(RootComponent);
	EndSceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("EndPos"));
	EndSceneComp->SetupAttachment(RootComponent);
	
	FVector DamageDirectVector = GetWeaponDamageEndPos() - GetWeaponDamageStartPos();

	WeaponType = EWeaponType::WT_OneHand;
}

FVector AWeaponOneHand::GetWeaponDamageStartPos()
{
	return StartSceneComp->GetComponentToWorld().GetLocation();
}

FVector AWeaponOneHand::GetWeaponDamageEndPos()
{
	return EndSceneComp->GetComponentToWorld().GetLocation();
}

float AWeaponOneHand::GetCapsuleRadius()
{
	return CapsuleRadius;
}