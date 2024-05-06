// Fill out your copyright notice in the Description page of Project Settings.


#include "LastWarriorAnimInstance.h"

void ULastWarriorAnimInstance::AnimNotify_NextAttackCheck()
{
	OnNextAttackCheck.Broadcast();
}

void ULastWarriorAnimInstance::AnimNotify_ResetAttackCombo()
{
	OnResetAttackComboCehck.Broadcast();
}

int32 ULastWarriorAnimInstance::GetAttackComboCnt()
{
	if(AttackMontage == nullptr)
		return 0;

	return AttackMontage->GetNumSections();
}

UAnimMontage* ULastWarriorAnimInstance::GetAttackMontage()
{
	return AttackMontage;
}

FName ULastWarriorAnimInstance::GetAttackMontageSectionName(int32 Section)
{
	return FName(*FString::Printf(TEXT("Attack%d"), Section));
}

void ULastWarriorAnimInstance::JumpToAttackMontageSection(int32 NewSection)
{
	if(AttackMontage == nullptr)
		return;
	
	Montage_JumpToSection(GetAttackMontageSectionName(NewSection), AttackMontage);
}

