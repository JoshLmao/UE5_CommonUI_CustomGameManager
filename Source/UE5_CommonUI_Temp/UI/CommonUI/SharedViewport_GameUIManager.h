// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameUIManagerSubsystem.h"
#include "SharedViewport_GameUIManager.generated.h"

/**
 * 
 */
UCLASS()
class UE5_COMMONUI_TEMP_API USharedViewport_GameUIManager : public UGameUIManagerSubsystem
{
	GENERATED_BODY()

public:
	virtual void NotifyPlayerAdded(UCommonLocalPlayer* LocalPlayer) override;
};
