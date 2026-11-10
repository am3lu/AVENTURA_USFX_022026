// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaCircular.generated.h"

/**
 * Da vueltas en un circulo horizontal.
 */
UCLASS()
class NAVESUSFX_022026_API APlataformaCircular : public APlataforma
{
	GENERATED_BODY()

public:
	APlataformaCircular();

protected:
	virtual FVector CalcularDesplazamiento(float TiempoMov) const override;
};
