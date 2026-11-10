// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstaculoMovil.h"
#include "ObstaculoVagoneta.generated.h"

/**
 * Producto concreto: Vagoneta (obstaculo Movil de la familia Subterraneo).
 */
UCLASS()
class AVENTURAUSFX022026L1_API AObstaculoVagoneta : public AObstaculoMovil
{
	GENERATED_BODY()

public:
	AObstaculoVagoneta();
};
