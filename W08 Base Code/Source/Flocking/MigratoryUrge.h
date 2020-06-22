// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MigratoryUrge.generated.h"

UCLASS()
class FLOCKING_API AMigratoryUrge : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MigratoryTargetVisual;
	
public:	
	// Sets default values for this actor's properties
	AMigratoryUrge();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Handle for Timer
	FTimerHandle TimerHandle;

	void MoveMigratoryTarget();

	int BoidCounter;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};