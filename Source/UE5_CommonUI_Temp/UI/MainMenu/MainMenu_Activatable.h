#pragma once

#include <CoreMinimal.h>

#include "CommonActivatableWidget.h"

#include "MainMenu_Activatable.generated.h"

UCLASS(Abstract)
class UMainMenu_Activatable : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	virtual TOptional<FUIInputConfig> GetDesiredInputConfig() const override;

protected:
	virtual UWidget* NativeGetDesiredFocusTarget() const override;

private:
	UPROPERTY(meta=(BindWidget))
	class UButton* OneButton;
};