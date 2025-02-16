#include "MainMenu_Activatable.h"

#include "Components/Button.h"

UMainMenu_Activatable::UMainMenu_Activatable(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bIsFocusable = true;
}
void UMainMenu_Activatable::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	OneButton->OnClicked.AddDynamic(this, &ThisClass::OnBtnClicked);
}

TOptional<FUIInputConfig> UMainMenu_Activatable::GetDesiredInputConfig() const
{
	FUIInputConfig Config{ ECommonInputMode::Menu, EMouseCaptureMode::NoCapture };
	return Config;
}

UWidget* UMainMenu_Activatable::NativeGetDesiredFocusTarget() const
{
	return OneButton;
}

void UMainMenu_Activatable::OnBtnClicked()
{
	UE_LOG(LogTemp, Error, TEXT("ButtonClicked for name %s"), *GetName());
}