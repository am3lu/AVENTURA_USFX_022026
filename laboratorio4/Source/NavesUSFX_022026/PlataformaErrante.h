// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaErrante.generated.h"

/**
 * Vaga sin patron aparente (suma de ondas con desfase aleatorio).
 */
UCLASS()
class NAVESUSFX_022026_API APlataformaErrante : public APlataforma
{
	GENERATED_BODY()

public:
	APlataformaErrante();

protected:
	virtual FVector CalcularDesplazamiento(float TiempoMov) const override;
};
