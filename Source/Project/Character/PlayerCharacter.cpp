// Ricrym Assignment


#include "Character/PlayerCharacter.h"
#include "AbilitySystem/ProjectAttributeSet.h"
#include "AbilitySystem/ProjectAbilitySystemComponent.h"
#include "Player/ProjectPlayerState.h"
#include "UI/ProjectHud.h"
#include "../../../Intermediate/ProjectFiles/ProjectMacros.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
//void APlayerCharacter::BeginPlay()
//{
//	Super::BeginPlay();
//
//
//	//Add logger for troubleshooting
//	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(__FUNCTION__));
//	UE_LOG(LogTemp, Warning, TEXT("PrimaryActorTick.bCanEverTick = %s"), PrimaryActorTick.bCanEverTick ? TEXT("true") : TEXT("false"));
//
//	PRINT("Hello, %s", *FString(__FUNCTION__));
//	FVector TargetLocation(2200.f, 700.f, 150.f);
//	SPHERE(TargetLocation);
//	LINE(GetActorLocation(), TargetLocation);
//	
//}
//
//void APlayerCharacter::Tick(float DeltaSeconds)
//{
//	Super::Tick(DeltaSeconds);
//	SPHERE_TICK(GetActorLocation());
//	LINE_TICK(GetActorLocation(), FVector(2200.f, 700.f, 150.f));
//}


void APlayerCharacter::PossessedBy(AController* NewController)
{/*
	Super::Tick(DeltaSeconds);
	SPHERE_TICK(GetActorLocation());
	LINE_TICK(GetActorLocation(), FVector(2200.f, 700.f, 150.f));*/
	Super::PossessedBy(NewController);

	InitAbilitySystemComponent();
	GiveDefaultAbilities();
	InitDefaultAttributes();
	InitHUD();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilitySystemComponent();
	InitDefaultAttributes();
	InitHUD();
}


void APlayerCharacter::InitAbilitySystemComponent()
{
	AProjectPlayerState* ProjectPlayerState = GetPlayerState<AProjectPlayerState>();
	check(ProjectPlayerState);
	AbilitySystemComponent = CastChecked<UProjectAbilitySystemComponent>(
		ProjectPlayerState->GetAbilitySystemComponent());
	AbilitySystemComponent->InitAbilityActorInfo(ProjectPlayerState, this);
	AttributeSet = ProjectPlayerState->GetAttributeSet();
}

void APlayerCharacter::InitHUD() const
{
	if (const APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (AProjectHud* ProjectHud = Cast<AProjectHud>(PlayerController->GetHUD()))
		{
			ProjectHud->Init();
		}
	}
}
