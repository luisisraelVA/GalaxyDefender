#include "GDEnemyBoss.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

AGDEnemyBoss::AGDEnemyBoss()
{
	ConfigurarStats(500.f, 100.f, 50.f, 500);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (MeshAsset.Succeeded() && MeshComponent)
		MeshComponent->SetStaticMesh(MeshAsset.Object);

	SetActorScale3D(FVector(2.f));
}

void AGDEnemyBoss::BeginPlay()
{
	Super::BeginPlay();
}

void AGDEnemyBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Boss puede quedar estático o moverse como quieras luego
}