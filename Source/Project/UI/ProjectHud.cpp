// Ricrym Assignment


#include "UI/ProjectHud.h"
#include "AttributesWidget.h"

void AProjectHud::Init()
{
	AttributeWidget = CreateWidget<UAttributesWidget>(GetOwningPlayerController(), AttributeWidgetClass);
	AttributeWidget->BindToAttributes();
	AttributeWidget->AddToViewport();
}
