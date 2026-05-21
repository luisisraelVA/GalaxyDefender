#include "GDBossSectorFactory.h"

AGDEnemyBase* UGDBossSectorFactory::CrearEnemigoPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion)
{
	InicializarFactory();
	if (!ElementFactory) return nullptr;

	UE_LOG(LogTemp, Warning, TEXT("Fabrica Boss: Desplegando al JEFE FINAL del nivel 3."));

	// ¡USAMOS EL NOMBRE EXACTO DE MARI Y SOLO 2 PARAMETROS!
	return ElementFactory->CrearEnemyBoss(World, Posicion);
}

AGDObstacleBase* UGDBossSectorFactory::CrearObstaculoPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion)
{
	InicializarFactory();

	// El sector del Jefe Final no tiene meteoritos, la arena está limpia para el combate
	return nullptr;
}

AGDPowerUpBase* UGDBossSectorFactory::CrearPowerUpPrincipal(UWorld* World, const FVector& Posicion, const FRotator& Rotacion)
{
	InicializarFactory();
	if (!ElementFactory) return nullptr;

	UE_LOG(LogTemp, Warning, TEXT("Fabrica Boss: Desplegando Power-Up de Velocidad extrema."));

	// ¡USAMOS EL NOMBRE EXACTO DE MARI Y SOLO 2 PARAMETROS!
	return ElementFactory->CrearPowerUpSpeed(World, Posicion);
}