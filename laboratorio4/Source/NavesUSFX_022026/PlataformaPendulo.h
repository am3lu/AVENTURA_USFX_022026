// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaPendulo.generated.h"

/**
 * Se balancea de lado a lado como un pendulo.
 */
UCLASS()
class NAVESUSFX_022026_API APlataformaPendulo : public APlataforma
{
	GENERATED_BODY()

public:
	APlataformaPendulo();

protected:
	virtual FVector CalcularDesplazamiento(float TiempoMov) const override;
};
