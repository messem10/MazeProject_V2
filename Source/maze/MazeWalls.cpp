// Fill out your copyright notice in the Description page of Project Settings.

#include "maze.h"
#include "MazeWalls.h"
#include "Wall.h"
#include "Pickup.h"

// Sets default values
AMazeWalls::AMazeWalls()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;
}

// Called when the game starts or when spawned
void AMazeWalls::BeginPlay()
{
	Super::BeginPlay();
	
	// Spawn a wall. (Same idea as in the puzzle code!)
	const FVector WallLocation = FVector(10.f, 10.f, 0.f) + GetActorLocation();
	AWall* NewWall = GetWorld()->SpawnActor<AWall>(WallLocation, FRotator(0, 0, 0));

	// Randomly places a pickup/key in the maze for the player to find. 
	// NOTE: Need to ensure that it does not spawn in the start nor the end areas!!!
	int NumBlocks = 10; // CHANGE THIS FOR MAP SIZE, ASSUMING SQUARE!!!
	int PickupX = FMath::RandRange(0, NumBlocks - 1) * 400 + 200;
	int PickupY = FMath::RandRange(0, NumBlocks - 1) * 400 + 200;

	const FVector PickupLocation = FVector((float)PickupX, (float)PickupY, 100.f);
	APickup* NewPickup = GetWorld()->SpawnActor<APickup>(PickupLocation, FRotator(0, 0, 0));

	 // Spits out the wall's position to the screen.
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Red, "Start Point" + WallLocation.ToString());


	/* HOW TO CREATE THE WALLS BASED OFF OF POINTS
		----------------------------------------

		Since the initialization point for our walls are in the bottom middle of it and it extends in the X direction by 400 units treat that as point #1. 
			(Yes, X-axis is forward. I checked before writing it all out) The important one is point #2 and it is easy to determine how and where it should go:

		if(py1 == py2)
		{
			if(px1 < px2)
				// Left Wall (No rotation)
			else
				// Right wall (180 degree rotation around Z axis)
				// This puts the initialization point to the upper right of the "box"
		}else{ 
			// No need to check x since we are generating it per box/tile!
			if(py1 < py2)
				// Top wall (90 degree around Z-axis)
			else
				// Bottom wall (270 degree around Z-axis)
		}

		If you want an image, check below:

			Top
			*---># *
			#	   |
	Left	|	   | Right
			*	   V
			#<---* #

			NOTE: CORNERS ARE THE SAME LOCATION, but:
				* is Point 1
				# is Point 2
	*/
}

// Called every frame
void AMazeWalls::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

