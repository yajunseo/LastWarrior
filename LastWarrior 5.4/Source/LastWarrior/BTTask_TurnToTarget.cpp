// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_TurnToTarget.h"

#include "AIController.h"
#include "EnemyAIController.h"
#include "EnemyCharacterBase.h"
#include "LastWarriorCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_TurnToTarget::UBTTask_TurnToTarget()
{
	NodeName = TEXT("Turn");
}

EBTNodeResult::Type UBTTask_TurnToTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	AEnemyCharacterBase* Enemy = Cast<AEnemyCharacterBase>(OwnerComp.GetAIOwner()->GetPawn());
	if(Enemy == nullptr)
		return EBTNodeResult::Failed;

	auto Target = Cast<ALastWarriorCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AEnemyAIController::TargetKey));
	if(Target == nullptr)
		return EBTNodeResult::Failed;

	FVector LookVector = Target->GetActorLocation() - Enemy->GetActorLocation();
	LookVector.Z = 0.0f;
	FRotator TargetRot = FRotationMatrix::MakeFromX(LookVector).Rotator();
	Enemy->SetActorRotation(FMath::RInterpTo(Enemy->GetActorRotation(), TargetRot, GetWorld()->GetDeltaSeconds(), 2.0f));

	return EBTNodeResult::Succeeded;
}
