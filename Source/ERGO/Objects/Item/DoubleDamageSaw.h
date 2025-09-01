#pragma once

#include "CoreMinimal.h"
#include "Objects/GameItem.h"
#include "DoubleDamageSaw.generated.h"

UCLASS()
class ERGO_API ADoubleDamageSaw : public AGameItem
{
	GENERATED_BODY()
	
public:
	virtual void UseItem(AGameEntity* target) override;
};
