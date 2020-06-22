// Fill out your copyright notice in the Description page of Project Settings.


#include "Boid.h"
#include "Predator.h"
#include "Asteroid.h"
#include "MigratoryUrge.h"
#include "ConstructorHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Materials/Material.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ABoid::ABoid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Stuff for configuring materials and static mesh components
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	BoidVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visible Component"));
	BoidVisual->SetupAttachment(RootComponent);
	CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision Component"));
	CollisionComponent->SetupAttachment(BoidVisual);

	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ABoid::OnOverlapBegin);

	//Get Sphere Mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ConeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone"));
	if (ConeVisualAsset.Succeeded())
	{
		BoidVisual->SetStaticMesh(ConeVisualAsset.Object);
	}

	//Get Material
	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("/Game/StarterContent/Materials/M_Brick_Cut_Stone.M_Brick_Cut_Stone"));
	if (FoundMaterial.Succeeded())
	{
		BoidVisual->SetMaterial(0, FoundMaterial.Object);
	}

	// Setting default values
	MinMoveSpeed = 20.0f;
	MaxMoveSpeed = 200.0f;
	TurnSpeed = 20.0f;
	IsAlive = true;
}

// Called when the game starts or when spawned
void ABoid::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Check if the boid is in the playable area if not wrap to other side of 
	if (GetActorLocation().X < -3000 || GetActorLocation().X > 3000 ||
		GetActorLocation().Y < -3000 || GetActorLocation().Y > 3000 ||
		GetActorLocation().Z < -3000 || GetActorLocation().Z > 3000)
	{
		// Relocate to other side of the bounds
		Relocate();
	}

	// If the boid is alive add fitness
	if (IsAlive)
	{
		// MoveBoid(DeltaTime);
		Fitness++;
	}
}

// Move the boid per tick to the flocking direction
void ABoid::MoveBoid(float DeltaTime)
{
	Reset();

	FindAllInPersonalRange();
	FindAllInVisualRange();

	// Get Desired velocity
	FVector ResultantVector = MigratoryTarget->GetActorLocation() - GetActorLocation();
	ResultantVector += CollisionAvoidance();
	ResultantVector += VectorMatching();
	ResultantVector += FlockingCentering();
	ResultantVector += PredatorAvoidance();
	ResultantVector.Normalize();

	// Getting target rotation
	FQuat CurrentRotation = GetVelocity().ToOrientationQuat();
	FQuat TargetRotation = ResultantVector.ToOrientationQuat();
	FQuat NewRotation = FQuat::Slerp(CurrentRotation, TargetRotation, TurnSpeed * DeltaTime);
	
	//Update position and rotation based on direction and move MoveSpeed
	FVector NewPos = GetActorLocation() + ResultantVector * MoveSpeed * DeltaTime;
	SetActorLocation(NewPos);
	SetActorRotation(NewRotation);
}


// Find any other objects in the personal range
void ABoid::FindAllInPersonalRange()
{
	// List of overlaps with other boids we are about to generate
	TArray<AActor*> mOverlaps;
	// We can define actors to ignore.
	TArray<AActor*> mIgnores;
	mIgnores.Add(this);
	
	// What objects are we looking for
	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypes;
	objectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_GameTraceChannel1));
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GetActorLocation(),
		1500.0f, objectTypes, NULL, mIgnores, mOverlaps);
	
	// For each overlap found
	for (auto actor : mOverlaps)
	{
		// Attempt to cast to a boid object
		ABoid* BoidPointer = Cast<ABoid>(actor);
		if (BoidPointer)
		{
			// If successful then add it to boid array
			PersonalBoidArray.Add(BoidPointer);
		}

		AAsteroid* AsteroidPointer = Cast<AAsteroid>(actor);
		if (AsteroidPointer)
		{
			// If successful then add it to boid array
			PersonalAsteroidArray.Add(AsteroidPointer);
		}
	}
}

// Find any other objects in the visual range
void ABoid::FindAllInVisualRange()
{
	// List of overlaps with other boids we are about to generate
	TArray<AActor*> mOverlaps;
	// We can define actors to ignore.
	TArray<AActor*> mIgnores;

	// Ignore this actor
	mIgnores.Add(this);

	// What objects are we looking for
	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypes;
	objectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_GameTraceChannel1));
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GetActorLocation(),
		2000.0f, objectTypes, NULL, mIgnores, mOverlaps);

	// For each overlap found
	for (auto actor : mOverlaps)
	{
		// Attempt to cast to a boid object
		ABoid* BoidPointer = Cast<ABoid>(actor);
		if (BoidPointer)
		{
			// If successful then add it to boid array
			VisualBoidArray.Add(BoidPointer);
		}
	}

	
	// For each overlap found
	for (auto actor : mOverlaps)
	{
		// Attempt to cast to a asteroid object
		APredator* PredatorPointer = Cast<APredator>(actor);
		if (PredatorPointer)
		{
			// If successful then add it to asteroid list
			VisualPredatorArray.Add(PredatorPointer);
		}
	}
}

// Getting the collision avoidance vector
FVector ABoid::CollisionAvoidance()
{
	FVector CollisionAvoidanceVector;

	// Avoiding other Boids
	for (auto boid : PersonalBoidArray)
	{
		FVector Direction = GetActorLocation() - boid->GetActorLocation();
		CollisionAvoidanceVector -= Direction;
	}

	// Avoiding Asteroids (dynamic walls)
	for (auto asteroid : PersonalAsteroidArray)
	{
		FVector Direction = GetActorLocation() - asteroid->GetActorLocation();
		CollisionAvoidanceVector -= Direction;
	}

	// Returns a normalized collision avoidance vector depending on the collision weight
	return CollisionAvoidanceVector.GetSafeNormal() * CollisionWeight;
}

// Getting the velocity matching vector
FVector ABoid::VectorMatching()
{
	// The cumulative velocity
	FVector Velocities;

	// Add the velocities of each surrounding boid
	for (auto boid : VisualBoidArray)
	{
		Velocities += boid->GetVelocity();
	}

	// Get the average of the velocities
	FVector VelocityVector = Velocities / VisualBoidArray.Num();

	// Returns a normalized velocity vector depending on the velocity weight
	return VelocityVector.GetSafeNormal() * VectorMatchingWeight;
}

// Getting the flocking center vector
FVector ABoid::FlockingCentering()
{
	// The cumulative locations
	FVector Locations;

	// Adding locations of each boid
	for (auto boid : VisualBoidArray)
	{
		Locations += boid->GetActorLocation();
	}
	
	// Get the average location of the boids and assign as flocking center
	FVector FlockingCentre = Locations / VisualBoidArray.Num();

	// Get the direction of the flocking center
	FVector CenteringVector = GetActorLocation() - FlockingCentre;
	
	// Returns a normalized flock center direction vector depending on the centering weight
	return CenteringVector.GetSafeNormal() * CenteringWeight;
}

// Getting the Predator avoidance vector
FVector ABoid::PredatorAvoidance()
{
	FVector EscapeVector;

	// Check if there is a predator nearby
	if (VisualPredatorArray.Num() > 0)
	{
		// Get the direction to each predator
		for (auto predators : VisualPredatorArray)
		{
			FVector Direction = GetActorLocation() - predators->GetActorLocation();

			// Get the opposite direction to the predator
			EscapeVector += -Direction;
		}
	}

	// Returns a normalized escape direction vector depending on the Predator weight
	return EscapeVector.GetSafeNormal() * PredatorWeight;
}


void ABoid::Reset()
{
	PersonalBoidArray.Empty();
	VisualBoidArray.Empty();
	VisualPredatorArray.Empty();
	
	MoveSpeed = 100.0f;
}


// Relocate boid if it is out of bounds (wrap around)
void ABoid::Relocate()
{
	FVector NewPos;

	if (GetActorLocation().X < -3000)
	{
		NewPos.Set(GetActorLocation().X + 100, GetActorLocation().Y, GetActorLocation().Z);
	}
	if (GetActorLocation().X > 3000)
	{
		NewPos.Set(GetActorLocation().X - 100, GetActorLocation().Y, GetActorLocation().Z);
	}
	if (GetActorLocation().Y < -3000)
	{
		NewPos.Set(GetActorLocation().X, GetActorLocation().Y + 100, GetActorLocation().Z);
	}
	if (GetActorLocation().Y > 3000)
	{
		NewPos.Set(GetActorLocation().X, GetActorLocation().Y - 100, GetActorLocation().Z);
	}
	if (GetActorLocation().Z < -3000)
	{
		NewPos.Set(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + 100);
	}
	if (GetActorLocation().Z > 3000)
	{
		NewPos.Set(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z - 100);
	}
	
	SetActorLocation(-NewPos);
}


void ABoid::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                           int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	/*if (ABoid* OtherBoid = Cast<ABoid>(OtherActor))
	{
		IsAlive = false;
		SetActorHiddenInGame(true);

		if (!IsFitnessCalculated)
		{
			Fitness -= Fitness * 0.25;
			IsFitnessCalculated = true;
		}
	}*/
	
	if (APredator* Predator = Cast<APredator>(OtherActor))
	{
		IsAlive = false;
		SetActorHiddenInGame(true);

		if (!IsFitnessCalculated)
		{
			Fitness -= Fitness * 0.5;
			IsFitnessCalculated = true;
		}
	}

	if (AAsteroid* Asteroid = Cast<AAsteroid>(OtherActor))
	{
		IsAlive = false;
		SetActorHiddenInGame(true);

		if (!IsFitnessCalculated)
		{
			Fitness -= Fitness * 0.25;
			IsFitnessCalculated = true;
			IsAlive = false;
		}
	}

}
