

#pragma once

#include "CoreMinimal.h"
#include "Input/CommonUIActionRouterBase.h"
#include "MyCustomCommonUIActionRouterBase.generated.h"

/**
 * 
 */
UCLASS()
class UE5_COMMONUI_TEMP_API UMyCustomCommonUIActionRouterBase : public UCommonUIActionRouterBase
{
	GENERATED_BODY()

protected:
	virtual void SetActiveRoot(FActivatableTreeRootPtr NewActiveRoot) override;
};
