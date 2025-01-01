// Ricrym Assignment

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UObject/Object.h"
#include "AttributesWidget.generated.h"

/**
 *
 */
UCLASS()
class PROJECT_API UAttributesWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	void BindToAttributes();

protected:
	UPROPERTY(BlueprintReadOnly)
	float HealthPercent;

	UPROPERTY(BlueprintReadOnly)
	float StaminaPercent;
};