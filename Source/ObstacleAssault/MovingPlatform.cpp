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

	SetActorLocation(startingPos);
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector acceleration = FVector(20,20,0);


	velocity += acceleration * DeltaTime;

	SetActorLocation(GetActorLocation()+velocity);
	
	distanceMoved = FVector::Dist(GetActorLocation(), startingPos);

	if(distanceMoved >= 1200){
		SetActorLocation(startingPos);
		velocity = initVelocity;
	}

	
}

