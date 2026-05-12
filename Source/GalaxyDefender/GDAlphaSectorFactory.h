// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GDSectorAbstractFactory.h"
#include "GDAlphaSectorFactory.generated.h"

/**
 * 
 */
UCLASS()
class GALAXYDEFENDER_API UGDAlphaSectorFactory : public UGDSectorAbstractFactory
{
	GENERATED_BODY()
public:
	UGDAlphaSectorFactory();

	virtual AGDEnemyBase* CrearEnemigoPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion) override;

	virtual AGDObstacleBase* CrearObstaculoPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion) override;

	virtual AGDPowerUpBase* CrearPowerUpPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion) override;
};
