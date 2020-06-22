// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Boid.h"
#include "Predator.h"
#include "MigratoryUrge.h"
#include "Asteroid.h"
#include "BoidGenerator.generated.h"


UCLASS()
class FLOCKING_API ABoidGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoidGenerator();

	static const int NUM_BOID = 100;
	static const int NUM_PRED = 10;
	static const int NUM_ASTEROID = 20;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Check if there is a need to repopulate
	bool NeedToPopulate = false;

	void SpawnInitialActors();
	//Populate and parent in Evolutionary Algorithms 
	void Populate();
	void ParentSelection();

private:
	// Array to hold boids
	TArray<ABoid*> BoidList;
	// Array to hold dead boids
	TArray<ABoid*> DeadBoidList;

	// Migration Target pointer
	AMigratoryUrge* MigrationTarget;
	FVector TargetLocation;

	// Array to hold parent boids
	TArray<ABoid*> ParentList;

	// A Mutation value for when the parents repopulate
	int MutationRate = 25;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int NumberOfBoids;

};
