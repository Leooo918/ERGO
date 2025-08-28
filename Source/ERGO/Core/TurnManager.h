// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TurnManager.generated.h"

class AGameEntity;

UCLASS()
class ERGO_API ATurnManager : public AActor
{
	GENERATED_BODY()

public:
	ATurnManager();

protected:
	virtual void BeginPlay() override;

public:
	void StartRoulette(int maxBulletCount);
	void
	
protected:
	int CurrentTurn = 0;
	UPROPERTY(BlueprintReadWrite)
	TArray<TObjectPtr<AGameEntity>> EntityArray;
	UPROPERTY(BlueprintReadWrite)
	TArray<TObjectPtr<ARouletteGun>> GunArray;
};
