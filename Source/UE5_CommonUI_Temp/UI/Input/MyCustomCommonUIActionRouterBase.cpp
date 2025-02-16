

#include "MyCustomCommonUIActionRouterBase.h"

#include "CommonActivatableWidget.h"
#include "CommonUI/Private/Input/UIActionRouterTypes.h"

void UMyCustomCommonUIActionRouterBase::SetActiveRoot(FActivatableTreeRootPtr NewActiveRoot)
{
	Super::SetActiveRoot(NewActiveRoot);

	/**
	 *	Sync the active root across ALL local player's CommonUIActionRouterBase 
	 */

	if (!GetLocalPlayer()->IsPrimaryPlayer())
	{
		// prevent recursion, only primary can execute following logic
		return;
	}

	// Iterate other local players and set their root as same
	auto AllLocalPlayers = GetWorld()->GetGameInstance()->GetLocalPlayers();
	for (const auto LocalPlayer : AllLocalPlayers)
	{
		if (LocalPlayer->IsPrimaryPlayer())
		{
			continue;
		}

		auto TheirCommonUIActionRouterBase = LocalPlayer->GetSubsystem<UMyCustomCommonUIActionRouterBase>();
		TheirCommonUIActionRouterBase->SetActiveRoot(NewActiveRoot);

		UE_LOG(LogTemp, Log, TEXT("Set LocalPlayer %s (idx: %d) to ActiveRoot %s"), *LocalPlayer->GetName(), LocalPlayer->GetLocalPlayerIndex(),
			   NewActiveRoot.IsValid() ? *NewActiveRoot->GetWidget()->GetName() : TEXT("invalid"));
	}
}