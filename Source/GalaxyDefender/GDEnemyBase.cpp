#include "GDEnemyBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

AGDEnemyBase::AGDEnemyBase()
{
    PrimaryActorTick.bCanEverTick = true;

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyMesh"));
    RootComponent = MeshComponent;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (MeshAsset.Succeeded())
        MeshComponent->SetStaticMesh(MeshAsset.Object);

    Vida = 100.f;
    Velocidad = 200.f;
    Dano = 10.f;
    Puntos = 50;
    bEstaMuerto = false;

    SetActorScale3D(FVector(1.f));
}

void AGDEnemyBase::BeginPlay() { 
    Super::BeginPlay(); 
}

void AGDEnemyBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (!bEstaMuerto)
    {
        FVector Pos = GetActorLocation();
        Pos.X -= Velocidad * DeltaTime;
        SetActorLocation(Pos);
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
    if (bEstaMuerto) return;
    Vida -= CantidadDano;
    if (Vida <= 0.f) Morir();
}

void AGDEnemyBase::Morir() { if (bEstaMuerto) return; bEstaMuerto = true; Destroy(); }

void AGDEnemyBase::SetVida(float NuevaVida) { Vida = NuevaVida; }
void AGDEnemyBase::SetVelocidad(float NuevaVelocidad) { Velocidad = NuevaVelocidad; }
void AGDEnemyBase::SetDano(float NuevoDano) { Dano = NuevoDano; }
void AGDEnemyBase::SetPuntos(int32 NuevosPuntos) { Puntos = NuevosPuntos; }

float AGDEnemyBase::GetVida() const { return Vida; }
float AGDEnemyBase::GetVelocidad() const { return Velocidad; }
float AGDEnemyBase::GetDano() const { return Dano; }
int32 AGDEnemyBase::GetPuntos() const { return Puntos; }
bool AGDEnemyBase::EstaMuerto() const { return bEstaMuerto; }
UStaticMeshComponent* AGDEnemyBase::GetMeshComponent() const { return MeshComponent; }