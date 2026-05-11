// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GDDecoradorNivel.generated.h"

/**
 * 
 */
UCLASS()
class GALAXYDEFENDER_API UGDDecoradorNivel : public UObject
{
	GENERATED_BODY()
public:
	// La función virtual que heredarán todos tus decoradores específicos
	virtual void ModificarActor(AActor* ActorAModificar);
};
