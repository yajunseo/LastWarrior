// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"

#include "Components/CapsuleComponent.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeltalMesh Component"));
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::SetWeaponSocketName(FName SocketName)
{
	WeaponSoket = SocketName;
}

float AWeapon::GetDamage()
{
	return Damage;
}

FName AWeapon::GetWeaponAttachSocketName()
{
	return WeaponSoket;
}

EWeaponType AWeapon::GetWeaponType()
{
	return WeaponType;
}

