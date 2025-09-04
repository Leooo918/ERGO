#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameEntityData.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TurnManager.generated.h"

class AGameEntity;
class ARouletteGun;

DECLARE_DELEGATE_TwoParams(OnChangeTurn, FGameEntityData, FGameEntityData);

UCLASS()
class ERGO_API UTurnManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UTurnManager();

public:
	void StartGame();
	void StartRoulette(int MaxBulletCount, int RealBulletCount);
	void EndRoulette();
	void ChangeTurn();
	void AssignEntity(AGameEntity* Entity, int  index);

public:
	FGameEntityData GetCurrentEntity() { return EntityDataArray[CurrentTurn]; }
	FGameEntityData GetEntityData(AGameEntity* Entity);
	
public:
	UPROPERTY(BlueprintReadWrite)
	TArray<FGameEntityData> EntityDataArray;
	OnChangeTurn ChangeTurnAction;

	protected:
	int CurrentTurn = 0;
};
