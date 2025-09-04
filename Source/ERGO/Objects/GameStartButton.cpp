#include "Objects/GameStartButton.h"
#include "Core/GameManager.h"
#include "GameEntity.h"
#include "Core/TurnManager.h"

AGameStartButton::AGameStartButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AGameStartButton::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGameStartButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGameStartButton::OnInteract(AGameEntity* target)
{
	//게임 시작
	GetGameInstance()->GetSubsystem<UTurnManager>()->StartGame();
}