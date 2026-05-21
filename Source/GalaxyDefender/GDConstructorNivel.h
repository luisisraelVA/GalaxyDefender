#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GDConstructorNivel.generated.h"

class UUGDRegistroNivel;
class UGDSectorAbstractFactory; // Apuntamos a la clase base abstracta

UCLASS()
class GALAXYDEFENDER_API UGDConstructorNivel : public UObject
{
	GENERATED_BODY()
public:

	void ConstruirFondoEspacial();
	void ConstruirMeteoritos();
	void ConstruirEnemigosBasicos();
	void ConstruirPowerUps();

	// ¡Devolvemos la función del Registro que nos faltaba!
	void SetRegistro(UUGDRegistroNivel* EnRegistro);

	// Función para la fábrica polimórfica
	void SetFabricaActual(UGDSectorAbstractFactory* NuevaFabrica);

private:
	UPROPERTY()
	UUGDRegistroNivel* RegistroActual;

	UPROPERTY()
	UGDSectorAbstractFactory* FabricaActual;
};