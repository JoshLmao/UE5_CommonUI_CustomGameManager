#pragma once

#include <CoreMinimal.h>

#include "CommonActivatableWidget.h"

#include "MainMenu_Activatable.generated.h"

UCLASS(Abstract)
class UMainMenu_Activatable : public UCommonActivatableWidget
{
	GENERATED_BODY()

	UMainMenu_Activatable(const class FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeOnInitialized() override;

public:
	virtual TOptional<FUIInputConfig> GetDesiredInputConfig() const override;

protected:
	virtual UWidget* NativeGetDesiredFocusTarget() const override;

	UFUNCTION()
	void OnBtnClicked();

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* OneButton;
};