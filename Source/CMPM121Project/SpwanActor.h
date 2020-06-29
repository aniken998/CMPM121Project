// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpwanActor.generated.h"

UCLASS()
class CMPM121PROJECT_API ASpwanActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpwanActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SuperMesh;


	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
