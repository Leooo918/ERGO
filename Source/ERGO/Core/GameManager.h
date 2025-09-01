// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameEntityData.h"
#include "GameFramework/GameModeBase.h"
#include "GameManager.generated.h"

/**
 * 
 */
UCLASS()
class ERGO_API AGameManager : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameManager();
	virtual void BeginPlay() override;
	
public:
	int EntityOriginHealth;
	int OriginMinRealBulletCount;
	TObjectPtr<class ATurnManager> CurrentTurnManager;
	TArray<FGameEntityData> EntityArray;
};
