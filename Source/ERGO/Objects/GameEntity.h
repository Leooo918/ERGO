#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameEntity.generated.h"

class AGameItem;
class ARouletteGun;

UENUM(Blueprintable)
enum class EEntityState : uint8
{
	// 자신의 차례가 아닌
	None = 0,
	// 총알 정하는 상태
	SetBullet = 1,
	// 아이템 사용할 수 있는 상태
	UsingItem = 2,
	// 발사를 할 수 있는 상태
	Shoot = 3,
	// 다른 행동 중 이어서 다른 상호작용 불가
	TakeAction = 4
};


UCLASS(Abstract)
class ERGO_API AGameEntity : public APawn
{
	GENERATED_BODY()

public:
	AGameEntity();

public:
	virtual void SetEntityState(EEntityState newState) { CurrentState = newState; }
	virtual ARouletteGun* GetGun() { return RouletteGun; }

	virtual void Initialize(ARouletteGun* gun);

protected:
	virtual void UseItem(AGameItem* Item);
	virtual void Attack(AGameEntity* target);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<ARouletteGun> RouletteGun;
	EEntityState CurrentState;
};
