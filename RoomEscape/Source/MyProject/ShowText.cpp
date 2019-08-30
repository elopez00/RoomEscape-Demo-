// Fill out your copyright notice in the Description page of Project Settings.


#include "ShowText.h"

// Sets default values for this component's properties
UShowText::UShowText()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UShowText::BeginPlay()
{
	Super::BeginPlay();

	/// Finds Actor that owns the component and assigns it the the Text Render Component instance
	TextRenderActor = Cast<ATextRenderActor>(GetOwner());
	TextRenderComponent = TextRenderActor->GetTextRender();

	// Finds Character in the world
	Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
}


// Called every frame
void UShowText::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate->IsOverlappingActor(Character))
	{
		DisplayText();
		LastDisplayTime = GetWorld()->GetTimeSeconds();
	}

	if (GetWorld()->GetTimeSeconds() - LastDisplayTime > DelayTime)
	{
		HideText();
	}

}


void UShowText::DisplayText() 
{
	TextRenderComponent->SetText(TEXT("BROO"));
}

void UShowText::HideText()
{
	TextRenderComponent->SetText(TEXT(""));
}