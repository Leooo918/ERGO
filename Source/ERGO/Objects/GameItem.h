#pragma once

#include "CoreMinimal.h"
#include "GameItem.generated.h"


UCLASS(Abstract)
class ERGO_API AGameItem : public AActor
{
	GENERATED_BODY()

public:
	AGameItem();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	virtual void UseItem(class AGameEntity* target) PURE_VIRTUAL();
};
