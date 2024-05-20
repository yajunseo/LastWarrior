// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

#include "BehaviorTree/BlackboardComponent.h"

AEnemyAIController::AEnemyAIController()
{
	BBComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoard Component"));
}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	if(BT != nullptr && BB != nullptr)
	{
		RunBehaviorTree(BT);
		UseBlackboard(BB, BBComponent);
	}
}
