// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "ObstaculoFijo.generated.h"

/**
 * Producto abstracto A: obstaculo que no se mueve y bloquea el paso.
 */
UCLASS(Abstract)
class AVENTURAUSFX022026L1_API AObstaculoFijo : public AObstaculo
{
	GENERATED_BODY()

public:
	virtual FString GetTipo() const override { return TEXT("Fijo"); }
};
