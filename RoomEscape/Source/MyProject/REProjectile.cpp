// Fill out your copyright notice in the Description page of Project Settings.


#include "REProjectile.h"

// Sets default values
AREProjectile::AREProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AREProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AREProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AREProjectile::AREProjectile(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//TODO replace this with actual projectile
	CollisionComp = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("ShpereComp"));
	CollisionComp->InitSphereRadius(15.f);
	RootComponent = CollisionComp;
	
	// Use ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = ObjectInitializer.CreateDefaultSubobject<UProjectileMovementComponent>(this, TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 0.3f;

	// Set life span
	InitialLifeSpan = 3.f;


	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AREProjectile::OnHit);
}

void AREProjectile::InitVelocity(const FVector& ShootDirection)
{
	if (ProjectileMovement)
	{
		// set the projectile's veloctiy to the desired diretion
		ProjectileMovement->Velocity = ShootDirection * ProjectileMovement->InitialSpeed;
	}
}

void AREProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics())
	{
		OtherComponent->AddImpulseAtLocation(ProjectileMovement->Velocity * 100.0f, Hit.ImpactPoint);
	}
}

