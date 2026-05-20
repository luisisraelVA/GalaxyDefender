// Fill out your copyright notice in the Description page of Project Settings.


#include "GDPowerUpSpeed.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AGDPowerUpSpeed::AGDPowerUpSpeed()
{
    TipoPowerUp = "Speed";

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cone.Cone"));
    if (MeshAsset.Succeeded() && MeshComponent)
        MeshComponent->SetStaticMesh(MeshAsset.Object);

    SetActorScale3D(FVector(0.5f));
}

