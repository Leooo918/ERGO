// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Objects/GameEntity.h"
#include "ER_Enemy.generated.h"

/**
 * 
 */
UCLASS()
class ERGO_API AER_Enemy : public AGameEntity
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
};
