// Fill out your copyright notice in the Description page of Project Settings.

#include "maze.h"
#include "Avatar.h"
#include "Pickup.h"


// Sets default values
AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
			OtherActor->K2_DestroyActor();
			GEngine->AddOnScreenDebugMessage(3, 5.f, FColor::Yellow, "You found the key!");
		}

		/*
		if (OtherActor->IsA(ACrumb::StaticClass()))
		{
			OtherActor->K2_DestroyActor();
			// Add it back to additional crumbs
		}
		*/

		// Now all we have to add is that the two walls move down
		//   and give an indication that it was hit other than the ball disappearing!


		/* //ROTATION CODE (We don't need this!)
		if (OtherActor)
		{
			FRotator ActorRotator = OtherActor->GetActorRotation();
			//ActorRotator.Yaw += 2;
			//OtherActor->SetActorRotation(ActorRotator);

			FVector x;
			x = FVector::CrossProduct(OtherActor->GetActorRightVector(), SelfActor->GetActorForwardVector());

			if (x.Z > 0)
				ActorRotator.Yaw += 2;
			else
				ActorRotator.Yaw -= 2;

			OtherActor->SetActorRotation(ActorRotator);

		}
		*/
	}
}
