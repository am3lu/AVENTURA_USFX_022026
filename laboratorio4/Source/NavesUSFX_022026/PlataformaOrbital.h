// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaOrbital.generated.h"

/**
 * Da vueltas en un circulo vertical, como una noria.
 */
UCLASS()
class NAVESUSFX_022026_API APlataformaOrbital : public APlataforma
{
	GENERATED_BODY()

public:
	APlataformaOrbital();

protected:
	virtual FVector CalcularDesplazamiento(float TiempoMov) const override;
};
