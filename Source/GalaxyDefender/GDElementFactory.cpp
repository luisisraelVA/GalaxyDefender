// Fill out your copyright notice in the Description page of Project Settings.


#include "GDElementFactory.h"
#include "GDEnemyFast.h"
#include "GDEnemyBasic.h"
#include "GDEnemyTank.h"
#include "GDEnemyShooter.h"
#include "GDEnemyBoss.h"
#include "GDPowerUpShield.h"
#include "GDPowerUpDoubleShot.h"
#include "GDPowerUpSpeed.h"
#include "Engine/World.h"

UGDElementFactory::UGDElementFactory()
{
	// ARREGLO 1: Ruta limpia, sin "Blueprint" y terminando en _C
	static ConstructorHelpers::FClassFinder<AGDObstacleBase> ObjetoMeteorito(TEXT("/Game/Modelos3D/BP_Meteorito.BP_Meteorito_C"));

	if (ObjetoMeteorito.Succeeded())
	{
		ClaseMeteoritoBP = ObjetoMeteorito.Class;
		UE_LOG(LogTemp, Warning, TEXT("Fabrica Elementos: ¡BP_Meteorito encontrado y cargado con exito!"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Fabrica Elementos: No se pudo encontrar la ruta de BP_Meteorito."));
	}
}

AGDEnemyBase* UGDElementFactory::CrearEnemigoBasico(UWorld* World, const FVector& Posicion, const FRotator& Rotacion)
{
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("UGDElementFactory::CrearEnemigoBasico - World es NULL."));
		return nullptr;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.Name = NAME_None;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	AGDEnemyBasic* Enemigo = World->SpawnActor<AGDEnemyBasic>(
		AGDEnemyBasic::StaticClass(),
		Posicion,
		Rotacion,
		SpawnParams
	);

	if (Enemigo)
	{
		Enemigo->ConfigurarStats(100.0f, 250.0f, 10.0f, 50);
		UE_LOG(LogTemp, Warning, TEXT("Factory creó AGDEnemyBasic en: %s"), *Posicion.ToString());
	}

	return Enemigo;
}

AGDObstacleBase* UGDElementFactory::CrearMeteorito(UWorld* World, const FVector& Posicion, const FRotator& Rotacion)
{
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("UGDElementFactory::CrearMeteorito - World es NULL."));
		return nullptr;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.Name = NAME_None;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	AGDObstacleBase* Meteorito = nullptr;

	// ARREGLO 2: Usamos tu Blueprint (ClaseMeteoritoBP)
	if (ClaseMeteoritoBP)
	{
		Meteorito = World->SpawnActor<AGDObstacleBase>(ClaseMeteoritoBP, Posicion, Rotacion, SpawnParams);
		UE_LOG(LogTemp, Warning, TEXT("Factory creó el METEORITO 3D en: %s"), *Posicion.ToString());
	}
	else
	{
		// Si por alguna razón falla el BP, usa el código de respaldo
		Meteorito = World->SpawnActor<AGDMeteorite>(AGDMeteorite::StaticClass(), Posicion, Rotacion, SpawnParams);
		UE_LOG(LogTemp, Warning, TEXT("Factory creó el meteorito gris (fallback) en: %s"), *Posicion.ToString());
	}

	// Como el Blueprint devuelve un AGDObstacleBase, hacemos Cast para usar la función de Mari
	if (AGDMeteorite* MetCast = Cast<AGDMeteorite>(Meteorito))
	{
		MetCast->ConfigurarObstaculo(200.0f, 25.0f, 80.0f);
	}

	return Meteorito;
}

AGDPowerUpBase* UGDElementFactory::CrearPowerUpBase(UWorld* World, const FVector& Posicion, const FRotator& Rotacion)
{
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("UGDElementFactory::CrearPowerUpBase - World es NULL."));
		return nullptr;
	}

	FActorSpawnParameters SpawnParams;
	SpawnParams.Name = NAME_None;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	AGDPowerUpBase* PowerUp = World->SpawnActor<AGDPowerUpBase>(
		AGDPowerUpBase::StaticClass(),
		Posicion,
		Rotacion,
		SpawnParams
	);

	if (PowerUp)
	{
		PowerUp->ConfigurarPowerUp(TEXT("PowerUpBase"), 5.0f);
		UE_LOG(LogTemp, Warning, TEXT("Factory creó AGDPowerUpBase en: %s"), *Posicion.ToString());
	}

	return PowerUp;
}

AGDEnemyBase* UGDElementFactory::CrearEnemyFast(UWorld* Mundo, FVector Posicion)
{
	return Mundo->SpawnActor<AGDEnemyFast>(AGDEnemyFast::StaticClass(), Posicion, FRotator::ZeroRotator);
}

AGDEnemyBase* UGDElementFactory::CrearEnemyBasic(UWorld* Mundo, FVector Posicion)
{
	return Mundo->SpawnActor<AGDEnemyBasic>(AGDEnemyBasic::StaticClass(), Posicion, FRotator::ZeroRotator);
}

AGDEnemyBase* UGDElementFactory::CrearEnemyTank(UWorld* Mundo, FVector Posicion)
{
	return Mundo->SpawnActor<AGDEnemyTank>(AGDEnemyTank::StaticClass(), Posicion, FRotator::ZeroRotator);
}

AGDEnemyBase* UGDElementFactory::CrearEnemyShooter(UWorld* Mundo, FVector Posicion)
{
	return Mundo->SpawnActor<AGDEnemyShooter>(AGDEnemyShooter::StaticClass(), Posicion, FRotator::ZeroRotator);
}

AGDEnemyBase* UGDElementFactory::CrearEnemyBoss(UWorld* Mundo, FVector Posicion)
{
	return Mundo->SpawnActor<AGDEnemyBoss>(AGDEnemyBoss::StaticClass(), Posicion, FRotator::ZeroRotator);
}

// PowerUps
AGDPowerUpBase* UGDElementFactory::CrearPowerUpShield(UWorld* Mundo, FVector Posicion)
{
	return Mundo->SpawnActor<AGDPowerUpShield>(AGDPowerUpShield::StaticClass(), Posicion, FRotator::ZeroRotator);
}

AGDPowerUpBase* UGDElementFactory::CrearPowerUpDoubleShot(UWorld* Mundo, FVector Posicion)
{
	return Mundo->SpawnActor<AGDPowerUpDoubleShot>(AGDPowerUpDoubleShot::StaticClass(), Posicion, FRotator::ZeroRotator);
}
AGDPowerUpBase* UGDElementFactory::CrearPowerUpSpeed(UWorld* Mundo, FVector Posicion)
{
	return Mundo->SpawnActor<AGDPowerUpSpeed>(AGDPowerUpSpeed::StaticClass(), Posicion, FRotator::ZeroRotator);
}