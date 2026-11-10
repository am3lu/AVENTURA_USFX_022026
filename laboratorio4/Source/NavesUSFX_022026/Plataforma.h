// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Plataforma.generated.h"

class UStaticMeshComponent;

/**
 * Plataforma base. Cada plataforma lleva su propio ciclo, independiente de las demas:
 *   - nace quieta durante DuracionPausa (5 s),
 *   - luego se mueve durante DuracionMovimiento (10 s),
 *   - vuelve a quedarse quieta, y asi sucesivamente.
 * La forma de moverse la define cada subclase en CalcularDesplazamiento().
 */
UCLASS(Abstract)
class NAVESUSFX_022026_API APlataforma : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APlataforma();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Segundos que permanece quieta (al nacer y despues de cada movimiento)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plataforma|Ciclo")
	float DuracionPausa;

	// Segundos que se mueve en cada ciclo
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plataforma|Ciclo")
	float DuracionMovimiento;

	// Tamano del recorrido (cm)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plataforma|Movimiento")
	float Amplitud;

	// Vueltas completas del recorrido por segundo de movimiento
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Plataforma|Movimiento")
	float Frecuencia;

	void ConfigurarMovimiento(float NuevaAmplitud, float NuevaFrecuencia);

	bool EstaEnMovimiento() const { return bEnMovimiento; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Desplazamiento respecto a la posicion inicial despues de TiempoMov segundos de movimiento
	// ACUMULADOS (las pausas no cuentan, asi retoma el recorrido donde lo dejo).
	virtual FVector CalcularDesplazamiento(float TiempoMov) const
		PURE_VIRTUAL(APlataforma::CalcularDesplazamiento, return FVector::ZeroVector;);

	// Vueltas completas recorridas tras TiempoMov segundos (0, 0.5, 1, ...)
	float Fase(float TiempoMov) const;

	// Lo mismo en radianes
	float Angulo(float TiempoMov) const;

	// Onda triangular de periodo 1: empieza en 0, sube a 1, baja a -1 y vuelve a 0
	static float OndaTriangular(float FaseActual);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Plataforma")
	UStaticMeshComponent* MallaPlataforma;

	// Color de la plataforma (cada tipo de movimiento tiene el suyo)
	FLinearColor ColorPlataforma;

	// Desfase aleatorio propio de cada plataforma
	float FaseAleatoria;

private:
	FVector PosicionInicial;
	float TiempoEnFase;
	float TiempoMovimiento;
	bool bEnMovimiento;
};
