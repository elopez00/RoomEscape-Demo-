// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "GameFramework/Character.h"
#include "OpenDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor();
	void CloseDoor();
	
	UPROPERTY(BlueprintAssignable)
		FOnOpenRequest OnOpenRequest;
	UPROPERTY(BlueprintAssignable)
		FOnOpenRequest OnCloseRequest;
	

private:
	UPROPERTY(VisibleAnywhere)
		float OpenAngle = 0.f;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 0.5f;
		
	UPROPERTY(EditAnywhere)
		float ReqWeight;

	float LastDoorOpenTime;

	// Owning Door
	AActor* Owner = nullptr; 

	// Character Player Controller
	ACharacter* Character = nullptr;

	float GetTotalMassOfActorsOnPlate();
};
