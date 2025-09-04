// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/BulletInserter.h"

#include "Core/TurnManager.h"

// Sets default values
ABulletInserter::ABulletInserter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABulletInserter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABulletInserter::Enable(int maxBulletCount)
{
	TotalBulletCount = maxBulletCount;
	RealBulletCount = GetGameInstance()->GetSubsystem<UTurnManager>()->GetEntityData(Player).MinRealBullet;

	//뭔가 그거 해줘야함 실제로 보인느거?
}

void ABulletInserter::GetReady()
{
	GetGameInstance()->GetSubsystem<UTurnManager>()
	->StartRoulette(TotalBulletCount, RealBulletCount);
}



