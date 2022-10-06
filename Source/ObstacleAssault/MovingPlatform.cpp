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
	MyX = MyVector.X;
	//MyVector.Set(-13900.0, -4330.0, 4056.0);
	
	SetActorLocation(MyVector);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector LocalVector;

	MyVector.Z = MyVector.Z + 0.2;
	MyVector.Y = MyVector.Y + 1;

	LocalVector = MyVector;
	SetActorLocation(LocalVector);

	//Move platform forward;
		//Get Current location;
		//Add vector to that location
		//Set the location
	//Send platform back if gone too far
		//Check how far we've moved
		//Reverse direction of motion if gone too far
}

