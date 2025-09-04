#include "TurnManager.h"

#include "GameEntityData.h"
#include "SWarningOrErrorBox.h"
#include "Objects/GameEntity.h"
#include "Objects/RouletteGun.h"

UTurnManager::UTurnManager()
{
	EntityDataArray.Init(FGameEntityData(), 2);
}

// 게임의 사이클 시작하는
void UTurnManager::StartGame()
{
	//BulletInserter를 활성화 시켜주어야 함
	for (auto Entity : EntityDataArray)
	{
		//엔티티 전부 총알 장전 상태
		Entity.Entity->SetEntityState(EEntityState::SetBullet);
	}
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
void UTurnManager::AssignEntity(AGameEntity* Entity, int index)
{
	if (index < 0 || index >= EntityDataArray.Num())
	{
		UE_LOG(LogTemp, Warning, TEXT("Invalid index"));
		return;
	}

	EntityDataArray[index].Entity = Entity;
	EntityDataArray[index].RemainHealth = 5;
	EntityDataArray[index].MinRealBullet = 1;
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
