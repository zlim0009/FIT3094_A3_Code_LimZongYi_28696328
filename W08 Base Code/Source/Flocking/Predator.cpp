// Fill out your copyright notice in the Description page of Project Settings.


#include "Predator.h"
#include "Boid.h"
#include "ConstructorHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Materials/Material.h"

// Sets default values
APredator::APredator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Stuff for configuring materials and static mesh components
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	PredatorVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visible Component"));
	PredatorVisual->SetupAttachment(RootComponent);
	CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision Component"));
	CollisionComponent->SetupAttachment(PredatorVisual);

	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &APredator::OnOverlapBegin);

	//Get Sphere Mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded())
	{
		PredatorVisual->SetStaticMesh(SphereVisualAsset.Object);
	}

	//Get Material
	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("/Game/StarterContent/Materials/M_Concrete_Grime.M_Concrete_Grime"));
	if (FoundMaterial.Succeeded())
	{
		PredatorVisual->SetMaterial(0, FoundMaterial.Object);
	}

	// Setting default values
	MoveSpeed = 10.0f;
	IsEating = false;
}


// Called when the game starts or when spawned
void APredator::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APredator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Check if the predator is eating
	if (!IsEating)
	{
		FindNearestBoid();
		if (TargetBoid)
		{
			MoveToBoid(DeltaTime);
		}
	}
	// If it is eating
	else
	{
		// In 5 second stop eating
		if (FDateTime::UtcNow().ToUnixTimestamp() > TargetTime)
		{
			IsEating = false;
		}
	}
}

void APredator::MoveToBoid(float DeltaTime)
{
	FVector Direction = TargetBoid->GetActorLocation() - GetActorLocation();
	Direction.Normalize();

	//Update position based on direction and move MoveSpeed
	FVector NewPos = GetActorLocation() + Direction * MoveSpeed * DeltaTime;
	SetActorLocation(NewPos);
}

void APredator::FindNearestBoid()
{
	TArray<ABoid*> VisualBoidArray;

	// List of overlaps with other boids we are about to generate
	TArray<AActor*> mOverlaps;
	// We can define actors to ignore.
	TArray<AActor*> mIgnores;
	mIgnores.Add(this);

	// What objects are we looking for
	TArray<TEnumAsByte<EObjectTypeQuery>> objectTypes;
	objectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_GameTraceChannel1));
	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GetActorLocation(),
		5000.0f, objectTypes, NULL, mIgnores, mOverlaps);

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

	// Finding nearest boid
	for (auto Boids : VisualBoidArray)
	{
		if (Boids->IsAlive)
		{
			// If we already have a target
			if (TargetBoid)
			{
				// Check distance from current location to current stone resource and new stone resource
				if (FVector::Dist(Boids->GetActorLocation(), GetActorLocation()) <
					FVector::Dist(TargetBoid->GetActorLocation(), GetActorLocation()))
				{
					// If shorter, have new closest
					TargetBoid = Boids;
				}

			}
			else
			{

				// If nearest is null
				TargetBoid = Boids;

			}
		}	
	}
}


void APredator::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Check if overlapped is a boid
	if (ABoid* OverlappedBoid = Cast<ABoid>(OtherActor))
	{
		// Check if overlapped with is the target boid
		if (TargetBoid == OverlappedBoid)
		{
			// Change the state of the predator to be eating
			IsEating = true;

			// Set a timer to stop it from eating
			TargetTime = FDateTime::UtcNow().ToUnixTimestamp() + Timer;
		}
	}
}