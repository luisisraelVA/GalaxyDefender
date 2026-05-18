// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GDEnemyBase.h"
#include "GDEnemyShooter.generated.h"

/**
 * 
 */
UCLASS()
class GALAXYDEFENDER_API AGDEnemyShooter : public AGDEnemyBase
{
	GENERATED_BODY()
public:
	AGDEnemyShooter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
