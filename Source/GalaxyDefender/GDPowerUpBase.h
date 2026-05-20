#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "GDPowerUpBase.generated.h"

UCLASS()
class GALAXYDEFENDER_API AGDPowerUpBase : public AActor
{
    GENERATED_BODY()

public:
    AGDPowerUpBase();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // Mesh del PowerUp
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* MeshComponent;

    // Tipo de PowerUp (Shield, DoubleShot, Speed)
    UPROPERTY(VisibleAnywhere)
    FString TipoPowerUp;

    // Duración del efecto
    UPROPERTY(VisibleAnywhere)
    float Duracion;

    // Si ya fue consumido
    UPROPERTY(VisibleAnywhere)
    bool bConsumido;

    // Configura el PowerUp
    virtual void ConfigurarPowerUp(const FString& NuevoNombre, float NuevaDuracion);

    // Aplica el PowerUp a un actor
    virtual void AplicarPowerUp(AActor* Objetivo);

    // Marca como consumido
    virtual void ConsumirPowerUp();

    // Getters
    FString GetTipoPowerUp() const;
    float GetDuracion() const;
    bool EstaConsumido() const;
    UStaticMeshComponent* GetMeshComponent() const;
};