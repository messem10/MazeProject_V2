// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "MyHUD_V2.generated.h"

/**
 * 
 */
UCLASS()
class MAZE_API AMyHUD_V2 : public AHUD
{
	GENERATED_BODY()
	
public:
	AMyHUD_V2();
	AMyHUD_V2(const class FobjectInitializer &PCIP);
	
	UFont *MyFont;

	virtual void DrawHUD() override;
	
};
