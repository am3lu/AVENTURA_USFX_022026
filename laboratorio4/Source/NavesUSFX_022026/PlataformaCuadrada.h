// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaCuadrada.generated.h"

/**
 * Recorre el contorno de un cuadrado.
 */
UCLASS()
class NAVESUSFX_022026_API APlataformaCuadrada : public APlataforma
{
	GENERATED_BODY()

public:
	APlataformaCuadrada();

protected:
	virtual FVector CalcularDesplazamiento(float TiempoMov) const override;
};
