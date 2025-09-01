// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/Item/DoubleDamageSaw.h"
#include "Objects/RouletteGun.h"
#include "Objects/GameEntity.h"

void ADoubleDamageSaw::UseItem(AGameEntity* target)
{
	ARouletteGun* gun = target->GetGun();
	if (gun)
	{
		gun->SetDamage(2);
	}
	UE_LOG(LogTemp, Display, TEXT("MING"));
}
