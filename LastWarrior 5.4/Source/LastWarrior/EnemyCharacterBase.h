// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimationAttackInterface.h"
#include "EnemyAnimInstance.h"
#include "GameFramework/Character.h"
#include "EnemyCharacterBase.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAttackEndDelegate);

UCLASS()
class LASTWARRIOR_API AEnemyCharacterBase : public ACharacter, public IAnimationAttackInterface
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class AWeapon> Weapon;
	
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

	virtual void AttackHitCheck() override;
	virtual void AttackHitCheckEnd() override;
	virtual void AttackMotionEnd() override;

	bool IsAttack = false;
	bool HitCheckOn = false;
	void Attack();
	FOnAttackEndDelegate OnAttackEnd;

	void SetWeapon();
private:
	UEnemyAnimInstance* Anim = nullptr;

	UPROPERTY()
	AWeapon* WeaponInstance = nullptr;
};
