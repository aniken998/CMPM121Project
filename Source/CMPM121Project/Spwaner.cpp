// Fill out your copyright notice in the Description page of Project Settings.


#include "Spwaner.h"

#include "Engine/StaticMesh.h"


// Sets default values
ASpwaner::ASpwaner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpwaner::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle UnusedHandle;
	GetWorldTimerManager().SetTimer(UnusedHandle, this, &ASpwaner::SpwaningActor, FMath::RandRange(2, 5), true);
	
}

// Called every frame
void ASpwaner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpwaner::SpwaningActor()
{
	if (SpwanNum < 10)
	{
		ASpwanActor* NewSpwanActor = GetWorld()->SpawnActorDeferred<ASpwanActor>(MySpwanActor, GetActorTransform());

		if (NewSpwanActor)
		{
			NewSpwanActor->SetRandomLocationAndSize();
			NewSpwanActor->FinishSpawning(GetActorTransform());
			++SpwanNum;
		}
	}
}

