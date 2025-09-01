#include "TurnManager.h"

#include "GameEntityData.h"
#include "Objects/GameEntity.h"
#include "Objects/RouletteGun.h"

ATurnManager::ATurnManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATurnManager::BeginPlay()
{
	Super::BeginPlay();
}

void ATurnManager::Initialize()
{
}

void ATurnManager::StartRoulette(int MaxBulletCount)
{
	if (EntityArray.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("EntityArray Is Empty"));
		return;
	}

	for (auto& Entity : EntityArray)
	{
		auto* Gun = Entity.Entity->GetGun();
		Gun->SetBulletCount(MaxBulletCount);

		//나중에는 직접 정할 수 있도록 바꾸기
		int Count = FMath::RandRange(0, MaxBulletCount);
		Gun->SetBullet(Count, MaxBulletCount - Count);
	}

	//순서 정하는 방식은 나중에 정하기
	EntityArray[0].Entity->SetEntityState(EEntityState::SetBullet);
}

void ATurnManager::ChangeTurn()
{
	// 원래 턴 이었던 애는 턴을 넘기고 다음 애 턴으로 넘기기
	FGameEntityData Prev = EntityArray[CurrentTurn];
	Prev.Entity->SetEntityState(EEntityState::None);
	
	if (++CurrentTurn >= EntityArray.Num())
		CurrentTurn = 0;
	
	FGameEntityData Current = EntityArray[CurrentTurn];
	Current.Entity->SetEntityState(EEntityState::UsingItem);

	ChangeTurnAction.ExecuteIfBound(Prev, Current);
}

void ATurnManager::EndRoulette()
{
}
