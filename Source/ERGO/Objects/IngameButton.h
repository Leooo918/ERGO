// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "GameFramework/Actor.h"
#include "IngameButton.generated.h"

UCLASS()
class ERGO_API AIngameButton : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:
	virtual void OnInteract(AGameEntity* target) override;
};
