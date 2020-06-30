// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "SpwanActor.h"

#include "Spwaner.generated.h"

UCLASS()
class CMPM121PROJECT_API ASpwaner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpwaner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int SpwanNum = 0;

public:	
	UPROPERTY(EditAnywhere)
	TSubclassOf<ASpwanActor> MySpwanActor;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpwaningActor();
};
