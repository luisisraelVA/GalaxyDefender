// Fill out your copyright notice in the Description page of Project Settings.

#include "GDConstructorNivel.h"
#include "UGDRegistroNivel.h" 
#include "GDAlphaSectorFactory.h" // El archivo de Mari
#include "GDDecoradorEscala.h"
#include "Engine/World.h" // Necesario para GetWorld()

void UGDConstructorNivel::SetRegistro(UUGDRegistroNivel* EnRegistro)
{
	RegistroActual = EnRegistro;
}

void UGDConstructorNivel::ConstruirFondoEspacial()
{
	UE_LOG(LogTemp, Warning, TEXT("Constructor: Generando entorno espacial para la nave..."));
}

void UGDConstructorNivel::ConstruirMeteoritos()
{
	UWorld* World = GetWorld();

	// 1. Quitamos la validación estricta de FabricaAlfa aquí arriba
	if (!World || !RegistroActual)
	{
		UE_LOG(LogTemp, Error, TEXT("Constructor: Faltan referencias de Mundo o Registro."));
		return;
	}

	// 2. ¡EL ARREGLO! Si la fábrica no existe, la creamos justo ahora
	if (!FabricaAlfa)
	{
		FabricaAlfa = NewObject<UGDAlphaSectorFactory>(this);
		UE_LOG(LogTemp, Warning, TEXT("Constructor: FabricaAlfa instanciada desde Meteoritos."));
	}

	UE_LOG(LogTemp, Warning, TEXT("Constructor: Iniciando generacion del Campo de Meteoritos..."));

	for (int32 i = 0; i < 5; i++)
	{
		float PosY = FMath::RandRange(-1500.0f, 1500.0f);
		float PosZ = FMath::RandRange(-800.0f, 800.0f);
		FVector PosicionAleatoria = FVector(2000.0f + (i * 600.0f), PosY, PosZ);

		FRotator RotacionAleatoria = FRotator(FMath::RandRange(0.0f, 360.0f), FMath::RandRange(0.0f, 360.0f), FMath::RandRange(0.0f, 360.0f));

		// Solicitamos el obstáculo
		AActor* NuevoMeteorito = FabricaAlfa->CrearObstaculoPrincipal(World, PosicionAleatoria, RotacionAleatoria);

		if (NuevoMeteorito)
		{
			RegistroActual->RegistrarObstaculo(NuevoMeteorito);
		}
	}
}

void UGDConstructorNivel::ConstruirEnemigosBasicos()
{
	UE_LOG(LogTemp, Warning, TEXT("Constructor: Desplegando enemigos basicos..."));

	UWorld* World = GetWorld();

	// Validamos que tengamos mundo y registro
	if (!World || !RegistroActual)
	{
		UE_LOG(LogTemp, Error, TEXT("Constructor: Faltan referencias de Mundo o Registro."));
		return;
	}

	// Paso 4: Crear la instancia de UGDAlphaSectorFactory
	if (!FabricaAlfa)
	{
		FabricaAlfa = NewObject<UGDAlphaSectorFactory>(this);
	}

	// Posición temporal frente a la cámara para que lo veas
	FVector Posicion = FVector(800.0f, 0.0f, 0.0f);
	FRotator Rotacion = FRotator::ZeroRotator;

	// Pasos 5 y 6: Llamamos al método de Mari y recibimos el actor
	AActor* NuevoEnemigo = FabricaAlfa->CrearEnemigoPrincipal(World, Posicion, Rotacion);

	// Paso 7: Guardarlo en tu UUGDRegistroNivel
	if (NuevoEnemigo)
	{
		// ¡CAMBIO AQUÍ! Usamos la nueva función específica
		RegistroActual->RegistrarEnemigo(NuevoEnemigo);
		UE_LOG(LogTemp, Warning, TEXT("Constructor: ¡Enemigo guardado correctamente en la lista de Enemigos!"));
	}
}

void UGDConstructorNivel::ConstruirPowerUps()
{
	UWorld* World = GetWorld();

	if (!World || !RegistroActual) return;

	// Si la fábrica no existe, la instanciamos
	if (!FabricaAlfa)
	{
		FabricaAlfa = NewObject<UGDAlphaSectorFactory>(this);
	}

	UE_LOG(LogTemp, Warning, TEXT("Constructor: Desplegando Power-Ups en el sector..."));

	// Vamos a generar solo 2 Power-Ups flotando por ahí
	for (int32 i = 0; i < 2; i++)
	{
		float PosY = FMath::RandRange(-1000.0f, 1000.0f);
		float PosZ = FMath::RandRange(-500.0f, 500.0f);
		FVector Posicion = FVector(3000.0f + (i * 1000.0f), PosY, PosZ);
		FRotator Rotacion = FRotator::ZeroRotator;

		// Llamamos a la fábrica de Mari para que nos dé el PowerUp
		AActor* NuevoPowerUp = FabricaAlfa->CrearPowerUpPrincipal(World, Posicion, Rotacion);

		if (NuevoPowerUp)
		{
			// ¡Lo guardamos en la 3ra lista de tu Registro!
			RegistroActual->RegistrarPowerUp(NuevoPowerUp);
		}
	}
}