// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemigo.generated.h"

class USceneComponent;
class UStaticMeshComponent;

/**
 * Nave enemiga. Se desplaza por el escenario: elige un punto al azar dentro de una
 * zona (caja), vuela hacia el girando la nave, espera un momento al llegar y elige otro.
 */
UCLASS()
class AVENTURA_USFX_022026_API AEnemigo : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemigo();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Define la zona del escenario (centro y mitad del tamano en cada eje) por donde se mueve
	void DefinirZonaMovimiento(const FVector& NuevoCentro, const FVector& NuevaExtension);

	void SetVelocidad(float NuevaVelocidad);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemigo")
		USceneComponent* Raiz;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemigo")
		UStaticMeshComponent* MallaEnemigo;

	// Velocidad de desplazamiento (cm/s)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemigo|Movimiento")
		float Velocidad;

	// Velocidad de giro hacia el destino (grados/s)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemigo|Movimiento")
		float VelocidadGiro;

	// A que distancia del destino (cm) se considera que ya llego
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemigo|Movimiento")
		float DistanciaLlegada;

	// Segundos que espera al llegar a un destino antes de ir al siguiente
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemigo|Movimiento")
		float TiempoEspera;

private:
	FVector CentroZona;
	FVector ExtensionZona;
	FVector Destino;
	float TiempoEsperaRestante;
	bool bZonaDefinida;

	void ElegirNuevoDestino();
};

