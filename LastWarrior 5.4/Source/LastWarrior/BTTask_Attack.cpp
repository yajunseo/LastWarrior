// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"

#include "AIController.h"
#include "EnemyCharacterBase.h"

UBTTask_Attack::UBTTask_Attack()
{
	bNotifyTick = true;
	IsAttacking = false;
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result =  Super::ExecuteTask(OwnerComp, NodeMemory);

	AEnemyCharacterBase* Enemy = Cast<AEnemyCharacterBase>(OwnerComp.GetAIOwner()->GetPawn());
	if(Enemy == nullptr)
		return EBTNodeResult::Failed;
	
	Enemy->Attack();
	IsAttacking = true;
	Enemy->OnAttackEnd.AddLambda([this]() -> void
	{
		IsAttacking= false;
	});
	
	return EBTNodeResult::InProgress;
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	if(!IsAttacking)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}
