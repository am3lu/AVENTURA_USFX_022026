// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaRebote.generated.h"

/**
 * Rebota dentro de una caja, con una velocidad distinta en cada eje.
 */
UCLASS()
class NAVESUSFX_022026_API APlataformaRebote : public APlataforma
{
	GENERATED_BODY()

public:
	APlataformaRebote();

protected:
	virtual FVector CalcularDesplazamiento(float TiempoMov) const override;
};
