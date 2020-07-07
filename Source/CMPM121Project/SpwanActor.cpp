// Fill out your copyright notice in the Description page of Project Settings.


#include "SpwanActor.h"

#include "ConstructorHelpers.h"

#include "Engine/StaticMesh.h"

// Sets default values
ASpwanActor::ASpwanActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Trigger Sphere"));
	TriggerSphere->SetupAttachment(RootComponent);

	TriggerSphere->InitSphereRadius(170.0 * 0.2);

	SuperMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Super Mesh"));
	SuperMesh->SetupAttachment(TriggerSphere);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SuperMeshAsset(TEXT
	("/Game/MyContent/SM_MatPreviewMesh_02.SM_MatPreviewMesh_02"));

	if (SuperMeshAsset.Succeeded())
	{
		SuperMesh->SetStaticMesh(SuperMeshAsset.Object);
		SuperMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -20.0f));
		SuperMesh->SetWorldScale3D(FVector(0.2f));
	}

	TriggerSphere->SetSimulatePhysics(true);
	//TriggerSphere->SetNotifyRigidBodyCollision(true);

	//TriggerSphere->BodyInstance.SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	SuperMesh->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);

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
	if (GetActorLocation().Z < -1000.0f)
	{
		Destroy();
	}
}

void ASpwanActor::SetRandomLocationAndSize()
{
	float size = FMath::RandRange(0.1f, 0.5f);

	float locationX = FMath::RandRange(-1400.0f, 1400.0f);
	float locationY = FMath::RandRange(-1400.0f, 1400.0f);


	SuperMesh->SetWorldScale3D(FVector(size));
	SetActorLocation(FVector(locationX, locationY, 1000.0f));
	TriggerSphere->InitSphereRadius(170.0 * size);
}



