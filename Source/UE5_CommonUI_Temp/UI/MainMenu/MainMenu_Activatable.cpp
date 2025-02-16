#include "MainMenu_Activatable.h"

#include "Components/Button.h"
#include "UE5_CommonUI_Temp/Setup/MainMenuHUD.h"

UMainMenu_Activatable::UMainMenu_Activatable(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bIsFocusable = true;
}
void UMainMenu_Activatable::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	OneButton->OnClicked.AddDynamic(this, &ThisClass::OnBtnClicked);
	TwoButton->OnClicked.AddDynamic(this, &ThisClass::OnTwoBtnClicked);
	ThreeButton->OnClicked.AddDynamic(this, &ThisClass::OnThreeBtnClicked);
	FourButton->OnClicked.AddDynamic(this, &ThisClass::OnFourBtnClicked);
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
	UE_LOG(LogTemp, Error, TEXT("ButtonClicked for name %s - WONT open Coop Landing"), *GetName());
	//OpenCoopLandingForPlayer(0);
}

void UMainMenu_Activatable::OnTwoBtnClicked()
{
	OpenCoopLandingForPlayer(1);
}
void UMainMenu_Activatable::OnThreeBtnClicked()
{
	OpenCoopLandingForPlayer(2);
}

void UMainMenu_Activatable::OnFourBtnClicked()
{
	OpenCoopLandingForPlayer(3);
}

void UMainMenu_Activatable::OpenCoopLandingForPlayer(int32 PlayerIndex)
{
	const auto AllLocalPlayers = GetGameInstance()->GetLocalPlayers();
	const auto TheirHUD = AllLocalPlayers[PlayerIndex]->GetPlayerController(GetWorld())->GetHUD();
	const auto TheirMMHUD = Cast<AMainMenuHUD>(TheirHUD);
	TheirMMHUD->OpenWidget(FGameplayTag::RequestGameplayTag("UI.MainMenu.CoopPlayerLanding"));
}