// Fill out your copyright notice in the Description page of Project Settings.


#include "RECharacterBase.h"
#include "Components/InputComponent.h"
#include "Engine.h"

// Sets default values
ARECharacterBase::ARECharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

ARECharacterBase::ARECharacterBase(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
	//Camera point creation
	FirstPersonCameraComponent = ObjectInitializer.CreateAbstractDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->AttachTo(GetCapsuleComponent());

	// Allow the pawn to control rotation.
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void ARECharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	if (GEngine) //TODO Erase this when packaging
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("RECharacter is being used!"));
	}
}

// Called every frame
void ARECharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARECharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Keyboard input
	InputComponent->BindAxis("MoveForward", this, &ARECharacterBase::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ARECharacterBase::MoveRight);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ARECharacterBase::OnStartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &ARECharacterBase::OnStopJump);

	// Mouse input
	InputComponent->BindAxis("Turn", this, &ARECharacterBase::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &ARECharacterBase::AddControllerPitchInput);

}

void ARECharacterBase::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.f))
	{
		// Find out which ways is forward
		FRotator Rotation = Controller->GetControlRotation();

		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.f;
		}

		// Add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ARECharacterBase::MoveRight(float Value) 
{
	// Find out which way is right
	const FRotator Rotation = Controller->GetControlRotation();
	const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);

	// Add movement in that direction
	AddMovementInput(Direction, Value);
}

void ARECharacterBase::OnStartJump()
{
	bPressedJump = true;
}

void ARECharacterBase::OnStopJump()
{
	bPressedJump = false;
}
