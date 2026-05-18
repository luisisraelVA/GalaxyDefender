// Fill out your copyright notice in the Description page of Project Settings.


#include "GDMeteorite.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"

AGDMeteorite::AGDMeteorite()
{
	ConfigurarObstaculo(200.0f, 25.0f, 80.0f);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Sphere.Sphere"));

	if (MeshAsset.Succeeded() && MeshComponent)
	{
		MeshComponent->SetStaticMesh(MeshAsset.Object);
	}

	SetActorScale3D(FVector(1.5f, 1.5f, 1.5f));
}

void AGDMeteorite::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("AGDMeteorite creado: meteorito del Nivel 2."));
}

void AGDMeteorite::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator Rot = GetActorRotation();
	Rot.Yaw += VelocidadRotacion * DeltaTime;
	Rot.Pitch += VelocidadRotacion * 0.5f * DeltaTime;
	SetActorRotation(Rot);
}

