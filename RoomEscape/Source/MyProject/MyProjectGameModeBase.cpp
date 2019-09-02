// Fill out your copyright notice in the Description page of Project Settings.


#include "MyProjectGameModeBase.h"
#include "ConstructorHelpers.h"
#include "REHUD.h"

AMyProjectGameModeBase::AMyProjectGameModeBase(const class FObjectInitializer &ObjectInitializer)
	:Super(ObjectInitializer)
{
	//set default pawn class Blueprinted copy
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("Pawn'/Game/Blueprints/BP_RECharacterBase.BP_RECharacterBase_C'"));
	if (PlayerPawnObject.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnObject.Class;
	}

	HUDClass = AREHUD::StaticClass();
}
