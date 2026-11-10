// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaZigzag.generated.h"

/**
 * Avanza en X mientras zigzaguea rapido en Y.
 */
UCLASS()
class NAVESUSFX_022026_API APlataformaZigzag : public APlataforma
{
	GENERATED_BODY()

public:
	APlataformaZigzag();

protected:
	virtual FVector CalcularDesplazamiento(float TiempoMov) const override;
};
