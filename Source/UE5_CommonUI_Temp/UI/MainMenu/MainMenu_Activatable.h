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
	UFUNCTION()
	void OnTwoBtnClicked();
	UFUNCTION()
	void OnThreeBtnClicked();
	UFUNCTION()
	void OnFourBtnClicked();

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* OneButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* TwoButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* ThreeButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* FourButton;

	void OpenCoopLandingForPlayer(int32 PlayerIndex);
};