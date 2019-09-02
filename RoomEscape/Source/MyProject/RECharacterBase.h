// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "REProjectile.h"
#include "RECharacterBase.generated.h"

UCLASS()
class MYPROJECT_API ARECharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARECharacterBase();
	ARECharacterBase(const FObjectInitializer &ObjectInitializer);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Movement Methods
	void MoveForward(float Val);
	void MoveRight(float Val);
	void OnStartJump();
	void OnStopJump();

	// First person camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		UCameraComponent* FirstPersonCameraComponent;

	// Handles firing
	UFUNCTION()
		void OnFire();

	// Gun muzzle's ofset from the camera location
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector MuzzleOffset;

	// Projectile class to spawn
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AREProjectile> ProjectileClass;
};