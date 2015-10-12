// Fill out your copyright notice in the Description page of Project Settings.

#include "maze.h"
#include "Pickup.h"


// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Structure to hold one-time initialization.
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> PickupMesh;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> PickupMaterial; //May need another wall material
		FConstructorStatics()
			: PickupMesh(TEXT("/Game/CreatedContent/Pickup_Stuff/PickupMesh.PickupMesh"))
			, PickupMaterial(TEXT("/Game/CreatedContent/Pickup_Stuff/PickupMaterial.PickupMaterial"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh0"));
	PickupMesh->SetStaticMesh(ConstructorStatics.PickupMesh.Get());
	PickupMesh->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));
	PickupMesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));

	PickupMesh->SetMaterial(0, ConstructorStatics.PickupMaterial.Get());

	//PickupMesh->SetSimulatePhysics(true);

	PickupMesh->AttachTo(DummyRoot);
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

