// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FVector startingPos = FVector(0.0f,0.0f,0.0f);
	
	UPROPERTY(VisibleAnywhere)
	float distanceMoved = -1.0f;

	UPROPERTY(EditAnywhere)
	FVector acceleration = FVector(0.0f,0.0f,20.0f);
	
	UPROPERTY(EditAnywhere)
	FVector velocity = FVector(0.0f,0.0f,1.0f);
	FVector initVelocity = FVector(0.0f,0.0f,1.0f);

	
	UPROPERTY(EditAnywhere)
	FRotator rotationVelocity;

	UPROPERTY(EditAnywhere)
	float moveDistance = 500.0f;

	UPROPERTY(VisibleAnywhere)
	bool goingForward = true;

	//float previousVeloctiyDot = 0;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;
};
