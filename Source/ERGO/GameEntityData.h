// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include  "GameEntityData.generated.h"

USTRUCT(Atomic, BlueprintType)
struct FGameEntityData
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<class AGameEntity> Entity;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<class AGameItem>> ContainItemArray;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int RemainHealth;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MinRealBullet;
};

struct ERGO_API GameEntityData
{
public:
	GameEntityData();
	~GameEntityData();
};
