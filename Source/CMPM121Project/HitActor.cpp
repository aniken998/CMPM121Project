// Fill out your copyright notice in the Description page of Project Settings.


#include "HitActor.h"

#include "ConstructorHelpers.h"

#include "Engine/StaticMesh.h"


// Sets default values
AHitActor::AHitActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("My Collider"));
	MyCollider->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AHitActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHitActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

