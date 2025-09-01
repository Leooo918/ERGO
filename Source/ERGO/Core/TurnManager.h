#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameEntityData.h"
#include "TurnManager.generated.h"

class AGameEntity;
class ARouletteGun;

DECLARE_DELEGATE_TwoParams(OnChangeTurn, FGameEntityData, FGameEntityData);

UCLASS()
class ERGO_API ATurnManager : public AActor
{
	GENERATED_BODY()

public:
	ATurnManager();

protected:
	virtual void BeginPlay() override;

public:
	void Initialize();
	void StartRoulette(int MaxBulletCount);
	void ChangeTurn();
	void EndRoulette();

public:
	FGameEntityData GetCurrentEntity() { return EntityArray[CurrentTurn]; }
	
public:
	UPROPERTY(BlueprintReadWrite)
	TArray<FGameEntityData> EntityArray;

	OnChangeTurn ChangeTurnAction;

	protected:
	int CurrentTurn = 0;
};
