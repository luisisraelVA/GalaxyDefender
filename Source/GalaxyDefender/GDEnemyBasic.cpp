#include "GDEnemyBasic.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

AGDEnemyBasic::AGDEnemyBasic()
{
	ConfigurarStats(100.f, 200.f, 10.f, 50);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (MeshAsset.Succeeded() && MeshComponent)
		MeshComponent->SetStaticMesh(MeshAsset.Object);

	SetActorScale3D(FVector(1.f));
}

void AGDEnemyBasic::BeginPlay()
{
	Super::BeginPlay();
}

void AGDEnemyBasic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!EstaMuerto())
	{
		FVector Pos = GetActorLocation();
		Pos.X -= Velocidad * DeltaTime;
		SetActorLocation(Pos);
	}
}