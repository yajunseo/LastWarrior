// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	WT_None UMETA(DisplayName = "None"),
	WT_OneHand UMETA(DisplayName = "OneHand"),
};

UCLASS()
class LASTWARRIOR_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = Component, meta = (AllowPrivateAccess = true))
	class USkeletalMeshComponent* MeshComp = NULL;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = State, meta = (AllowPrivateAccess = true))
	float Damage = 0.0f;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Socket, meta = (AllowPrivateAccess = true))
	FName WeaponSoket = TEXT("hand_rSocket");

	EWeaponType WeaponType = EWeaponType::WT_None;
	
public:
	void SetWeaponSocketName(FName SocketName);
	float GetDamage();
	FName GetWeaponAttachSocketName();
	EWeaponType GetWeaponType();
};
