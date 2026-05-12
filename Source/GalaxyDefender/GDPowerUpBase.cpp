// Fill out your copyright notice in the Description page of Project Settings.


#include "GDPowerUpBase.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AGDPowerUpBase::AGDPowerUpBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PowerUpMesh"));
	RootComponent = MeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Sphere.Sphere"));

	if (MeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}

	NombrePowerUp = TEXT("PowerUpBase");
	Duracion = 5.0f;
	bConsumido = false;

	SetActorScale3D(FVector(0.5f, 0.5f, 0.5f));
}

// Called when the game starts or when spawned
void AGDPowerUpBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AGDPowerUpBase creado."));
}

// Called every frame
void AGDPowerUpBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator NuevaRotacion = GetActorRotation();
	NuevaRotacion.Yaw += 90.0f * DeltaTime;
	SetActorRotation(NuevaRotacion);
}
void AGDPowerUpBase::ConfigurarPowerUp(const FString& NuevoNombre, float NuevaDuracion)
{
	NombrePowerUp = NuevoNombre;
	Duracion = NuevaDuracion;
}

void AGDPowerUpBase::AplicarPowerUp(AActor* Objetivo)
{
	if (!Objetivo || bConsumido)
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("PowerUp aplicado: %s"), *NombrePowerUp);

	ConsumirPowerUp();
}

void AGDPowerUpBase::ConsumirPowerUp()
{
	if (bConsumido)
	{
		return;
	}

	bConsumido = true;
	Destroy();
}
FString AGDPowerUpBase::GetNombrePowerUp() const
{
	return NombrePowerUp;
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
