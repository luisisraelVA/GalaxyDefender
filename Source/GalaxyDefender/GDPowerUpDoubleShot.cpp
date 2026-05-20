// Fill out your copyright notice in the Description page of Project Settings.


#include "GDPowerUpDoubleShot.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AGDPowerUpDoubleShot::AGDPowerUpDoubleShot()
{
    TipoPowerUp = "DoubleShot";

    // Mesh temporal
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
    if (MeshAsset.Succeeded() && MeshComponent)
        MeshComponent->SetStaticMesh(MeshAsset.Object);

    SetActorScale3D(FVector(0.5f));
}