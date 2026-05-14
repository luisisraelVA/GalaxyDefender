#include "GDDecoradorEscala.h"

void UGDDecoradorEscala::ModificarActor(AActor* ActorAModificar)
{
	// 1. Llamamos a la validación de la clase padre por seguridad
	Super::ModificarActor(ActorAModificar);

	// 2. Si el actor es válido, lo mutamos
	if (IsValid(ActorAModificar))
	{
		// Lo hacemos 3 veces más grande para que se note inmediatamente en pantalla
		ActorAModificar->SetActorScale3D(FVector(3.0f, 3.0f, 3.0f));

		UE_LOG(LogTemp, Warning, TEXT("Decorador Escala: Tamano del enemigo multiplicado x3."));
	}
}