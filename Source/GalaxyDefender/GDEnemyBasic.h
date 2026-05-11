// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GDEnemyBase.h"
#include "GDEnemyBasic.generated.h"

/**
 * 
 */
UCLASS()
class GALAXYDEFENDER_API AGDEnemyBasic : public AGDEnemyBase
{
	GENERATED_BODY()
public:
	AGDEnemyBasic();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
};
