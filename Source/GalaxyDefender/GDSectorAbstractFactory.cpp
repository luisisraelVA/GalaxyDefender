// Fill out your copyright notice in the Description page of Project Settings.

#include "GDSectorAbstractFactory.h"

UGDSectorAbstractFactory::UGDSectorAbstractFactory()
{
	ElementFactory = nullptr;
}

void UGDSectorAbstractFactory::InicializarFactory()
{
	if (!ElementFactory)
	{
		ElementFactory = NewObject<UGDElementFactory>(this, UGDElementFactory::StaticClass());
		UE_LOG(LogTemp, Warning, TEXT("UGDSectorAbstractFactory inicializó UGDElementFactory."));
	}
}

AGDEnemyBase* UGDSectorAbstractFactory::CrearEnemigoPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion)
{
	InicializarFactory();

	UE_LOG(LogTemp, Warning, TEXT("UGDSectorAbstractFactory::CrearEnemigoPrincipal base. No crea enemigo específico."));

	return nullptr;
}

AGDObstacleBase* UGDSectorAbstractFactory::CrearObstaculoPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion)
{
	InicializarFactory();

	UE_LOG(LogTemp, Warning, TEXT("UGDSectorAbstractFactory::CrearObstaculoPrincipal base. No crea obstáculo específico."));

	return nullptr;
}

AGDPowerUpBase* UGDSectorAbstractFactory::CrearPowerUpPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion)
{
	InicializarFactory();

	UE_LOG(LogTemp, Warning, TEXT("UGDSectorAbstractFactory::CrearPowerUpPrincipal base. No crea power up específico."));

	return nullptr;
}

