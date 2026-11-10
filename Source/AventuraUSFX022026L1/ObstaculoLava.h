// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObstaculoPeligroso.h"
#include "ObstaculoLava.generated.h"

/**
 * Producto concreto: Lava (obstaculo Peligroso de la familia Subterraneo).
 */
UCLASS()
class AVENTURAUSFX022026L1_API AObstaculoLava : public AObstaculoPeligroso
{
	GENERATED_BODY()

public:
	AObstaculoLava();
};
