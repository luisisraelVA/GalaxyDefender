// Fill out your copyright notice in the Description page of Project Settings.


#include "GDObstacleBase.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AGDObstacleBase::AGDObstacleBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObstacleMesh"));
	RootComponent = MeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Sphere.Sphere"));

	if (MeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}
	Vida = 150.0f;
	DanoPorChoque = 20.0f;
	VelocidadRotacion = 40.0f;
}

// Called when the game starts or when spawned
void AGDObstacleBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AGDObstacleBase creado."));
	
}

// Called every frame
void AGDObstacleBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator NuevaRotacion = GetActorRotation();
	NuevaRotacion.Yaw += VelocidadRotacion * DeltaTime;
	NuevaRotacion.Pitch += VelocidadRotacion * 0.5f * DeltaTime;
	SetActorRotation(NuevaRotacion);
}
void AGDObstacleBase::ConfigurarObstaculo(float NuevaVida, float NuevoDanoPorChoque, float NuevaVelocidadRotacion)
{
	Vida = NuevaVida;
	DanoPorChoque = NuevoDanoPorChoque;
	VelocidadRotacion = NuevaVelocidadRotacion;
}

void AGDObstacleBase::RecibirDano(float CantidadDano)
{
	Vida -= CantidadDano;

	if (Vida <= 0.0f)
	{
		DestruirObstaculo();
	}
}

void AGDObstacleBase::DestruirObstaculo()
{
	UE_LOG(LogTemp, Warning, TEXT("Obstáculo destruido."));
	Destroy();
}

float AGDObstacleBase::GetVida() const
{
	return Vida;
}

float AGDObstacleBase::GetDanoPorChoque() const
{
	return DanoPorChoque;
}

UStaticMeshComponent* AGDObstacleBase::GetMeshComponent() const
{
	return MeshComponent;
}
