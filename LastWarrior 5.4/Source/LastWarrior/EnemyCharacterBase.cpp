// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacterBase.h"
#include "Weapon.h"
#include "WeaponOneHand.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values
AEnemyCharacterBase::AEnemyCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	Anim = Cast<UEnemyAnimInstance>(GetMesh()->GetAnimInstance());
	SetWeapon();
}

// Called every frame
void AEnemyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AEnemyCharacterBase::GetHP()
{
	return HP;
}

float AEnemyCharacterBase::GetDetectRange()
{
	return DetectRange;
}

float AEnemyCharacterBase::GetAttackRange()
{
	return AttackRange;
}

void AEnemyCharacterBase::TakeDamage(float Damage)
{
	if(HP > 0.0f)
	{
		HP = FMath::Clamp(HP - Damage, 0.0f, HP);
	}
}

void AEnemyCharacterBase::AttackHitCheck()
{
	HitCheckOn = true;
}

void AEnemyCharacterBase::AttackHitCheckEnd()
{
	HitCheckOn = false;
}

void AEnemyCharacterBase::AttackMotionEnd()
{
	IsAttack = false;
	OnAttackEnd.Broadcast();
}

void AEnemyCharacterBase::Attack()
{
	if(Anim == nullptr)
		return;

	if(IsAttack)
		return;
	
	IsAttack = true;
	Anim->Montage_Play(Anim->GetNormalAttackMontage());
}

void AEnemyCharacterBase::SetWeapon()
{
	if(Weapon == nullptr)
		return;
	
	auto CreateWeapon = GetWorld()->SpawnActor<AWeapon>(Weapon);
	if(CreateWeapon != nullptr)
	{
		CreateWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, CreateWeapon->GetWeaponAttachSocketName());
		WeaponInstance = CreateWeapon;
	}
}
