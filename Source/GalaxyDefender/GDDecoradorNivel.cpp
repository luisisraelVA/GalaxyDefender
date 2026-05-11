// Fill out your copyright notice in the Description page of Project Settings.

#include "GDDecoradorNivel.h"

void UGDDecoradorNivel::ModificarActor(AActor* ActorAModificar)
{
	// Verificamos que el actor exista antes de intentar hacerle algo
	if (!IsValid(ActorAModificar))
	{
		UE_LOG(LogTemp, Error, TEXT("Decorador Base: Se intento modificar un actor nulo o invalido."));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("Decorador Base: Analizando actor para futuras modificaciones..."));
}