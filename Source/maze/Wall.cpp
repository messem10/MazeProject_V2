// Fill out your copyright notice in the Description page of Project Settings.

#include "maze.h"
#include "Wall.h"


// Sets default values
AWall::AWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	// Structure to hold one-time initialization.
	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> WallMesh;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> WallMaterial; //May need another wall material
		FConstructorStatics()
			: WallMesh(TEXT("/Game/CreatedContent/WallMesh.WallMesh"))
			, WallMaterial(TEXT("/Game/CreatedContent/WallMaterial.WallMaterial"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	WallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WallMesh0"));
	WallMesh->SetStaticMesh(ConstructorStatics.WallMesh.Get());
	WallMesh->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));
	WallMesh->SetRelativeLocation(FVector(0.f, 0.f, 25.f));

	WallMesh->SetMaterial(0, ConstructorStatics.WallMaterial.Get());

	//WallMesh->SetSimulatePhysics(true);

	WallMesh->AttachTo(DummyRoot);

}

// Called when the game starts or when spawned
void AWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWall::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

