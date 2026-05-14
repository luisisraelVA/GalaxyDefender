// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GDConstructorNivel.generated.h"


class UUGDRegistroNivel;
class UGDAlphaSectorFactory;
/**
 * 
 */
UCLASS()
class GALAXYDEFENDER_API UGDConstructorNivel : public UObject
{
	GENERATED_BODY()
public:
	
	void ConstruirFondoEspacial();
	void ConstruirMeteoritos();
	void ConstruirEnemigosBasicos();
	void ConstruirPowerUps();
	void SetRegistro(UUGDRegistroNivel* EnRegistro);

private:
	// Punteros para la integración
	UPROPERTY()
	UUGDRegistroNivel* RegistroActual;

	UPROPERTY()
	UGDAlphaSectorFactory* FabricaAlfa;
};
