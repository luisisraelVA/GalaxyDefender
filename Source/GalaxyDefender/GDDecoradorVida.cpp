#include "GDDecoradorVida.h"
#include "GDEnemyBase.h" // Incluimos la base de enemigos de Mari

void UGDDecoradorVida::ModificarActor(AActor* ActorAModificar)
{
	// 1. Validación base obligatoria
	Super::ModificarActor(ActorAModificar);

	if (IsValid(ActorAModificar))
	{
		// 2. Intentamos transformar el actor genérico en un enemigo de Mari
		AGDEnemyBase* Enemigo = Cast<AGDEnemyBase>(ActorAModificar);

		if (Enemigo)
		{
			// Le asignamos 5000 puntos de vida para transformarlo en un verdadero Boss indestructible
			// Nota: Ajusta 'SetVida' si Mari nombró la función de otra manera (ej. 'SetHealth' o 'Vida =')
			Enemigo->SetVida(5000.0f);

			UE_LOG(LogTemp, Warning, TEXT("Decorador Vida: ¡Atributo modificado! El enemigo ahora tiene 5000 de vida."));
		}
	}
}