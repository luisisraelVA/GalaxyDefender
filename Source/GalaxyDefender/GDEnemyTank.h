// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GDEnemyBase.h"
#include "GDEnemyTank.generated.h"

/**
 * 
 */
UCLASS()
class GALAXYDEFENDER_API AGDEnemyTank : public AGDEnemyBase
{
	GENERATED_BODY()
public:
	AGDEnemyTank();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
