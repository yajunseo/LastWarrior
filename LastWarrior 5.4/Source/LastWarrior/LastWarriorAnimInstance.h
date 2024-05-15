// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "LastWarriorAnimInstance.generated.h"

//다음 공격 체크 딜리게이트
DECLARE_MULTICAST_DELEGATE(FOnNextAttackCheckDelegate);
//콤보 리셋 딜리게이트
DECLARE_MULTICAST_DELEGATE(FOnResetAttackComboDelegate);

/**
 * 
 */
UCLASS()
class LASTWARRIOR_API ULastWarriorAnimInstance : public UAnimInstance
{
	GENERATED_BODY()


public:
	FOnNextAttackCheckDelegate OnNextAttackCheck;
	FOnResetAttackComboDelegate OnResetAttackComboCehck;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Montage, meta = (AllowPrivateAccess = "true"))
	UAnimMontage* AttackMontage;
	
private:
	UFUNCTION()
	void AnimNotify_NextAttackCheck();
	UFUNCTION()
	void AnimNotify_ResetAttackCombo();

public:
	int32 GetAttackComboCnt();
	UAnimMontage* GetAttackMontage();
	FName GetAttackMontageSectionName(int32 Section);
	void JumpToAttackMontageSection(int32 NewSection);

};
