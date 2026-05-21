#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GDFachadaNivel.generated.h"

class UUGDRegistroNivel;
class UGDConstructorNivel;
class UGDDirectorNivel;

UCLASS()
class GALAXYDEFENDER_API AGDFachadaNivel : public AActor
{
	GENERATED_BODY()

public:
	AGDFachadaNivel();

protected:
	virtual void BeginPlay() override;

public:
	// NUEVO: Habilitamos el Tick para que la Fachada vigile la partida
	virtual void Tick(float DeltaTime) override;

	void IniciarNivel(int32 NumeroNivel);
	void LimpiarNivelActual();

private:
	UPROPERTY()
	UUGDRegistroNivel* Registro;

	UPROPERTY()
	UGDConstructorNivel* Constructor;

	UPROPERTY()
	UGDDirectorNivel* Director;

	// NUEVO: Variables de control de flujo
	int32 NivelActual;
	bool bNivelEnProgreso;
};