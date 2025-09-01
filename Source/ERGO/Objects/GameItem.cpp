#include "Objects/GameItem.h"

AGameItem::AGameItem()
{
 	PrimaryActorTick.bCanEverTick = true;

}

void AGameItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGameItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameItem::OnInteract(AGameEntity* target)
{
	UseItem(target); 
}
