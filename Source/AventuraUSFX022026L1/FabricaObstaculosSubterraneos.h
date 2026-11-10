// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FabricaObstaculos.h"
#include "FabricaObstaculosSubterraneos.generated.h"

/**
 * Fabrica concreta: produce la familia Subterraneo (Estalactita, Vagoneta y Lava).
 */
UCLASS()
class AVENTURAUSFX022026L1_API AFabricaObstaculosSubterraneos : public AFabricaObstaculos
{
	GENERATED_BODY()

public:
	virtual AObstaculoFijo* CrearObstaculoFijo(const FVector& Posicion, const FRotator& Rotacion) override;
	virtual AObstaculoMovil* CrearObstaculoMovil(const FVector& Posicion, const FRotator& Rotacion) override;
	virtual AObstaculoPeligroso* CrearObstaculoPeligroso(const FVector& Posicion, const FRotator& Rotacion) override;

	virtual FString GetNombreFamilia() const override { return TEXT("Subterraneo"); }
};
