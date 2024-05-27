// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_IsInAttackRange.h"

#include "AIController.h"
#include "EnemyAIController.h"
#include "EnemyCharacterBase.h"
#include "LastWarriorCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_IsInAttackRange::UBTDecorator_IsInAttackRange()
{
	NodeName = TEXT("CanAttack");
}

bool UBTDecorator_IsInAttackRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);

	AEnemyCharacterBase* Enemy = Cast<AEnemyCharacterBase>(OwnerComp.GetAIOwner()->GetPawn());
	if(Enemy == nullptr)
		return false;

	auto Target = Cast<ALastWarriorCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AEnemyAIController::TargetKey));
	if(Target == nullptr)
		return false;

	bResult = (Target->GetDistanceTo(Enemy) <= Enemy->GetAttackRange());
	return bResult;
}
