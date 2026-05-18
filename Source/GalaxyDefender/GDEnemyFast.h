// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GDEnemyBase.h"
#include "GDEnemyFast.generated.h"

/**
 * 
 */
UCLASS()
class GALAXYDEFENDER_API AGDEnemyFast : public AGDEnemyBase
{
	GENERATED_BODY()
public:
	AGDEnemyFast();  // Constructor correcto

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
