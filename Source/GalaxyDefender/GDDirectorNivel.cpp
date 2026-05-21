#include "GDDirectorNivel.h"
#include "GDConstructorNivel.h"
#include "GDAlphaSectorFactory.h" // Fábrica Nivel 2
#include "GDBossSectorFactory.h"  // Fábrica Nivel 3 (Nueva)

void UGDDirectorNivel::ConstruirNivel(int32 NumeroNivel, UGDConstructorNivel* ConstructorActual)
{
	if (!ConstructorActual) return;

	// 1. El Director decide qué fábrica manufacturará las piezas de este nivel
	UGDSectorAbstractFactory* FabricaDelNivel = nullptr;

	if (NumeroNivel == 1 || NumeroNivel == 2)
	{
		FabricaDelNivel = NewObject<UGDAlphaSectorFactory>(ConstructorActual);
	}
	else if (NumeroNivel == 3)
	{
		FabricaDelNivel = NewObject<UGDBossSectorFactory>(ConstructorActual);
	}

	// 2. Inyectamos la factoría elegida en el Constructor
	ConstructorActual->SetFabricaActual(FabricaDelNivel);

	// 3. Ejecutamos los pasos de construcción según el plano del nivel
	// El Director decide el orden de los pasos
	switch (NumeroNivel)
	{
	case 1:
		// Nivel 1: Sector Alfa (Introducción completa y automática)
		ConstructorActual->ConstruirFondoEspacial();
		ConstructorActual->ConstruirMeteoritos();     // ¡Añadido! Genera rocas automáticas
		ConstructorActual->ConstruirPowerUps();       // ¡Añadido! Distribuye cápsulas de ayuda
		ConstructorActual->ConstruirEnemigosBasicos(); // Ahora creará un escuadrón esparcido
		break;

	case 2:
		// Nivel 2: Campo de Asteroides Pesado
		ConstructorActual->ConstruirFondoEspacial();
		ConstructorActual->ConstruirMeteoritos();
		ConstructorActual->ConstruirPowerUps();
		ConstructorActual->ConstruirEnemigosBasicos();
		break;

	case 3:
		// Nivel 3: Sector del Jefe Final
		ConstructorActual->ConstruirFondoEspacial();
		ConstructorActual->ConstruirPowerUps();
		ConstructorActual->ConstruirEnemigosBasicos();
		break;

	default:
		UE_LOG(LogTemp, Warning, TEXT("Director: Nivel %d no configurado aun."), NumeroNivel);
		break;
	}
}