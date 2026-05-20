#include "GDEnemyFast.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

AGDEnemyFast::AGDEnemyFast()
{
    ConfigurarStats(80.f, 400.f, 15.f, 70);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
    if (MeshAsset.Succeeded() && MeshComponent)
        MeshComponent->SetStaticMesh(MeshAsset.Object);
    SetActorScale3D(FVector(0.7f));
}

void AGDEnemyFast::BeginPlay() { 
    Super::BeginPlay(); 
}
void AGDEnemyFast::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (!EstaMuerto())
    {
        FVector Pos = GetActorLocation();
        Pos.X -= Velocidad * DeltaTime;
        SetActorLocation(Pos);
    }
}