#pragma once

#include "CoreMinimal.h"
#include "GDDecoradorNivel.h" // Heredamos de tu decorador base
#include "GDDecoradorEscala.generated.h"

UCLASS()
class GALAXYDEFENDER_API UGDDecoradorEscala : public UGDDecoradorNivel
{
	GENERATED_BODY()

public:
	// Usamos override porque estamos sobreescribiendo el método virtual de tu clase padre
	virtual void ModificarActor(AActor* ActorAModificar) override;
};