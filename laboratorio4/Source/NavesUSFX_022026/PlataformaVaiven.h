// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaVaiven.generated.h"

/**
 * Va y viene en linea recta (eje X) a velocidad constante.
 */
UCLASS()
class NAVESUSFX_022026_API APlataformaVaiven : public APlataforma
{
	GENERATED_BODY()

public:
	APlataformaVaiven();

protected:
	virtual FVector CalcularDesplazamiento(float TiempoMov) const override;
};
