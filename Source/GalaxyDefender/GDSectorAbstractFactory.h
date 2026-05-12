// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GDElementFactory.h"
#include "GDSectorAbstractFactory.generated.h"

/**
 * 
 */
UCLASS()
class GALAXYDEFENDER_API UGDSectorAbstractFactory : public UObject
{
	GENERATED_BODY()
public:
	UGDSectorAbstractFactory();

protected:
	UPROPERTY()
	UGDElementFactory* ElementFactory;

public:
	virtual void InicializarFactory();

	virtual AGDEnemyBase* CrearEnemigoPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion);

	virtual AGDObstacleBase* CrearObstaculoPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion);

	virtual AGDPowerUpBase* CrearPowerUpPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion);
};

