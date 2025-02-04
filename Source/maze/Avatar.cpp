// Fill out your copyright notice in the Description page of Project Settings.

#include "maze.h"
#include "Avatar.h"
#include "Pickup.h"
#include "Crumb.h"


// Sets default values
AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->OnActorHit.AddDynamic(this, &AAvatar::OnHit);
}

// Called when the game starts or when spawned
void AAvatar::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAvatar::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

// Called to bind functionality to input
void AAvatar::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	//Super::SetupPlayerInputComponent(InputComponent);

	check(InputComponent);
	InputComponent->BindAxis("Forward", this, &AAvatar::MoveForward);
	InputComponent->BindAxis("Right", this, &AAvatar::MoveRight);

	InputComponent->BindAxis("Yaw", this, &AAvatar::Yaw);
	InputComponent->BindAxis("Pitch", this, &AAvatar::Pitch);

	InputComponent->BindAction("Jump", IE_Pressed, this, &AAvatar::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &AAvatar::StopJumping);

	InputComponent->BindAction("Crumb", IE_Pressed, this, &AAvatar::SpawnCrumb);
}

void AAvatar::MoveForward(float amount)
{
	if (Controller && amount)
	{
		FVector fwd = GetActorForwardVector();
		AddMovementInput(fwd, amount);
	}
}

void AAvatar::MoveRight(float amount)
{
	if (Controller && amount)
	{
		FVector right = GetActorRightVector();
		AddMovementInput(right, amount);
	}
}

void AAvatar::Yaw(float amount)
{
	AddControllerYawInput(100.f*amount*GetWorld()->GetDeltaSeconds());
}

void AAvatar::Pitch(float amount)
{
	AddControllerPitchInput(100.f*amount*GetWorld()->GetDeltaSeconds());
}

void AAvatar::Jump()
{
	bPressedJump = true;
	JumpKeyHoldTime = 0.0f;
}

void AAvatar::StopJumping()
{
	bPressedJump = false;
	JumpKeyHoldTime = 0.0f;
}

void AAvatar::SpawnCrumb()
{
	if (CrumbAvailable != 0 && GetActorLocation().Z <= 110.f) {
		const FVector CrumbLocation = FVector(GetActorLocation().X, GetActorLocation().Y, 200.f);

		// Original Line: ACrumb *NewCrumb = GetWorld()->SpawnActor<ACrumb>(CrumbLocation, FRotator(0, 0, 0));
		ACrumb *NewCrumb = GetWorld()->SpawnActor<ACrumb>(CrumbLocation, GetActorRotation());
		//CrumbArray.Add(&NewCrumb);
		CrumbAvailable--;
	}
}

void AAvatar::OnHit(AActor *SelfActor, AActor *OtherActor, FVector NormalImpulse, const FHitResult &Hit)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(0, 5.f, FColor::Blue, "Hit...");
		if (SelfActor)
			GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Blue, SelfActor->GetActorLabel());
		else if (OtherActor)
			GEngine->AddOnScreenDebugMessage(2, 5.f, FColor::Blue, OtherActor->GetActorLabel());

		// If OtherActor is a pickup, set the bool to true and remove the OtherActor.
		// This doesn't rely on things that are only available when you play it in the editor!
		if (OtherActor->IsA(APickup::StaticClass()))
		{
			PickupFound = true;
			//OtherActor->Destroy();
			GetWorld()->DestroyActor(OtherActor);
			GEngine->AddOnScreenDebugMessage(3, 5.f, FColor::Yellow, "You found the key!");
		}


		if (OtherActor->IsA(ACrumb::StaticClass()))
		{
			//OtherActor->Destroy();
			GetWorld()->DestroyActor(OtherActor);
			CrumbAvailable++;
		}

		// Now all we have to add is that the two walls move down
		//   and give an indication that it was hit other than the ball disappearing!

	}
}
