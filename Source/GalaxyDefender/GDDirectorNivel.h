// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GDDirectorNivel.generated.h"


// Forward declaration para conectar con el Constructor
class UGDConstructorNivel;
/**
 * 
 */
UCLASS()
class GALAXYDEFENDER_API UGDDirectorNivel : public UObject
{
	GENERATED_BODY()
public:
	// Función que dirige al constructor según el nivel elegido
	void ConstruirNivel(int32 NumeroNivel, UGDConstructorNivel* ConstructorActual);
};
