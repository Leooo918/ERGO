// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "GameFramework/Actor.h"
#include "GameStartButton.generated.h"

UCLASS()
class ERGO_API AGameStartButton : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	AGameStartButton();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void OnInteract(class AGameEntity* target) override;

	
};
