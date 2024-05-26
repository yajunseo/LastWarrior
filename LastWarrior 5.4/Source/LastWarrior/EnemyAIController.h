// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class LASTWARRIOR_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	class UBehaviorTree* BT;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	class UBlackboardData* BB;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI, meta = (AllowPrivateAccess = "true"))
	class UBlackboardComponent* BBComponent;

public:
	AEnemyAIController();
	virtual void OnPossess(APawn* InPawn) override;
	
	static const FName HomePosKey;
	static const FName PatrolPosKey;
	static const FName TargetKey;
	
protected:
	virtual void BeginPlay() override;
};
