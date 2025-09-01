// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"

#include "EngineUtils.h"
#include "TurnManager.h"
#include "Objects/GameEntity.h"
#include "GameEntityData.h"

AGameManager::AGameManager()
{
	OriginMinRealBulletCount = 0;
	EntityOriginHealth = 5;
}

void AGameManager::BeginPlay()
{
	Super::BeginPlay();

	UClass* TurnManagerClass = LoadClass<ATurnManager>(
		nullptr, TEXT("/Script/Engine.Blueprint'/Game/BP/TurnManager.BP_TurnManager_C"));
	if (TurnManagerClass)
	{
		CurrentTurnManager = GetWorld()->SpawnActor<ATurnManager>(TurnManagerClass, FVector::ZeroVector,
		                                                          FRotator::ZeroRotator);
	}

	if (CurrentTurnManager)
	{
		CurrentTurnManager->EntityArray.Empty();
		
		for (TActorIterator<AGameEntity> It(GetWorld()); It; ++It)
		{
			AGameEntity* Entity = *It;
			if (Entity)
			{
				FGameEntityData data;
				data.Entity = Entity;
				data.MinRealBullet = OriginMinRealBulletCount;
				data.RemainHealth = EntityOriginHealth;
				
				CurrentTurnManager->EntityArray.Add(data);
			}
		}
	}
}
