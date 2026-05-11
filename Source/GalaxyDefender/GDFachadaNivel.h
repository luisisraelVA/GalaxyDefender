// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GDFachadaNivel.generated.h"

// Forward declarations de tu equipo de trabajo
class UUGDRegistroNivel;
class UGDConstructorNivel;
class UGDDirectorNivel;

UCLASS()
class GALAXYDEFENDER_API AGDFachadaNivel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGDFachadaNivel();
	// Controles principales que podrás llamar incluso desde Blueprints si lo necesitas
	UFUNCTION(BlueprintCallable, Category = "GalaxyDefender|Niveles")
	void IniciarNivel(int32 NumeroNivel);

	UFUNCTION(BlueprintCallable, Category = "GalaxyDefender|Niveles")
	void LimpiarNivelActual();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Punteros a los componentes de tu sistema
	UPROPERTY()
	UUGDRegistroNivel* Registro;

	UPROPERTY()
	UGDConstructorNivel* Constructor;

	UPROPERTY()
	UGDDirectorNivel* Director;
};
