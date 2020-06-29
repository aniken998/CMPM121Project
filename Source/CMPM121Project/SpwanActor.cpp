// Fill out your copyright notice in the Description page of Project Settings.


#include "SpwanActor.h"

// Sets default values
ASpwanActor::ASpwanActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SuperMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Super Mesh"));
}

// Called when the game starts or when spawned
void ASpwanActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpwanActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

