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

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);	
}

void AMovingPlatform::MovePlatform(float DeltaTime){
	if(ShouldPlatformReturn())
	{
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();			//Platform이 가는 방향을 넣음
		StartLocation += MoveDirection * MoveDistance;						//시작지점을 가는 처음위치 + 가는방향(Normal Vector) * 거리로 해서 일정한 곳을 지정함
		PlatformVelocity = -PlatformVelocity;								//PlatformVelocity를 거꾸로가게 만든다.
		SetActorLocation(StartLocation);									//시작지점을 현재 도착한 지점(MoveDistance보다 현재 크니까 지금이 터닝포인트)로 지정한다.
	}else{
		CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + PlatformVelocity*DeltaTime;
		SetActorLocation(CurrentLocation);
	}	
}

void AMovingPlatform::RotatePlatform(float DeltaTime){			
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn() const{			//const로 된 함수는 const로 만들어진 함수만 부를 수 있다. GetDistanceMoved는 class안에 있는 값을 수정하진 않지만 const를 지우면 에러가 뜬다.
	return GetDistanceMoved() > MoveDistance;
}

float AMovingPlatform::GetDistanceMoved() const{
	return FVector::Dist(StartLocation, GetActorLocation());
}