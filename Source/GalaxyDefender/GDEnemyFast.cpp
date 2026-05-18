// Fill out your copyright notice in the Description page of Project Settings.

#include "GDEnemyFast.h"
#include "UObject/ConstructorHelpers.h"

AGDEnemyFast::AGDEnemyFast()
{
	ConfigurarStats(80.f, 400.f, 15.f, 70);

	// Mesh temporal
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	if (MeshAsset.Succeeded() && MeshComponent)
		MeshComponent->SetStaticMesh(MeshAsset.Object);

	SetActorScale3D(FVector(0.7f));
}

void AGDEnemyFast::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AGDEnemyFast listo"));
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