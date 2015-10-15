// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Crumb.generated.h"

UCLASS()
class MAZE_API ACrumb : public AActor
{
	GENERATED_BODY()

	/** Dummy root component */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRoot;

	/** StaticMesh component for the clickable block */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* CrumbMesh;

public:
	// Sets default values for this actor's properties
	ACrumb();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

public:
	/** Returns DummyRoot subobject **/
	FORCEINLINE class USceneComponent* GetDummyRoot() const { return DummyRoot; }
	/** Returns BlockMesh subobject **/
	FORCEINLINE class UStaticMeshComponent* GetCrumbMesh() const { return CrumbMesh; }

};
