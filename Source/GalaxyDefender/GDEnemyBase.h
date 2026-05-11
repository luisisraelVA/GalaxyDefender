// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GDEnemyBase.generated.h"

UCLASS()
class GALAXYDEFENDER_API AGDEnemyBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGDEnemyBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "GD Enemy")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "GD Enemy")
	float Vida;

	UPROPERTY(VisibleAnywhere, Category = "GD Enemy")
	float Velocidad;

	UPROPERTY(VisibleAnywhere, Category = "GD Enemy")
	float Dano;

	UPROPERTY(VisibleAnywhere, Category = "GD Enemy")
	int32 Puntos;

	UPROPERTY(VisibleAnywhere, Category = "GD Enemy")
	bool bEstaMuerto;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void ConfigurarStats(float NuevaVida, float NuevaVelocidad, float NuevoDano, int32 NuevosPuntos);

	virtual void RecibirDano(float CantidadDano);

	virtual void Morir();

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