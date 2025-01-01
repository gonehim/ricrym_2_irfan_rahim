// Ricrym Assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Hud.h"
#include "ProjectHud.generated.h"

class UAttributesWidget;
/**
 *
 */
UCLASS()
class PROJECT_API AProjectHud : public AHUD
{
	GENERATED_BODY()
public:
	void Init();

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAttributesWidget> AttributeWidgetClass;
private:
	UPROPERTY()
	TObjectPtr<UAttributesWidget> AttributeWidget;
};