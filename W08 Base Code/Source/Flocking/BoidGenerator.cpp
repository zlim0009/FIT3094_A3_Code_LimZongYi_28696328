// Fill out your copyright notice in the Description page of Project Settings.


#include "BoidGenerator.h"

// Sets default values
ABoidGenerator::ABoidGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NeedToPopulate = false;
}

// Called when the game starts or when spawned
void ABoidGenerator::BeginPlay()
{
	Super::BeginPlay();
	SpawnInitialActors();
}

// Called every frame
void ABoidGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// If number of boids is lower than 20, repopulate
	if (NumberOfBoids <= 20)
	{
		NeedToPopulate = true;
		// Parent selection then repopulate the boids
		ParentSelection();
		Populate();
	}
	// If number of boids is not lower than 20 then find target
	else
	{
		if (MigrationTarget->GetActorLocation() != TargetLocation)
		{
			for (auto Boid : BoidList)
			{
				if (Boid->IsAlive)
				{
					Boid->SetMigrationTarget(MigrationTarget);
					Boid->MoveBoid(DeltaTime);
					TargetLocation = MigrationTarget->GetActorLocation();
				}
				else
				{
					DeadBoidList.Add(Boid);
					NumberOfBoids--;
				}
			}
		}
		else
		{
			for (auto Boid : BoidList)
			{
				if (Boid->IsAlive)
				{
					Boid->MoveBoid(DeltaTime);
				}
				else
				{
					DeadBoidList.Add(Boid);
					NumberOfBoids--;
				}
			}
		}
	}
}

void ABoidGenerator::SpawnInitialActors()
{
	UWorld* World = GetWorld();

	// Boid Spawner
	for (int i = 0; i < NUM_BOID; i++)
	{
		float RandomX = FMath::FRandRange(-3000, 3000);
		float RandomY = FMath::FRandRange(-3000, 3000);
		float RandomZ = FMath::FRandRange(-3000, 3000);

		FVector Position(RandomX, RandomY, RandomZ);
		ABoid* Boid = World->SpawnActor<ABoid>(Position, FRotator::ZeroRotator);
		Boid->CollisionWeight = rand() % 100 * 0.01;
		Boid->VectorMatchingWeight = rand() % 100 * 0.01;
		Boid->CenteringWeight = rand() % 100 * 0.01;
		Boid->PredatorWeight = rand() % 100 * 0.01;
		
		BoidList.Add(Boid);
		NumberOfBoids++;
	}

	// Predator Spawner
	for (int i = 0; i < NUM_PRED; i++)
	{
		float RandomX = FMath::FRandRange(-3000, 3000);
		float RandomY = FMath::FRandRange(-3000, 3000);
		float RandomZ = FMath::FRandRange(-3000, 3000);

		FVector Position(RandomX, RandomY, RandomZ);
		APredator* Predator = World->SpawnActor<APredator>(Position, FRotator::ZeroRotator);
	}

	// Asteroid Spawner
	for (int i = 0; i < NUM_ASTEROID; i++)
	{
		AAsteroid* Asteroid = World->SpawnActor<AAsteroid>(FVector::ZeroVector, FRotator::ZeroRotator);
	}

	// Migratory Urge target spawner
	float RandomX = FMath::FRandRange(-3000, 3000);
	float RandomY = FMath::FRandRange(-3000, 3000);
	float RandomZ = FMath::FRandRange(-3000, 3000);
	FVector Position(RandomX, RandomY, RandomZ);
	MigrationTarget = World->SpawnActor<AMigratoryUrge>(Position, FRotator::ZeroRotator);
}

void ABoidGenerator::Populate()
{
	// Check if the boids need repopulation
	if (NeedToPopulate)
	{
		// Change each of the properties of the dead boids with the genes of the parent boids
		for (auto Boids : BoidList)
		{
			// Evolve by randomly selecting two of the alive boid.
			int ParentSelection = rand() % ParentList.Num();
			int ParentSelection2 = rand() % ParentList.Num();

			Boids->CollisionWeight = ParentList[ParentSelection]->CollisionWeight;
			Boids->VectorMatchingWeight = ParentList[ParentSelection]->VectorMatchingWeight;
			Boids->CenteringWeight = ParentList[ParentSelection2]->CenteringWeight;
			Boids->PredatorWeight = ParentList[ParentSelection2]->PredatorWeight;

			// Apply mutation and the boid has 25% chance to mutate for each gene
			if (rand() % 100 < MutationRate)
			{
				Boids->CollisionWeight = rand() % 100 * 0.01;
			}
			if (rand() % 100 < MutationRate)
			{
				Boids->VectorMatchingWeight = rand() % 100 * 0.01;
			}
			if (rand() % 100 < MutationRate)
			{
				Boids->CenteringWeight = rand() % 100 * 0.01;
			}
			if (rand() % 100 < MutationRate)
			{
				Boids->PredatorWeight = rand() % 100 * 0.01;
			}

			Boids->SetMigrationTarget(MigrationTarget);
			
			Boids->SetActorHiddenInGame(false);
			Boids->Fitness = 0;
			Boids->IsAlive = false;
			Boids->IsFitnessCalculated = false;

		}
		NeedToPopulate = false;
		NumberOfBoids = 100;
		DeadBoidList.Empty();
	}
}

void ABoidGenerator::ParentSelection()
{
	float TotalFitness = 0.0f;
	float AverageFitness = 0.0f;

	// Getting the average Fitness from all the boids alive
	for (auto AliveBoid : BoidList)
	{
		// Are the boids alive?
		if (AliveBoid->IsAlive)
		{
			TotalFitness += AliveBoid->Fitness;
		}
	}
	AverageFitness = TotalFitness / NumberOfBoids;
	

	for (auto AliveBoid : BoidList)
	{
		// Are the boids alive?
		if (AliveBoid->IsAlive)
		{
			// Does the boid have a Fitness value over the average alive boid
			if (AliveBoid->Fitness >= AverageFitness)
			{
				// Add it into the parent list to repopulate
				ParentList.Add(AliveBoid);
			}
		}
	}
}