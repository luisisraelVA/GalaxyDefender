// Fill out your copyright notice in the Description page of Project Settings.

#include "UGDRegistroNivel.h" // Este es el archivo que Unreal te generó

void UUGDRegistroNivel::RegistrarActor(AActor* NuevoActor)
{
	if (IsValid(NuevoActor))
	{
		ActoresDelNivel.Add(NuevoActor);
		UE_LOG(LogTemp, Warning, TEXT("Registro: Actor añadido. Total en nivel: %d"), ActoresDelNivel.Num());
	}
}

void UUGDRegistroNivel::LimpiarRegistro()
{
	for (AActor* Actor : ActoresDelNivel)
	{
		if (IsValid(Actor))
		{
			Actor->Destroy();
		}
	}

	ActoresDelNivel.Empty();
	UE_LOG(LogTemp, Warning, TEXT("Registro: Todos los actores del nivel han sido eliminados."));
}