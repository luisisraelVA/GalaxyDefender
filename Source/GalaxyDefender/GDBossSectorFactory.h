#pragma once

#include "CoreMinimal.h"
#include "GDSectorAbstractFactory.h"
#include "GDBossSectorFactory.generated.h"

UCLASS()
class GALAXYDEFENDER_API UGDBossSectorFactory : public UGDSectorAbstractFactory
{
	GENERATED_BODY()
public:
	virtual AGDEnemyBase* CrearEnemigoPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion) override;
	virtual AGDObstacleBase* CrearObstaculoPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion) override;
	virtual AGDPowerUpBase* CrearPowerUpPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion) override;
};