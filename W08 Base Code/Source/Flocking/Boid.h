// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Boid.generated.h"

class APredator;
class AMigratoryUrge;
class AAsteroid;

UCLASS()
class FLOCKING_API ABoid : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* BoidVisual;

	UPROPERTY(EditAnywhere)
		UCapsuleComponent* CollisionComponent;

	// Function to delete boid if collided
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
public:	
	// Sets default values for this actor's properties
	ABoid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TArray<ABoid*> PersonalBoidArray;
	TArray<ABoid*> VisualBoidArray;
	TArray<APredator*> VisualPredatorArray;
	TArray<AAsteroid*> PersonalAsteroidArray;
	AMigratoryUrge* MigratoryTarget;
	
	float MoveSpeed;
	float MinMoveSpeed;
	float MaxMoveSpeed;

	float TurnSpeed;
	
	// Finding what is around the boid
	void FindAllInPersonalRange();
	void FindAllInVisualRange();

	// Calculate flocking vectors 
	FVector CollisionAvoidance();
	FVector VectorMatching();
	FVector FlockingCentering();
	FVector PredatorAvoidance();

	void Reset();
	void Relocate();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float CollisionWeight;
	float VectorMatchingWeight;
	float CenteringWeight;
	float PredatorWeight;

	// Boid's fitness 
	float Fitness = 0.0f;
	// Check boid Evolution state
	bool IsAlive;
	bool IsFitnessCalculated;

	void MoveBoid(float DeltaTime);

	void SetMigrationTarget(AMigratoryUrge* MigrationUrge) { MigratoryTarget = MigrationUrge; }
	float GetMoveSpeed() { return MoveSpeed; }
};