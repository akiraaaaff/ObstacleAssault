// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	startingPos = GetActorLocation();
	initVelocity = velocity;
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
	
	
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{


	if(ShouldPlatformReturn()){

		// working out exact new starting position
		FVector moveDirection = velocity.GetSafeNormal();
		startingPos = startingPos + moveDirection * moveDistance;
		
		// flipping velocity and acceleration to reverse movement
		initVelocity = -initVelocity;
		velocity = initVelocity;
		acceleration = -acceleration;

		
	}
	
	// Updated Velocity and Position 
	velocity += acceleration * DeltaTime;
	FVector newPos = GetActorLocation()+velocity * DeltaTime;

	SetActorLocation(newPos);
	
}
void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(rotationVelocity*DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	//distanceMoved = FVector::Dist(GetActorLocation(), startingPos);
	return GetDistanceMoved() > moveDistance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(GetActorLocation(), startingPos);
}