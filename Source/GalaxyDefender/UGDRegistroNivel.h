// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "UGDRegistroNivel.generated.h"

UCLASS()
class GALAXYDEFENDER_API UUGDRegistroNivel : public UObject
{
	GENERATED_BODY()

public:
	// 1. Separamos por categorías usando estrictamente TArray
	UPROPERTY()
	TArray<AActor*> Enemigos;

	UPROPERTY()
	TArray<AActor*> Obstaculos;

	UPROPERTY()
	TArray<AActor*> PowerUps;

	// 2. Funciones específicas para cada lista
	void RegistrarEnemigo(AActor* NuevoEnemigo);
	void RegistrarObstaculo(AActor* NuevoObstaculo);
	void RegistrarPowerUp(AActor* NuevoPowerUp);

	// 3. Función de limpieza global
	void LimpiarRegistro();
};