// Fill out your copyright notice in the Description page of Project Settings.

#include "SharedViewport_GameUIManager.h"

#include "CommonLocalPlayer.h"

void USharedViewport_GameUIManager::NotifyPlayerAdded(UCommonLocalPlayer* LocalPlayer)
{
	if (!LocalPlayer->IsPrimaryPlayer())
	{
		return;
	}

	Super::NotifyPlayerAdded(LocalPlayer);
}