#include "TurnManager.h"

#include "GameEntityData.h"
#include "Objects/GameEntity.h"
#include "Objects/RouletteGun.h"


UTurnManager::UTurnManager()
{
	EntityDataArray.Init(FGameEntityData(), 2);
}

// 게임의 사이클 시작하는
void UTurnManager::StartGame()
{
	//게임이 준비되어야만 시작
	if (IsGameReady == false) return;

	//우선 총 장전이 가능한 상태로 만들어
	EntityDataArray[0].Entity->SetEntityState(EEntityState::SetBullet);
	EntityDataArray[1].Entity->SetEntityState(EEntityState::SetBullet);
}


void UTurnManager::StartRoulette(int MaxBulletCount, int RealBulletCount)
{
	if (EntityDataArray.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("EntityArray Is Empty"));
		return;
	}

	for (auto& Entity : EntityDataArray)
	{
		auto* Gun = Entity.Entity->GetGun();
		Gun->SetBulletCount(MaxBulletCount);

		//나중에는 직접 정할 수 있도록 바꾸기
		int Count = FMath::RandRange(0, MaxBulletCount);
		Gun->SetBullet(Count, MaxBulletCount - Count);
	}

	//순서 정하는 방식은 나중에 정하기
	EntityDataArray[0].Entity->SetEntityState(EEntityState::SetBullet);
}

void UTurnManager::EndRoulette()
{
	
}

void UTurnManager::ChangeTurn()
{
	// 원래 턴 이었던 애는 턴을 넘기고 다음 애 턴으로 넘기기
	FGameEntityData Prev = EntityDataArray[CurrentTurn];
	Prev.Entity->SetEntityState(EEntityState::None);
	
	if (++CurrentTurn >= EntityDataArray.Num())
		CurrentTurn = 0;
	
	FGameEntityData Current = EntityDataArray[CurrentTurn];
	Current.Entity->SetEntityState(EEntityState::UsingItem);

	ChangeTurnAction.ExecuteIfBound(Prev, Current);
}

//0 = Player, 1 = AI
void UTurnManager::AssignEntity(AGameEntity* Entity, EEntityType entityType)
{
	EntityDataArray[entityType].Entity = Entity;
	EntityDataArray[entityType].RemainHealth = 5;
	EntityDataArray[entityType].MinRealBullet = 1;

	//0, 1 전부 할당될 시 게임 시작 가능
	if (EntityDataArray[0].Entity != nullptr && EntityDataArray[1].Entity != nullptr)
	{
		IsGameReady = true;
	}
}



FGameEntityData UTurnManager::GetEntityData(class AGameEntity* Entity)
{
	for (auto EntityData : EntityDataArray)
	{
		if (EntityData.Entity == Entity)
		{
			return EntityData;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("TurnManager.GetEntityData() Entity is wrong"));
	return FGameEntityData();
}
