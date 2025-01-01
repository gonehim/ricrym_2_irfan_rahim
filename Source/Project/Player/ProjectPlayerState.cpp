// Ricrym Assignment


#include "Player/ProjectPlayerState.h"
#include "AbilitySystem/ProjectAttributeSet.h"
#include "AbilitySystem/ProjectAbilitySystemComponent.h"

// Sets default values
AProjectPlayerState::AProjectPlayerState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	NetUpdateFrequency = 100.f;


	AbilitySystemComponent = CreateDefaultSubobject<UProjectAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<UProjectAttributeSet>("AttributeSet");

}

UAbilitySystemComponent* AProjectPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UProjectAttributeSet* AProjectPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}

// Called when the game starts or when spawned
//void AProjectPlayerState::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}
//
//// Called every frame
//void AProjectPlayerState::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

