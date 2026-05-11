// Fill out your copyright notice in the Description page of Project Settings.

#include "GDConstructorNivel.h"

void UGDConstructorNivel::ConstruirFondoEspacial()
{
	UE_LOG(LogTemp, Warning, TEXT("Constructor: Generando entorno espacial para la nave..."));
}

void UGDConstructorNivel::ConstruirMeteoritos()
{
	UE_LOG(LogTemp, Warning, TEXT("Constructor: Colocando meteoritos en la ruta..."));
}

void UGDConstructorNivel::ConstruirEnemigosBasicos()
{
	UE_LOG(LogTemp, Warning, TEXT("Constructor: Desplegando enemigos basicos..."));
}

void UGDConstructorNivel::ConstruirPowerUps()
{
	UE_LOG(LogTemp, Warning, TEXT("Constructor: Escondiendo Power Ups de escudo y disparo..."));
}