// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletInserter.generated.h"

class AGameEntity;

UCLASS()
class ERGO_API ABulletInserter : public AActor
{
	GENERATED_BODY()

public:
	ABulletInserter();

protected:
	virtual void BeginPlay() override;

public:
	void Initialize(AGameEntity* Entity) { Player = Entity; }
	void Enable(int maxBulletCount);


	virtual void GetReady();
	virtual void IncreaseBullet() { RealBulletCount++; }
	virtual void DecreaseBullet() { RealBulletCount--; }

protected:
	int TotalBulletCount;
	int RealBulletCount;
	TObjectPtr<AGameEntity> Player;
};
