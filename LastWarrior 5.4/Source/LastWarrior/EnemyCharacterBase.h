// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyCharacterBase.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAttackEndDelegate);

UCLASS()
class LASTWARRIOR_API AEnemyCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = STAT, meta = (AllowPrivateAccess = "true"))
	float HP;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = STAT, meta = (AllowPrivateAccess = "true"))
	float DetectRange = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = STAT, meta = (AllowPrivateAccess = "true"))
	float AttackRange = 200.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	TArray<FVector> PatrolPoints;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float GetHP();
	float GetDetectRange();
	float GetAttackRange();
	
	UFUNCTION(BlueprintCallable)
	void TakeDamage(float Damage);

	void Attack();
	FOnAttackEndDelegate OnAttackEnd;

private:
	FTimerHandle TestTimerHandle;
	void TestAttackEnd();
};
