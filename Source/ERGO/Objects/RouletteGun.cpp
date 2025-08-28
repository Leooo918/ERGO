// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/RouletteGun.h"

// Sets default values
ARouletteGun::ARouletteGun()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BulletCount = 0;
}

// Called when the game starts or when spawned
void ARouletteGun::BeginPlay()
{
	Super::BeginPlay();

	BulletCount = 0;
}

// Called every frame
void ARouletteGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARouletteGun::SetBullet(int fakeCount, int realCount)
{
	int remainFake = fakeCount;
	int remainReal = realCount;
	
	for (int i = 0; i < fakeCount + realCount; i++)
	{
		if (remainFake == 0)
		{
			BulletTypes.push(true);
			remainReal--;
			continue;
		}
		if (remainReal == 0)
		{
			BulletTypes.push(false);
			remainFake--;
			continue;
		}
		
		bool isReal = FMath::RandBool();
		
		BulletTypes.push(isReal);
		
		if (isReal) --remainReal;
		else --remainFake;
	}
}
