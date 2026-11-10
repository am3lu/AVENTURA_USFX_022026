// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "ObstaculoMovil.generated.h"

/**
 * Producto abstracto B: obstaculo que va y viene a lo largo de un eje, centrado en
 * el punto donde aparecio. Las clases concretas solo definen el eje, el recorrido y la velocidad.
 */
UCLASS(Abstract)
class AVENTURAUSFX022026L1_API AObstaculoMovil : public AObstaculo
{
	GENERATED_BODY()

public:
	AObstaculoMovil();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual FString GetTipo() const override { return TEXT("Movil"); }

protected:
	virtual void BeginPlay() override;

	// Direccion del vaiven (se normaliza)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstaculo|Movimiento")
	FVector EjeMovimiento;

	// Distancia (cm) que se aleja del punto inicial hacia cada lado
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstaculo|Movimiento")
	float Recorrido;

	// Velocidad (cm/s)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstaculo|Movimiento")
	float Velocidad;

private:
	FVector PosicionInicial;
	float Distancia;
	float Sentido;
};
