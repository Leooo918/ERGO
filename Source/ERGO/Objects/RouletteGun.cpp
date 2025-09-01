#include "Objects/RouletteGun.h"
#include "Objects/GameEntity.h"

ARouletteGun::ARouletteGun()
{
	PrimaryActorTick.bCanEverTick = true;
	BulletCount = 0;
}

void ARouletteGun::BeginPlay()
{
	Super::BeginPlay();
}

void ARouletteGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ARouletteGun::GetCurrentBullet()
{
	UE_LOG(LogTemp, Warning, TEXT("The Gun is Empty But You Steel Trying To Get Bullet"));
	if (IsEmpty())
	{
		return false;
	}
	bool Bullet = BulletTypes[0];
	BulletTypes.erase(BulletTypes.begin());

	return Bullet;
}

void ARouletteGun::Shoot(AGameEntity* Target)
{
	Damage = 1;
}

void ARouletteGun::SetBullet(int FakeCount, int RealCount)
{
	int RemainFake = FakeCount;
	int RemainReal = RealCount;

	for (int i = 0; i < FakeCount + RealCount; i++)
	{
		if (RemainFake == 0)
		{
			BulletTypes.push_back(true);
			RemainReal--;
			continue;
		}
		if (RemainReal == 0)
		{
			BulletTypes.push_back(false);
			RemainFake--;
			continue;
		}

		bool IsReal = FMath::RandBool();

		BulletTypes.push_back(IsReal);

		if (IsReal) --RemainReal;
		else --RemainFake;
	}
}

void ARouletteGun::OnInteract(AGameEntity* target)
{
	UE_LOG(LogTemp, Display, TEXT("MING"));
}
