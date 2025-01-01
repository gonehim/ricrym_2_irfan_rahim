// Ricrym Assignment


#include "UI/AttributesWidget.h"
#include "AbilitySystem/ProjectAttributeSet.h"
#include "Player/ProjectPlayerState.h"


void UAttributesWidget::BindToAttributes()
{
	const AProjectPlayerState* ProjectPlayerState = Cast<AProjectPlayerState>(GetOwningPlayerState());
	if (!ProjectPlayerState) return;

	UAbilitySystemComponent* ASC = ProjectPlayerState->GetAbilitySystemComponent();
	const UProjectAttributeSet* FabAS = ProjectPlayerState->GetAttributeSet();
	
	
	// Initial Attributes
	HealthPercent = NUMERIC_VALUE(FabAS, Health) / NUMERIC_VALUE(FabAS, MaxHealth);
	StaminaPercent = NUMERIC_VALUE(FabAS, Stamina) / NUMERIC_VALUE(FabAS, MaxStamina);

	// Attribute Changes
	ASC->GetGameplayAttributeValueChangeDelegate(FabAS->GetHealthAttribute()).AddLambda(
		[this, FabAS](const FOnAttributeChangeData& Data)
		{
			HealthPercent = Data.NewValue / NUMERIC_VALUE(FabAS, MaxHealth);
		});

	ASC->GetGameplayAttributeValueChangeDelegate(FabAS->GetStaminaAttribute()).AddLambda(
		[this, FabAS](const FOnAttributeChangeData& Data)
		{
			StaminaPercent = Data.NewValue / NUMERIC_VALUE(FabAS, MaxStamina);;
		});
}