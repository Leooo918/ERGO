#include "Objects/GameItem.h"
#include "Objects/GameEntity.h"

AGameEntity::AGameEntity()
{
 	PrimaryActorTick.bCanEverTick = true;
	CurrentState = EEntityState::None;
	Health = 0;
}

void AGameEntity::BeginPlay()
{
	Super::BeginPlay();
}

void AGameEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGameEntity::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AGameEntity::Initialize(ARouletteGun* gun)
{
	RouletteGun = gun;
}

void AGameEntity::UseItem(AGameItem* Item)
{
	Item->UseItem(this);
	OwnedItems.Remove(Item);
}

void AGameEntity::Attack(AGameEntity* target)
{
	target->GetAttacked();
}

