// Fill out your copyright notice in the Description page of Project Settings.


#include "WaterDamage.h"

// Sets default values for this component's properties
UWaterDamage::UWaterDamage()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWaterDamage::BeginPlay()
{
	Super::BeginPlay();

	Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	
}


// Called every frame
void UWaterDamage::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	CheckCharacterOverlap();
	// ...
}

void UWaterDamage::CheckCharacterOverlap()
{
	if (Water->IsOverlappingActor(Character))
	{
		UGameplayStatics::ApplyDamage(Character, 100.f, GetOwner()->GetInstigatorController(), GetOwner(), DamageType);
	}
}

