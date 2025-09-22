// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/Entity/ER_Enemy.h"

#include "Core/TurnManager.h"

void AER_Enemy::BeginPlay()
{
	Super::BeginPlay();
	GetGameInstance()->GetSubsystem<UTurnManager>()->AssignEntity(this, EEntityType::Enemy);	//적으로 할당
}
