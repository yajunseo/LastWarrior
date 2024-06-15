// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_AttackMotionEnd.h"

#include "AnimationAttackInterface.h"

void UAnimNotify_AttackMotionEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                         const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if(MeshComp != nullptr)
	{
		IAnimationAttackInterface* AttackPawn = Cast<IAnimationAttackInterface>(MeshComp->GetOwner());
		if(AttackPawn != nullptr)
		{
			AttackPawn->AttackMotionEnd();
		}
	}
}
