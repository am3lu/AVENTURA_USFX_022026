// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaOcho.generated.h"

/**
 * Dibuja un ocho (infinito) en el plano horizontal.
 */
UCLASS()
class NAVESUSFX_022026_API APlataformaOcho : public APlataforma
{
	GENERATED_BODY()

public:
	APlataformaOcho();

protected:
	virtual FVector CalcularDesplazamiento(float TiempoMov) const override;
};
