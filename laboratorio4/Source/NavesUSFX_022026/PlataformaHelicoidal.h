// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaHelicoidal.generated.h"

/**
 * Sube dando vueltas, como una helice.
 */
UCLASS()
class NAVESUSFX_022026_API APlataformaHelicoidal : public APlataforma
{
	GENERATED_BODY()

public:
	APlataformaHelicoidal();

protected:
	virtual FVector CalcularDesplazamiento(float TiempoMov) const override;
};
