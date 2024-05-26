// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_Detect.h"

#include "AIController.h"
#include "EnemyAIController.h"
#include "EnemyCharacterBase.h"
#include "LastWarriorCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTService_Detect::UBTService_Detect()
{
	NodeName = TEXT("Detect");
	Interval = 1.0f;
}

void UBTService_Detect::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if(ControllingPawn == nullptr)
		return;

	UWorld* World = ControllingPawn->GetWorld();
	if(World == nullptr)
		return;
	
	FVector Center = ControllingPawn->GetActorLocation();
	AEnemyCharacterBase* Enemy = Cast<AEnemyCharacterBase>(ControllingPawn);
	if(Enemy == nullptr)
		return;

	float DetectRange = Enemy->GetDetectRange();

	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		ECC_EngineTraceChannel2,
		FCollisionShape::MakeSphere(DetectRange),
		CollisionQueryParam
	);

	if(bResult)
	{
		for (auto const& OverlapResult : OverlapResults)
		{
			ALastWarriorCharacter* Warrior = Cast<ALastWarriorCharacter>(OverlapResult.GetActor());
			if (Warrior && Warrior->GetController()->IsPlayerController())
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(AEnemyAIController::TargetKey, Warrior);
				
				DrawDebugSphere(World, Center, DetectRange, 16, FColor::Green, false, 0.2f);
				DrawDebugPoint(World, Warrior->GetActorLocation(), 10.0f, FColor::Blue, false, 0.2f);
				DrawDebugLine(World, ControllingPawn->GetActorLocation(), Warrior->GetActorLocation(), FColor::Blue, false, 0.2f);
				return;
			}
		}
	}
	
	DrawDebugSphere(World, Center, DetectRange, 16, FColor::Red, false, 0.2);
}
