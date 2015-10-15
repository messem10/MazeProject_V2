// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Crumb.h"
#include "GameFramework/Character.h"
#include "Avatar.generated.h"


UCLASS()
class MAZE_API AAvatar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAvatar();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// Taylor's Addition START
	int CrumbAvailable = 10;
	//TArray<ACrumb> CrumbArray;
	// Taylor's Addition END

	void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void MoveForward(float amount);
	void MoveRight(float amount);

	void Yaw(float amount);
	void Pitch(float amount);

	// Taylor's Addition START
	UFUNCTION(BlueprintCallable, Category = "Pawn|Character")
		void Jump();
	UFUNCTION(BlueprintCallable, Category = "Pawn|Character")
		void StopJumping();

	void SpawnCrumb();
	// Taylor's Addition END

	bool PickupFound = false;

	UFUNCTION()
		void OnHit(AActor *SelfActor, AActor *OtherActor, FVector NormalImpulse, const FHitResult &Hit);
	
};
