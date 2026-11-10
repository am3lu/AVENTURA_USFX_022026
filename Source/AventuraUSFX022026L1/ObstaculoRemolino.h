// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstaculoPeligroso.h"
#include "ObstaculoRemolino.generated.h"

/**
 * Producto concreto: Remolino (obstaculo Peligroso de la familia Acuatico).
 */
UCLASS()
class AVENTURAUSFX022026L1_API AObstaculoRemolino : public AObstaculoPeligroso
{
	GENERATED_BODY()

public:
	AObstaculoRemolino();
};
