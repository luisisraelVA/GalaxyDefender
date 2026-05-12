// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GDPowerUpBase.generated.h"

UCLASS()
class GALAXYDEFENDER_API AGDPowerUpBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGDPowerUpBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Category = "GD PowerUp")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "GD PowerUp")
	FString NombrePowerUp;

	UPROPERTY(VisibleAnywhere, Category = "GD PowerUp")
	float Duracion;

	UPROPERTY(VisibleAnywhere, Category = "GD PowerUp")
	bool bConsumido;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void ConfigurarPowerUp(const FString& NuevoNombre, float NuevaDuracion);

	virtual void AplicarPowerUp(AActor* Objetivo);

	virtual void ConsumirPowerUp();

	FString GetNombrePowerUp() const;
	float GetDuracion() const;
	bool EstaConsumido() const;
	UStaticMeshComponent* GetMeshComponent() const;
};
