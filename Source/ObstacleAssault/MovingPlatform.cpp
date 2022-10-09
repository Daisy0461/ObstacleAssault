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
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Move platform forward;
		//Get Current location;
	FVector CurrentLocation = GetActorLocation();
		//Add vector to that location
		CurrentLocation = CurrentLocation + PlatformVelocity*DeltaTime;
		//Set the location
		SetActorLocation(CurrentLocation);
	//Send platform back if gone too far
		//Check how far we've moved
		DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
		
		//Reverse direction of motion if gone too far
		if(DistanceMoved >= MoveDistance)
		{
			FVector MoveDirection = PlatformVelocity.GetSafeNormal();			//Platform이 가는 방향을 넣음
			StartLocation += MoveDirection * MoveDistance;						//시작지점을 가는 처음위치 + 가는방향(Normal Vector) * 거리로 해서 일정한 곳을 지정함
			PlatformVelocity = -PlatformVelocity;								//PlatformVelocity를 거꾸로가게 만든다.
			SetActorLocation(StartLocation);									//시작지점을 현재 도착한 지점(MoveDistance보다 현재 크니까 지금이 터닝포인트)로 지정한다.
		}
}

