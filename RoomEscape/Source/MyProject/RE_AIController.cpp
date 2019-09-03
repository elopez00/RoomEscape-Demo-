// Fill out your copyright notice in the Description page of Project Settings.


#include "RE_AIController.h"

ARE_AIController::ARE_AIController()
{
	PrimaryActorTick.bCanEverTick = true;

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

	SightConfig->SightRadius = AISightRadius;
	SightConfig->LoseSightRadius = AILoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees;
	SightConfig->SetMaxAge(AISightAge);

	// Detects Enemies, Friends and Nuetral
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	// Set sight as dominant sense
	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	
	// Attatch function that will detect pawn
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &ARE_AIController::OnPawnDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);
}

void ARE_AIController::BeginPlay()
{
	Super::BeginPlay();

	if (GetPerceptionComponent() != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("All Systems Set"))
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Some Problem has Occured"))
	}
}

void ARE_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void ARE_AIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

FRotator ARE_AIController::GetControlRotation() const
{
	if (GetPawn() == nullptr)
	{
		return FRotator(0.f, 0.f, 0.f);
	}

	return FRotator(0.f, GetPawn()->GetActorRotation().Yaw, 0.f);
}

void ARE_AIController::OnPawnDetected(const TArray<AActor*>& DetectedPawns)
{

}
