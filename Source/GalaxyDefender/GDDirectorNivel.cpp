// Fill out your copyright notice in the Description page of Project Settings.

#include "GDDirectorNivel.h"
#include "GDConstructorNivel.h" // Incluimos el constructor para poder usar sus funciones

void UGDDirectorNivel::ConstruirNivel(int32 NumeroNivel, UGDConstructorNivel* ConstructorActual)
{
	// Medida de seguridad: Si no hay constructor, abortamos.
	if (!ConstructorActual)
	{
		UE_LOG(LogTemp, Error, TEXT("Director: Constructor invalido, abortando mision."));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Director: Planificando Operacion Nebulosa - Nivel %d"), NumeroNivel);

	// El Director decide el orden de los pasos
	switch (NumeroNivel)
	{
	case 1:
		// Nivel 1: Sector Alfa (Introducción)
		ConstructorActual->ConstruirFondoEspacial();
		ConstructorActual->ConstruirEnemigosBasicos();
		break;

	case 2:
		// Nivel 2: Campo de Asteroides
		ConstructorActual->ConstruirFondoEspacial();
		ConstructorActual->ConstruirMeteoritos();
		ConstructorActual->ConstruirPowerUps(); // <- Aquí están los Power-Ups
		ConstructorActual->ConstruirEnemigosBasicos();
		break;

	default:
		UE_LOG(LogTemp, Warning, TEXT("Director: Nivel %d no configurado aun."), NumeroNivel);
		break;
	}
}