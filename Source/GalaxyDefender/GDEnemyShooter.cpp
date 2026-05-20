#include "GDEnemyShooter.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

AGDEnemyShooter::AGDEnemyShooter()
{
	ConfigurarStats(150.f, 200.f, 15.f, 100);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	if (MeshAsset.Succeeded() && MeshComponent)
		MeshComponent->SetStaticMesh(MeshAsset.Object);

	SetActorScale3D(FVector(1.f));
}

void AGDEnemyShooter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("GDEnemyShooter listo"));
}

void AGDEnemyShooter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!EstaMuerto())
	{
		FVector Pos = GetActorLocation();
		Pos.X -= Velocidad * DeltaTime;
		SetActorLocation(Pos);
	}
}