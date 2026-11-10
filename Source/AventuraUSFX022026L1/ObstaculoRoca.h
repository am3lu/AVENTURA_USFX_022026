// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstaculoFijo.h"
#include "ObstaculoRoca.generated.h"

/**
 * Producto concreto: Roca (obstaculo Fijo de la familia Terrestre).
 */
UCLASS()
class AVENTURAUSFX022026L1_API AObstaculoRoca : public AObstaculoFijo
{
	GENERATED_BODY()

public:
	AObstaculoRoca();
};
