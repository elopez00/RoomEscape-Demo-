// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Components/TextRenderComponent.h"
#include "Engine/TextRenderActor.h"
#include "Engine/TriggerVolume.h"
#include "ShowText.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UShowText : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UShowText();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	// Method to Display text
	void DisplayText();

	// Method to Hide text
	void HideText();

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr; // Interaction with trigger volume

	ACharacter* Character = nullptr;

	// Actor that owns the Text Render Component
	ATextRenderActor* TextRenderActor = nullptr;

	// Text Render Component
	UTextRenderComponent* TextRenderComponent = nullptr;
	
	UPROPERTY(EditAnywhere)
		float DelayTime = 0.5f;
	float LastDisplayTime = 0.f;
};
