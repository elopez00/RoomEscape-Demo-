// Fill out your copyright notice in the Description page of Project Settings.


#include "REWayPoint.h"

// Sets default values
AREWayPoint::AREWayPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	SetRootComponent(Root);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	BoxComponent->SetupAttachment(GetRootComponent());
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AREWayPoint::OnPlayerEnter);
}

// Called when the game starts or when spawned
void AREWayPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AREWayPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AREWayPoint::OnPlayerEnter(UPrimitiveComponent* OverlapComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult &SweepResult)
{
	ARECharacterAI* Character = nullptr;

	if (OtherActor != nullptr)
	{
		Character = Cast<ARECharacterAI>(OtherActor);
		if (Character != nullptr)
		{
			Character->NextWayPoint = NextWayPoint;
		}
	}

}
