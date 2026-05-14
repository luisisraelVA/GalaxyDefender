// Fill out your copyright notice in the Description page of Project Settings.


#include "GDAlphaSectorFactory.h"

UGDAlphaSectorFactory::UGDAlphaSectorFactory()
{
}

AGDEnemyBase* UGDAlphaSectorFactory::CrearEnemigoPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion)
{
	InicializarFactory();

	if (!ElementFactory)
	{
		UE_LOG(LogTemp, Error, TEXT("UGDAlphaSectorFactory no tiene ElementFactory."));
		return nullptr;
	}

	UE_LOG(LogTemp, Warning, TEXT("UGDAlphaSectorFactory creando enemigo principal del Sector Alfa."));

	return ElementFactory->CrearEnemigoBasico(World, Posicion, Rotacion);
}

AGDObstacleBase* UGDAlphaSectorFactory::CrearObstaculoPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion)
{
	InicializarFactory();

	if (!ElementFactory)
	{
		UE_LOG(LogTemp, Error, TEXT("UGDAlphaSectorFactory no tiene ElementFactory."));
		return nullptr;
	}

	UE_LOG(LogTemp, Warning, TEXT("UGDAlphaSectorFactory: Fabricando Meteorito para el Sector Alfa."));

	// ¡AQUI ESTA EL CAMBIO! Le pedimos al ElementFactory de Mari que nos dé el meteorito.
	// Asumo que su función se llama CrearMeteorito. Si le puso otro nombre, solo ajustalo.
	return ElementFactory->CrearMeteorito(World, Posicion, Rotacion);
}

AGDPowerUpBase* UGDAlphaSectorFactory::CrearPowerUpPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion)
{
	InicializarFactory();

	if (!ElementFactory)
	{
		UE_LOG(LogTemp, Error, TEXT("UGDAlphaSectorFactory no tiene ElementFactory."));
		return nullptr;
	}

	UE_LOG(LogTemp, Warning, TEXT("UGDAlphaSectorFactory creando power up básico del Sector Alfa."));

	return ElementFactory->CrearPowerUpBase(World, Posicion, Rotacion);
}

