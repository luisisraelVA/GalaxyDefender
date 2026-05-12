// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GDObstacleBase.h"
#include "GDMeteorite.generated.h"

/**
 * 
 */
UCLASS()
class GALAXYDEFENDER_API AGDMeteorite : public AGDObstacleBase
{
	GENERATED_BODY()
public:
	AGDMeteorite();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
