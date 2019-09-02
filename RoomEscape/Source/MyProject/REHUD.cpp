// Fill out your copyright notice in the Description page of Project Settings.


#include "REHUD.h"

AREHUD::AREHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Set the crosshair texure
	static ConstructorHelpers::FObjectFinder<UTexture2D> CrosshairTexObj(TEXT("Texture2D'/Game/Blueprints/crosshair.crosshair'"));
	CrosshairTex = CrosshairTexObj.Object;
}

void AREHUD::DrawHUD()
{
	Super::DrawHUD();
	// Draw crosshair and find center of the canvas
	const FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);
	// Offset by half the texture's dimension so that the center of the texture aligns with the center fo the Canvas
	const FVector2D CrosshairDrawPosition((Center.X - (CrosshairTex->GetSurfaceWidth() * 0.5f)),
		(Center.Y - (CrosshairTex->GetSurfaceHeight() * 0.5f)));
	// Draw the crosshair
	FCanvasTileItem TileItem(CrosshairDrawPosition, CrosshairTex->Resource, FLinearColor::White);
	TileItem.BlendMode = SE_BLEND_Translucent;
	Canvas->DrawItem(TileItem);
}