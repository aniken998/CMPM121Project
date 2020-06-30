// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector newLocation = GetActorLocation();

	if(newLocation.X >= 338.0f)
	{
		plus = false;
	}
	
	if(newLocation.X <= -728.0)
	{
		plus = true;
	}

	if (plus) 
	{
		newLocation.X += DeltaTime * speedX;
	}
	else
	{
		newLocation.X -= DeltaTime * speedX;
	}

	SetActorLocation(newLocation);
}

