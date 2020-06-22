// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/CapsuleComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Predator.generated.h"

class ABoid;

UCLASS()
class FLOCKING_API APredator : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		UCapsuleComponent* CollisionComponent;
	
public:	
	// Sets default values for this actor's properties
	APredator();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* PredatorVisual;
	
	// Function to delete boid if collided
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	ABoid* TargetBoid;
	
	float MoveSpeed;

	bool IsEating;
	// Timer used for determining when to finish eating
	int64 TargetTime;
	// How often timer increment 1 = 1s
	const int64 Timer = 5;

	void MoveToBoid(float DeltaTime);
	
	void FindNearestBoid();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
