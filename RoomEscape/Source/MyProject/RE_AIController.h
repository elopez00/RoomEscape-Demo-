// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "GameFramework/Controller.h"
#include "RE_AIController.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API ARE_AIController : public AAIController
{
	GENERATED_BODY()

public:
	ARE_AIController();
	
	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;

	virtual void Tick(float DeltaSeconds) override;

	virtual FRotator GetControlRotation() const override;
	
	UFUNCTION()
		void OnPawnDetected(const TArray<AActor*>& DetectedPawns);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
		float AISightRadius = 500.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
		float AISightAge = 5.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
		float AILoseSightRadius = AISightRadius + 50.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
		float AIFieldOfView = 90.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
		class UAISenseConfig_Sight* SightConfig;
};
