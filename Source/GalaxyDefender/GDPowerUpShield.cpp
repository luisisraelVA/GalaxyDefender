// Fill out your copyright notice in the Description page of Project Settings.


#include "GDPowerUpShield.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AGDPowerUpShield::AGDPowerUpShield()
{
    TipoPowerUp = "Shield";

    // Mesh temporal
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
    if (MeshAsset.Succeeded() && MeshComponent)
        MeshComponent->SetStaticMesh(MeshAsset.Object);

    SetActorScale3D(FVector(0.5f));
}

