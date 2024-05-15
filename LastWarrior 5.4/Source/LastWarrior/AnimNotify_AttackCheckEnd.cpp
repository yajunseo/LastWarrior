// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_AttackCheckEnd.h"

#include "AnimationAttackInterface.h"

void UAnimNotify_AttackCheckEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                        const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if(MeshComp)
	{
		IAnimationAttackInterface* AttackPawn = Cast<IAnimationAttackInterface>(MeshComp->GetOwner());
		if(AttackPawn)
		{
			AttackPawn->AttackHitCheckEnd();
		}
	}
}
