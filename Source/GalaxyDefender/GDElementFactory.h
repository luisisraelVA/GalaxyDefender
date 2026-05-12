// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GDEnemyBase.h"
#include "GDEnemyBasic.h"
#include "GDObstacleBase.h"
#include "GDMeteorite.h"
#include "GDPowerUpBase.h"
#include "GDElementFactory.generated.h"

/**
 * 
 */
UCLASS()
class GALAXYDEFENDER_API UGDElementFactory : public UObject
{
	GENERATED_BODY()
	
public:
	UGDElementFactory();

	AGDEnemyBase* CrearEnemigoBasico(UWorld* World, const FVector& Posicion, const FRotator& Rotacion);

	AGDObstacleBase* CrearMeteorito(UWorld* World, const FVector& Posicion, const FRotator& Rotacion);

	AGDPowerUpBase* CrearPowerUpBase(UWorld* World, const FVector& Posicion, const FRotator& Rotacion);
};
