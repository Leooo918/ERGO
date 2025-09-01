#include "Objects/Entity/ER_Player.h"
#include "Objects/GameItem.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AER_Player::AER_Player()
{
	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = true;

	static ConstructorHelpers::FObjectFinder<UInputMappingContext> IMCDefaultRef(
		TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Input/IMC_Default.IMC_Default'"));
	if (IMCDefaultRef.Succeeded())
	{
		InputMappingContext = IMCDefaultRef.Object;
	}

	static ConstructorHelpers::FObjectFinder<UInputAction> SelectActionRef(
		TEXT("/Script/EnhancedInput.InputAction'/Game/Input/InputAction/IA_Select.IA_Select'"));
	if (SelectActionRef.Succeeded())
	{
		SelectAction = SelectActionRef.Object;
	}
	static ConstructorHelpers::FObjectFinder<UInputAction> TurnActionRef(
		TEXT("/Script/EnhancedInput.InputAction'/Game/Input/InputAction/IA_Turn.IA_Turn'"));
	if (TurnActionRef.Succeeded())
	{
		TurnAction = TurnActionRef.Object;
	}
}

void AER_Player::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		auto* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
			PlayerController->GetLocalPlayer());
		if (Subsystem && InputMappingContext)
		{
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}

		EnableInput(PlayerController);
	}
}


void AER_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	auto* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent)
	{
		EnhancedInputComponent->BindAction(SelectAction, ETriggerEvent::Triggered, this, &AER_Player::Input_Select);
		EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &AER_Player::Input_Turn);
	}
}


void AER_Player::Input_Select(const FInputActionValue& InputValue)
{
	//if (CurrentState != EEntityState::EntityTurn) return;

	APlayerController* PC = Cast<APlayerController>(GetController());
	if (!PC) return;

	FVector Location;
	FRotator Rotation;
	PC->GetPlayerViewPoint(Location, Rotation);

	FVector Start = Location;
	FVector End = Start + (Rotation.Vector() * 1000.0f);

	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this); // 자기 자신은 무시

	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params))
	{
		AActor* HitActor = HitResult.GetActor();
		if (HitActor)
		{
			UE_LOG(LogTemp, Display, TEXT("%s"), *HitActor->GetName());
			
			IInteractable* target = Cast<IInteractable>(HitActor);
			if (target)
			{
				target->OnInteract(this);
			}
		}
	}
}

void AER_Player::Input_Turn(const FInputActionValue& InputValue)
{
	FVector2D Value = InputValue.Get<FVector2D>();
	AddControllerYawInput(Value.X);
	AddControllerPitchInput(-Value.Y);
}
