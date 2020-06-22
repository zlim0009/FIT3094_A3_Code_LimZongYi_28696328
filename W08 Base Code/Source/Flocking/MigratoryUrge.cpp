// Fill out your copyright notice in the Description page of Project Settings.


#include "MigratoryUrge.h"


#include "Boid.h"
#include "ConstructorHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Materials/Material.h"

// Sets default values
AMigratoryUrge::AMigratoryUrge()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Stuff for configuring materials and static mesh components
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	MigratoryTargetVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visible Component"));
	MigratoryTargetVisual->SetupAttachment(RootComponent);
	
	//Get Sphere Mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (SphereVisualAsset.Succeeded())
	{
		MigratoryTargetVisual->SetStaticMesh(SphereVisualAsset.Object);
	}
	

	//Get Material
	static ConstructorHelpers::FObjectFinder<UMaterial> FoundMaterial(TEXT("/Game/StarterContent/Materials/M_Concrete_Poured.M_Concrete_Poured"));
	if (FoundMaterial.Succeeded())
	{
		MigratoryTargetVisual->SetMaterial(0, FoundMaterial.Object);
	}
}

// Called when the game starts or when spawned
void AMigratoryUrge::BeginPlay()
{
	Super::BeginPlay();

	// Set a timer for every 30 seconds and call the Move target function
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMigratoryUrge::MoveMigratoryTarget, 30.0f, true, 30.0f);
}

// Called every frame
void AMigratoryUrge::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Change the position of the target
void AMigratoryUrge::MoveMigratoryTarget()
{
	float RandomX = FMath::FRandRange(-3000, 3000);
	float RandomY = FMath::FRandRange(-3000, 3000);
	float RandomZ = FMath::FRandRange(-3000, 3000);

	FVector Position(RandomX, RandomY, RandomZ);
	SetActorLocation(Position);
	BoidCounter = 0;
}