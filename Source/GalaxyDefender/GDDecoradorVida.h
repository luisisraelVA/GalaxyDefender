#pragma once

#include "CoreMinimal.h"
#include "GDDecoradorNivel.h"
#include "GDDecoradorVida.generated.h"

UCLASS()
class GALAXYDEFENDER_API UGDDecoradorVida : public UGDDecoradorNivel
{
	GENERATED_BODY()

public:
	// Sobrescribimos el método para aplicar el aumento de salud
	virtual void ModificarActor(AActor* ActorAModificar) override;
};