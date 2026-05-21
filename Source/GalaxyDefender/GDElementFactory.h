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
    // Enemigos
    AGDEnemyBase* CrearEnemyFast(UWorld* Mundo, FVector Posicion);
    AGDEnemyBase* CrearEnemyBasic(UWorld* Mundo, FVector Posicion);
    AGDEnemyBase* CrearEnemyTank(UWorld* Mundo, FVector Posicion);
    AGDEnemyBase* CrearEnemyShooter(UWorld* Mundo, FVector Posicion);
    AGDEnemyBase* CrearEnemyBoss(UWorld* Mundo, FVector Posicion);

    // PowerUps
    AGDPowerUpBase* CrearPowerUpShield(UWorld* Mundo, FVector Posicion);
    AGDPowerUpBase* CrearPowerUpDoubleShot(UWorld* Mundo, FVector Posicion);
    AGDPowerUpBase* CrearPowerUpSpeed(UWorld* Mundo, FVector Posicion);

    TSubclassOf<class AGDObstacleBase> ClaseMeteoritoBP;
};
