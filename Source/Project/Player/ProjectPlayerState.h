// Ricrym Assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "ProjectPlayerState.generated.h"

class UProjectAbilitySystemComponent;
class UProjectAttributeSet;

UCLASS()
class PROJECT_API AProjectPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectPlayerState();


	//~IAbilitySystemInterface interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~End of IAbilitySystemInterface interface

	virtual UProjectAttributeSet* GetAttributeSet() const;

protected:

	UPROPERTY()
	TObjectPtr<UProjectAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UProjectAttributeSet> AttributeSet;

};
