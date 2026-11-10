// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstaculoMovil.h"
#include "ObstaculoGlobo.generated.h"

/**
 * Producto concreto: Globo (obstaculo Movil de la familia Aereo).
 */
UCLASS()
class AVENTURAUSFX022026L1_API AObstaculoGlobo : public AObstaculoMovil
{
	GENERATED_BODY()

public:
	AObstaculoGlobo();
};
