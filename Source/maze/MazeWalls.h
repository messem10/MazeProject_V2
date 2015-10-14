// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Pickup.h"
#include "MazeWalls.generated.h"

UCLASS()
class MAZE_API AMazeWalls : public AActor
{
	GENERATED_BODY()

	/* Dummy root component */
	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRoot;
	
public:	
	// Sets default values for this actor's properties
	AMazeWalls();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
};
