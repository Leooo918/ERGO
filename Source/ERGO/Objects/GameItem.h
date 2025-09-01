#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "GameItem.generated.h"


UCLASS(Abstract)
class ERGO_API AGameItem : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	AGameItem();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void UseItem(AGameEntity* target) PURE_VIRTUAL();
	virtual void OnInteract(AGameEntity* target) override;
};
