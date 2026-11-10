// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstaculoFijo.h"
#include "ObstaculoIceberg.generated.h"

/**
 * Producto concreto: Iceberg (obstaculo Fijo de la familia Acuatico).
 */
UCLASS()
class AVENTURAUSFX022026L1_API AObstaculoIceberg : public AObstaculoFijo
{
	GENERATED_BODY()

public:
	AObstaculoIceberg();
};
