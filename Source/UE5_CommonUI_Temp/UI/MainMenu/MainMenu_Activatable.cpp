#include "MainMenu_Activatable.h"

#include "Components/Button.h"

TOptional<FUIInputConfig> UMainMenu_Activatable::GetDesiredInputConfig() const
{
	FUIInputConfig Config{ ECommonInputMode::Menu, EMouseCaptureMode::NoCapture };
	return Config;
}

UWidget* UMainMenu_Activatable::NativeGetDesiredFocusTarget() const
{
	return OneButton;
}