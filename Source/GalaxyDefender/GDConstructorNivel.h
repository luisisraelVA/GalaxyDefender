// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GDConstructorNivel.generated.h"

/**
 * 
 */
UCLASS()
class GALAXYDEFENDER_API UGDConstructorNivel : public UObject
{
	GENERATED_BODY()
public:
	// Funciones que armarán el nivel paso a paso
	void ConstruirFondoEspacial();
	void ConstruirMeteoritos();
	void ConstruirEnemigosBasicos();
	void ConstruirPowerUps();
};
