// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GDEnemyBase.h"
#include "GDEnemyBoss.generated.h"

/**
 * 
 */
UCLASS()
class GALAXYDEFENDER_API AGDEnemyBoss : public AGDEnemyBase
{
	GENERATED_BODY()
	
public:
	AGDEnemyBoss();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
