// Fill out your copyright notice in the Description page of Project Settings.

#include "GDFachadaNivel.h"
#include "UGDRegistroNivel.h" // El archivo de tu registro
#include "GDConstructorNivel.h"
#include "GDDirectorNivel.h"

AGDFachadaNivel::AGDFachadaNivel()
{
	// No necesitamos que la fachada se actualice cada frame
	PrimaryActorTick.bCanEverTick = false;
}

void AGDFachadaNivel::BeginPlay()
{
	Super::BeginPlay();

	// Creamos las instancias de tu equipo de trabajo
	Registro = NewObject<UUGDRegistroNivel>(this);
	Constructor = NewObject<UGDConstructorNivel>(this);
	Director = NewObject<UGDDirectorNivel>(this);

	Constructor->SetRegistro(Registro);

	UE_LOG(LogTemp, Warning, TEXT("Fachada: Sistema Operacion Nebulosa inicializado y listo."));

	IniciarNivel(2);
}

void AGDFachadaNivel::IniciarNivel(int32 NumeroNivel)
{
	if (Director && Constructor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Fachada: Solicitando creacion del nivel %d..."), NumeroNivel);

		// 1. Limpiamos lo que haya del nivel anterior
		LimpiarNivelActual();

		// 2. Le damos la orden al director
		Director->ConstruirNivel(NumeroNivel, Constructor);
	}
}

void AGDFachadaNivel::LimpiarNivelActual()
{
	if (Registro)
	{
		UE_LOG(LogTemp, Warning, TEXT("Fachada: Ordenando limpieza al Registro..."));
		Registro->LimpiarRegistro();
	}
}