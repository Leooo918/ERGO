#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameEntity.generated.h"

class AGameItem;
class ARouletteGun;

UENUM(Blueprintable)
enum class EEntityState : uint8
{
	None = 0,
	SelectItem = 1,
	Attack = 2,
};


UCLASS(Abstract)
class ERGO_API AGameEntity : public APawn
{
	GENERATED_BODY()

public:
	AGameEntity();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	virtual void SetEntityState(EEntityState newState) { CurrentState = newState; }
	virtual void GetItem(AGameItem* Item) { if (Item) OwnedItems.Add(Item); }
	virtual void GetAttacked() { Health--; }
	virtual void Initialize(ARouletteGun* gun);

protected:
	virtual void UseItem(AGameItem* Item);
	virtual void Attack(AGameEntity* target);

protected:
	UPROPERTY() 
	TArray<TObjectPtr<AGameItem>> OwnedItems;
	TObjectPtr<ARouletteGun> RouletteGun;
	EEntityState CurrentState;
	int Health;
};
