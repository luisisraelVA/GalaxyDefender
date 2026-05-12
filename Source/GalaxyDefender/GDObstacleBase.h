// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GDObstacleBase.generated.h"

UCLASS()
class GALAXYDEFENDER_API AGDObstacleBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGDObstacleBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Category = "GD Obstacle")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "GD Obstacle")
	float Vida;

	UPROPERTY(VisibleAnywhere, Category = "GD Obstacle")
	float DanoPorChoque;

	UPROPERTY(VisibleAnywhere, Category = "GD Obstacle")
	float VelocidadRotacion;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void ConfigurarObstaculo(float NuevaVida, float NuevoDanoPorChoque, float NuevaVelocidadRotacion);

	virtual void RecibirDano(float CantidadDano);

	virtual void DestruirObstaculo();

	float GetVida() const;
	float GetDanoPorChoque() const;
	UStaticMeshComponent* GetMeshComponent() const;
};
