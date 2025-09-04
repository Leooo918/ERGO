// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/IngameButton.h"


void AIngameButton::OnInteract(AGameEntity* target)
{
	InteractAction.ExecuteIfBound();
}
