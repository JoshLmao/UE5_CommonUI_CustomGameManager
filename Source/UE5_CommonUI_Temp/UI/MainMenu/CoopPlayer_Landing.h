

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CoopPlayer_Landing.generated.h"

/**
 * 
 */
UCLASS()
class UE5_COMMONUI_TEMP_API UCoopPlayer_Landing : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	virtual TOptional<FUIInputConfig> GetDesiredInputConfig() const override;

protected:
	virtual UWidget* NativeGetDesiredFocusTarget() const override;
	virtual void NativeOnInitialized() override;
	virtual bool NativeOnHandleBackAction() override;

	UFUNCTION()
	void OnFirstBtnClicked();

public:
	UPROPERTY(meta = (BindWidget))
	class UButton* FirstBtn;
};
