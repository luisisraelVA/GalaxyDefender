// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h" // Necesario para que reconozca AActor
#include "UGDRegistroNivel.generated.h"

UCLASS()
class GALAXYDEFENDER_API UUGDRegistroNivel : public UObject
{
	GENERATED_BODY()

public:
	// Contenedor principal
	UPROPERTY()
	TArray<AActor*> ActoresDelNivel;

	void RegistrarActor(AActor* NuevoActor);
	void LimpiarRegistro();
};