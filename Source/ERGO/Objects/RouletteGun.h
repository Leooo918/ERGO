// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include "CoreMinimal.h"
#include "Interactable.h"
#include "GameFramework/Actor.h"
#include "RouletteGun.generated.h"

UCLASS()
class ERGO_API ARouletteGun : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	ARouletteGun();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	bool GetCurrentBullet();
	void Shoot(class AGameEntity* Target);
	void SetBullet(int FakeCount, int RealCount);

	void SetDamage(int Value) { Damage = Value; }
	void SetBulletCount(int Count) { BulletCount = Count; }

public:
	bool IsEmpty() { return BulletTypes.empty(); }
	bool GetBulletType(int Index) { return BulletTypes[Index]; }
	int GetTotalBulletCount() { return BulletCount; }
	int GetRemainBulletCount() { return BulletTypes.size(); }

public:
	virtual void OnInteract(AGameEntity* target) override;
	
protected:
	int BulletCount;
	int Damage = 1;

	//If true real, false fake
	std::vector<bool> BulletTypes;
};
