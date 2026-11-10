// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstaculoPeligroso.h"
#include "ObstaculoTormenta.generated.h"

/**
 * Producto concreto: Tormenta (obstaculo Peligroso de la familia Aereo).
 */
UCLASS()
class AVENTURAUSFX022026L1_API AObstaculoTormenta : public AObstaculoPeligroso
{
	GENERATED_BODY()

public:
	AObstaculoTormenta();
};
