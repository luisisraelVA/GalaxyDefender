// Fill out your copyright notice in the Description page of Project Settings.


#include "GDEnemyBoss.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

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
	UE_LOG(LogTemp, Warning, TEXT("GDEnemyBoss listo"));
}

void AGDEnemyBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Boss por ahora estático
}