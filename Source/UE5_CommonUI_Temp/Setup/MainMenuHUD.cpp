#include "MainMenuHUD.h"

#include <Blueprint/UserWidget.h>

#include "CommonActivatableWidget.h"
#include "PrimaryGameLayout.h"

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	FInputModeUIOnly InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::LockInFullscreen);
	GetOwningPlayerController()->SetInputMode(InputModeData);

	// Open our landing menu at start
	auto LocalPlayer = GetOwningPlayerController()->GetLocalPlayer();
	if (LocalPlayer->IsPrimaryPlayer())
	{
		OpenWidget(FGameplayTag::RequestGameplayTag("UI.MainMenu.Landing"));
	}
	// Uncomment to open on start for other local players
	// else
	// {
	// 	OpenWidget(FGameplayTag::RequestGameplayTag("UI.MainMenu.CoopPlayerLanding"));
	// }
}

void AMainMenuHUD::OpenWidget(FGameplayTag WidgetTag)
{
	checkf(UIConfig.Contains(WidgetTag), TEXT("Doesnt have tag!"));

	auto OwningLocalPlayer = GetOwningPlayerController()->GetLocalPlayer();
	auto PrimaryLocalPlayer = GetWorld()->GetFirstPlayerController()->GetLocalPlayer();
	if (UPrimaryGameLayout* RootLayout = UPrimaryGameLayout::GetPrimaryGameLayout(PrimaryLocalPlayer))
	{
		if (IsValid(ActiveActivatable))
		{
			RootLayout->FindAndRemoveWidgetFromLayer(ActiveActivatable);
		}

		// clang-format off
		auto lambda = [this, OwningLocalPlayer](UCommonActivatableWidget& Widget)
		{
			UE_LOG(LogTemp, Log, TEXT("%s Activatable owned by local player %s - idx: %d"), *Widget.GetName(), *OwningLocalPlayer->GetName(), OwningLocalPlayer->GetLocalPlayerIndex());
			Widget.SetPlayerContext(FLocalPlayerContext(OwningLocalPlayer));
		};
		// clang-format on
		ActiveActivatable = RootLayout->PushWidgetToLayerStack<UCommonActivatableWidget>(UIConfig[WidgetTag].Layer, UIConfig[WidgetTag].WidgetClass, lambda);
	}
}
