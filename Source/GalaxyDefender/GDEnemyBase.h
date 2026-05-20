// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "GDEnemyBase.generated.h"

UCLASS()
class GALAXYDEFENDER_API AGDEnemyBase : public AActor
{
    GENERATED_BODY()

public:
    AGDEnemyBase();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComponent;

    UPROPERTY(EditAnywhere)
    float Vida;

    UPROPERTY(EditAnywhere)
    float Velocidad;

    UPROPERTY(EditAnywhere)
    float Dano;

    UPROPERTY(EditAnywhere)
    int32 Puntos;

    UPROPERTY(VisibleAnywhere)
    bool bEstaMuerto;

    void ConfigurarStats(float NuevaVida, float NuevaVelocidad, float NuevoDano, int32 NuevosPuntos);
    void RecibirDano(float CantidadDano);
    void Morir();

    void SetVida(float NuevaVida);
    void SetVelocidad(float NuevaVelocidad);
    void SetDano(float NuevoDano);
    void SetPuntos(int32 NuevosPuntos);

    float GetVida() const;
    float GetVelocidad() const;
    float GetDano() const;
    int32 GetPuntos() const;
    bool EstaMuerto() const;

    UStaticMeshComponent* GetMeshComponent() const;
};