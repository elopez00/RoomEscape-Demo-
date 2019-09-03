// Fill out your copyright notice in the Description page of Project Settings.


#include "RECharacterAI.h"

// Sets default values
ARECharacterAI::ARECharacterAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 600.f, 0.f);
}


// Called when the game starts or when spawned
void ARECharacterAI::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARECharacterAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARECharacterAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
