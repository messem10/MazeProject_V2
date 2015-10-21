// Fill out your copyright notice in the Description page of Project Settings.

#include "maze.h"
#include "Crumb.h"


// Sets default values
ACrumb::ACrumb()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	// PrimaryActorTick.bCanEverTick = true;

	struct FConstructorStatics
	{
		ConstructorHelpers::FObjectFinderOptional<UStaticMesh> CrumbMesh;
		ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> CrumbMaterial;
		FConstructorStatics()
			: CrumbMesh(TEXT("/Game/CreatedContent/Crumb_Stuff/CrumbMesh.CrumbMesh"))
			, CrumbMaterial(TEXT("/Game/CreatedContent/Crumb_Stuff/CrumbMaterial.CrumbMaterial"))
		{
		}
	};
	static FConstructorStatics ConstructorStatics;

	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	CrumbMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CrumbMesh0"));
	CrumbMesh->SetStaticMesh(ConstructorStatics.CrumbMesh.Get());
	CrumbMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.25f));
	CrumbMesh->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	CrumbMesh->SetMaterial(0, ConstructorStatics.CrumbMaterial.Get());
	CrumbMesh->AttachTo(DummyRoot);
}

// Called when the game starts or when spawned
void ACrumb::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACrumb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

