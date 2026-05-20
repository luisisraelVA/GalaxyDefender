// Fill out your copyright notice in the Description page of Project Settings.


#include "GDPowerUpBase.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AGDPowerUpBase::AGDPowerUpBase()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;

	TipoPowerUp = "Base";
	Duracion = 5.f;
	bConsumido = false;
}

void AGDPowerUpBase::BeginPlay()
{
	Super::BeginPlay();
}

void AGDPowerUpBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Rotación simple para visualizar
	if (MeshComponent)
	{
		FRotator Rot = MeshComponent->GetComponentRotation();
		Rot.Yaw += 60.f * DeltaTime;
		MeshComponent->SetWorldRotation(Rot);
	}
}

void AGDPowerUpBase::ConfigurarPowerUp(const FString& NuevoNombre, float NuevaDuracion)
{
	TipoPowerUp = NuevoNombre;
	Duracion = NuevaDuracion;
}

void AGDPowerUpBase::AplicarPowerUp(AActor* Objetivo)
{
	// Funcionalidad base, puede sobrescribirse en hijos
}

void AGDPowerUpBase::ConsumirPowerUp()
{
	bConsumido = true;
	Destroy();
}

FString AGDPowerUpBase::GetTipoPowerUp() const
{
	return TipoPowerUp;
}

float AGDPowerUpBase::GetDuracion() const
{
	return Duracion;
}

bool AGDPowerUpBase::EstaConsumido() const
{
	return bConsumido;
}

UStaticMeshComponent* AGDPowerUpBase::GetMeshComponent() const
{
	return MeshComponent;
}
