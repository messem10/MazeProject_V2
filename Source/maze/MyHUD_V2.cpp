// Fill out your copyright notice in the Description page of Project Settings.

/*
#include "maze.h"
#include "Avatar.h"
#include "MyHUD_V2.h"


AMyHUD_V2::AMyHUD_V2(const class FObjectInitializer& PCIP) : Super(PCIP)
{
	static ConstructorHelpers::FObjectFinder<UFont>HUDFontOb(TEXT("/Engine/EngineFonts/Roboto"));
	MyFont = HUDFontOb.Object;
}

void AMyHUD_V2::DrawHUD()
{
	FVector2D ScreenSize = FVector2D(Canvas->SizeX, Canvas->SizeY);
	Super::DrawHUD();

	TActorIterator<AAvatar>Avatar = TActorIterator<AAvatar>(GetWorld());

	// Avatar->#BREADCRUMBS
	DrawText(FString(""), FColor::Green, 0, 0, MyFont);
}
*/