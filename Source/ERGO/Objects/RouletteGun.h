// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include  <stack>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RouletteGun.generated.h"

UCLASS()
class ERGO_API ARouletteGun : public AActor
{
	GENERATED_BODY()

public:
	ARouletteGun();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	bool IsEmpty() { return BulletTypes.empty(); }
	bool GetCurrentBullet() { return BulletTypes.top(); }

	void SetBullet(int fakeCount, int realCount);
	void SetBulletCount(int Count) { BulletCount = Count; }
	int GetTotalBulletCount() { return BulletCount; }
	int GetRemainBulletCount() { return BulletTypes.size(); }

public:

protected:
	int BulletCount;
	
	//If true real, false fake
	std::stack<bool> BulletTypes;
};
