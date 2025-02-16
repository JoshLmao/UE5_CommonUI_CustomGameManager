

#include "CoopPlayer_Landing.h"

#include "Components/Button.h"

TOptional<FUIInputConfig> UCoopPlayer_Landing::GetDesiredInputConfig() const
{
	FUIInputConfig Config{ ECommonInputMode::Menu, EMouseCaptureMode::NoCapture };
	return Config;
}

UWidget* UCoopPlayer_Landing::NativeGetDesiredFocusTarget() const
{
	return FirstBtn;
}

void UCoopPlayer_Landing::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	FirstBtn->OnClicked.AddDynamic(this, &ThisClass::OnFirstBtnClicked);
}

bool UCoopPlayer_Landing::NativeOnHandleBackAction()
{
	return Super::NativeOnHandleBackAction();
}

void UCoopPlayer_Landing::OnFirstBtnClicked()
{
	UE_LOG(LogTemp, Display, TEXT("OnFirstBtnClicked"));
}