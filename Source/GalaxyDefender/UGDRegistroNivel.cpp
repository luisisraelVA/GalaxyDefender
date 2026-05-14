// Fill out your copyright notice in the Description page of Project Settings.

#include "UGDRegistroNivel.h"

void UUGDRegistroNivel::RegistrarEnemigo(AActor* NuevoEnemigo)
{
	if (IsValid(NuevoEnemigo))
	{
		Enemigos.Add(NuevoEnemigo);
		UE_LOG(LogTemp, Warning, TEXT("Registro: Enemigo clasificado. Total de Enemigos: %d"), Enemigos.Num());
	}
}

void UUGDRegistroNivel::RegistrarObstaculo(AActor* NuevoObstaculo)
{
	if (IsValid(NuevoObstaculo))
	{
		Obstaculos.Add(NuevoObstaculo);
		UE_LOG(LogTemp, Warning, TEXT("Registro: Obstaculo clasificado. Total de Obstaculos: %d"), Obstaculos.Num());
	}
}

void UUGDRegistroNivel::RegistrarPowerUp(AActor* NuevoPowerUp)
{
	if (IsValid(NuevoPowerUp))
	{
		PowerUps.Add(NuevoPowerUp);
		UE_LOG(LogTemp, Warning, TEXT("Registro: PowerUp clasificado. Total de PowerUps: %d"), PowerUps.Num());
	}
}

void UUGDRegistroNivel::LimpiarRegistro()
{
	// Vaciamos Enemigos
	for (AActor* Actor : Enemigos)
	{
		if (IsValid(Actor)) Actor->Destroy();
	}
	Enemigos.Empty();

	// Vaciamos Obstáculos
	for (AActor* Actor : Obstaculos)
	{
		if (IsValid(Actor)) Actor->Destroy();
	}
	Obstaculos.Empty();

	// Vaciamos PowerUps
	for (AActor* Actor : PowerUps)
	{
		if (IsValid(Actor)) Actor->Destroy();
	}
	PowerUps.Empty();

	UE_LOG(LogTemp, Warning, TEXT("Registro: Memoria liberada. Sector completamente limpio."));
}