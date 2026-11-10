// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaOnda.generated.h"

/**
 * Avanza en Y ondulando arriba y abajo, como una ola.
 */
UCLASS()
class NAVESUSFX_022026_API APlataformaOnda : public APlataforma
{
	GENERATED_BODY()

public:
	APlataformaOnda();

protected:
	virtual FVector CalcularDesplazamiento(float TiempoMov) const override;
};
