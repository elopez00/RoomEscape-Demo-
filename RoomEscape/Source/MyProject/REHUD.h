// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h"
#include "UObject/ConstructorHelpers.h"
#include "REHUD.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AREHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AREHUD(const FObjectInitializer& ObjectInitialzer);
	virtual void DrawHUD() override;

private:
	UTexture2D* CrosshairTex;
};
