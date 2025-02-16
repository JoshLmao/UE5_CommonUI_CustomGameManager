#pragma once

#include <CoreMinimal.h>
#include <GameFramework/HUD.h>
#include <GameplayTagContainer.h>

#include "MainMenuHUD.generated.h"

USTRUCT(BlueprintType)
struct FWidgetInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UCommonActivatableWidget> WidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag Layer;
};

UCLASS(Abstract)
class UE5_COMMONUI_TEMP_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OpenWidget(FGameplayTag WidgetTag);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<FGameplayTag, FWidgetInfo> UIConfig;

private:
	class UCommonActivatableWidget* ActiveActivatable;
};
