// Fill out your copyright notice in the Description page of Project Settings.


#include "GDEnemyBasic.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

AGDEnemyBasic::AGDEnemyBasic()
{
	ConfigurarStats(100.0f, 250.0f, 10.0f, 50);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));

	if (MeshAsset.Succeeded() && MeshComponent)
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}

	SetActorScale3D(FVector(0.8f, 0.8f, 0.8f));
}

void AGDEnemyBasic::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("AGDEnemyBasic listo: enemigo básico del Nivel 1."));
}

void AGDEnemyBasic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
