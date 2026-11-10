// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstaculoFijo.h"
#include "ObstaculoNube.generated.h"

/**
 * Producto concreto: Nube (obstaculo Fijo de la familia Aereo).
 */
UCLASS()
class AVENTURAUSFX022026L1_API AObstaculoNube : public AObstaculoFijo
{
	GENERATED_BODY()

public:
	AObstaculoNube();
};
