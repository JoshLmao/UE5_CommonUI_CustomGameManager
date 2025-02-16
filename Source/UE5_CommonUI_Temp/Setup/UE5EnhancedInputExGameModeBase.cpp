// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5EnhancedInputExGameModeBase.h"

#include "MainMenuHUD.h"
#include "UE5EnhancedInputPlayerController.h"

AUE5EnhancedInputExGameModeBase::AUE5EnhancedInputExGameModeBase()
{
	HUDClass = AMainMenuHUD::StaticClass();
	PlayerControllerClass = AUE5EnhancedInputPlayerController::StaticClass();
}

void AUE5EnhancedInputExGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	FString Error;
	auto P1 = GetGameInstance()->CreateInitialPlayer(Error);
	auto P2 = GetGameInstance()->CreateLocalPlayer(1, Error, true);
}