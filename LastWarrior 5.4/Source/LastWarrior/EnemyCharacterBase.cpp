// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacterBase.h"

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

void AEnemyCharacterBase::Attack()
{
	UE_LOG(LogTemp, Warning, TEXT("ATTACK"));

	GetWorld()->GetTimerManager().SetTimer(TestTimerHandle, this, &AEnemyCharacterBase::TestAttackEnd, 2.0f, false);
}

void AEnemyCharacterBase::TestAttackEnd()
{
	OnAttackEnd.Broadcast();
}
