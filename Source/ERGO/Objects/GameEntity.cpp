#include "Objects/GameEntity.h"
#include "Objects/GameItem.h"
#include "Objects/RouletteGun.h"

AGameEntity::AGameEntity()
{
 	PrimaryActorTick.bCanEverTick = true;
	CurrentState = EEntityState::None;
}

void AGameEntity::Initialize(ARouletteGun* gun)
{
	RouletteGun = gun;
}

void AGameEntity::UseItem(AGameItem* Item)
{
	Item->UseItem(this);
}

void AGameEntity::Attack(AGameEntity* target)
{
	RouletteGun->Shoot(target);
	//뭐 턴 넘기기 그런거 해줘야 하면;;;
}

