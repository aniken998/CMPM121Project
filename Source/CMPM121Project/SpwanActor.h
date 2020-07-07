// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"

#include "SpwanActor.generated.h"

UCLASS()
class CMPM121PROJECT_API ASpwanActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpwanActor();

	UPROPERTY(VisibleAnywhere)
	USphereComponent* TriggerSphere;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SuperMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetRandomLocationAndSize();


};
