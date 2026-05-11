#include "GDEnemyBase.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/Engine.h"

AGDEnemyBase::AGDEnemyBase()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyMesh"));
	RootComponent = MeshComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));

	if (MeshAsset.Succeeded())
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}

	Vida = 100.0f;
	Velocidad = 200.0f;
	Dano = 10.0f;
	Puntos = 50;
	bEstaMuerto = false;

	SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));
}

void AGDEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("AGDEnemyBase creado en el mundo."));
}

void AGDEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bEstaMuerto)
	{
		FVector NuevaUbicacion = GetActorLocation();
		NuevaUbicacion.X -= Velocidad * DeltaTime;
		SetActorLocation(NuevaUbicacion);
	}
}

void AGDEnemyBase::ConfigurarStats(float NuevaVida, float NuevaVelocidad, float NuevoDano, int32 NuevosPuntos)
{
	Vida = NuevaVida;
	Velocidad = NuevaVelocidad;
	Dano = NuevoDano;
	Puntos = NuevosPuntos;
}

void AGDEnemyBase::RecibirDano(float CantidadDano)
{
	if (bEstaMuerto)
	{
		return;
	}

	Vida -= CantidadDano;

	UE_LOG(LogTemp, Warning, TEXT("Enemigo recibió daño. Vida actual: %f"), Vida);

	if (Vida <= 0.0f)
	{
		Morir();
	}
}

void AGDEnemyBase::Morir()
{
	if (bEstaMuerto)
	{
		return;
	}

	bEstaMuerto = true;

	UE_LOG(LogTemp, Warning, TEXT("Enemigo destruido. Puntos otorgados: %d"), Puntos);

	Destroy();
}

void AGDEnemyBase::SetVida(float NuevaVida)
{
	Vida = NuevaVida;
}

void AGDEnemyBase::SetVelocidad(float NuevaVelocidad)
{
	Velocidad = NuevaVelocidad;
}

void AGDEnemyBase::SetDano(float NuevoDano)
{
	Dano = NuevoDano;
}

void AGDEnemyBase::SetPuntos(int32 NuevosPuntos)
{
	Puntos = NuevosPuntos;
}

float AGDEnemyBase::GetVida() const
{
	return Vida;
}

float AGDEnemyBase::GetVelocidad() const
{
	return Velocidad;
}

float AGDEnemyBase::GetDano() const
{
	return Dano;
}

int32 AGDEnemyBase::GetPuntos() const
{
	return Puntos;
}

bool AGDEnemyBase::EstaMuerto() const
{
	return bEstaMuerto;
}

UStaticMeshComponent* AGDEnemyBase::GetMeshComponent() const
{
	return MeshComponent;
}