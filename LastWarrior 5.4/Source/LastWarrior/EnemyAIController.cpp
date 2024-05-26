// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

#include "BehaviorTree/BlackboardComponent.h"

const FName AEnemyAIController::HomePosKey(TEXT("HomePos"));
const FName AEnemyAIController::PatrolPosKey(TEXT("PatrolPos"));
const FName AEnemyAIController::TargetKey(TEXT("Target"));

AEnemyAIController::AEnemyAIController()
{
	BBComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoard Component"));
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if(UseBlackboard(BB, BBComponent))
	{
		Blackboard->SetValueAsVector(HomePosKey, InPawn->GetActorLocation());
		RunBehaviorTree(BT);
	}
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();
}
