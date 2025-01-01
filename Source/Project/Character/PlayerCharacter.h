// Ricrym Assignment

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class PROJECT_API APlayerCharacter : public ACharacterBase
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

//	virtual void Tick(float DeltaSeconds) override;
//
protected:
	void InitAbilitySystemComponent();
	void InitHUD() const;
};
