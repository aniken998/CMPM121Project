// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MyBoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Collider"));
	MyBoxCollider->SetupAttachment(RootComponent);

	MyBoxCollider->SetNotifyRigidBodyCollision(true);

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	MyBoxCollider->OnComponentHit.AddDynamic(this, &AMyActor::OnCompHit);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (peopleOn)
	{
		FVector newLocation = GetActorLocation();

		if (newLocation.X >= 549.0)
		{
			plus = false;
			peopleOn = false;
		}

		if (newLocation.X <= -549.0)
		{
			plus = true;
			peopleOn = false;
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
}

void AMyActor::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->ActorHasTag("Player"))
	{
		peopleOn = true;
		UE_LOG(LogTemp, Warning, TEXT("isPlayer"));

	}
	UE_LOG(LogTemp, Warning, TEXT("on platform"));
}



