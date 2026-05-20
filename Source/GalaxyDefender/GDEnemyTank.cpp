#include "GDEnemyTank.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

AGDEnemyTank::AGDEnemyTank()
{
	ConfigurarStats(300.f, 150.f, 25.f, 150);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (MeshAsset.Succeeded() && MeshComponent)
		MeshComponent->SetStaticMesh(MeshAsset.Object);

	SetActorScale3D(FVector(1.2f));
}

void AGDEnemyTank::BeginPlay()
{
	Super::BeginPlay();
}

void AGDEnemyTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!EstaMuerto())
	{
		FVector Pos = GetActorLocation();
		Pos.X -= Velocidad * DeltaTime;
		SetActorLocation(Pos);
	}
}