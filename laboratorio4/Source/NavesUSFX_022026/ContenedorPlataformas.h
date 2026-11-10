// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ContenedorPlataformas.generated.h"

class APlataforma;
class USceneComponent;

/**
 * Contenedor de plataformas. Crea y guarda al menos 200 plataformas (12 tipos de movimiento
 * repartidos en cuadricula) y, pasado un tiempo inicial, hace desaparecer una al azar
 * cada IntervaloDesaparicion segundos (0.3 s) hasta que no quede ninguna.
 */
UCLASS()
class NAVESUSFX_022026_API AContenedorPlataformas : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AContenedorPlataformas();

	// Minimo de plataformas que debe almacenar el contenedor
	static const int32 CantidadMinima = 200;

	// Crea las plataformas, las guarda en el contenedor y arranca su desaparicion aleatoria
	void Iniciar(int32 Cantidad);

	// Cuantas plataformas quedan en el contenedor
	int32 Cantidad() const { return Plataformas.Num(); }

	const TArray<APlataforma*>& GetPlataformas() const { return Plataformas; }

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Plataformas")
	USceneComponent* Raiz;

	// Centro (X, Y) de la cuadricula donde aparecen las plataformas
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plataformas|Distribucion")
	FVector CentroZona;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plataformas|Distribucion")
	int32 Columnas;

	// Distancia entre plataformas contiguas (cm)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plataformas|Distribucion")
	float Separacion;

	// Cada plataforma recibe una altura al azar entre estos valores (cm)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plataformas|Distribucion")
	float AlturaMinima;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plataformas|Distribucion")
	float AlturaMaxima;

	// Rango de tamano del recorrido (cm) y de vueltas por segundo que recibe cada plataforma
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plataformas|Movimiento")
	float AmplitudMinima;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plataformas|Movimiento")
	float AmplitudMaxima;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plataformas|Movimiento")
	float FrecuenciaMinima;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plataformas|Movimiento")
	float FrecuenciaMaxima;

	// Cada cuantos segundos desaparece una plataforma al azar
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plataformas|Desaparicion")
	float IntervaloDesaparicion;

	// Segundos que pasan antes de que empiecen a desaparecer (coincide con la pausa inicial)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plataformas|Desaparicion")
	float RetrasoDesaparicion;

private:
	UPROPERTY()
	TArray<APlataforma*> Plataformas;

	FTimerHandle TimerDesaparicion;

	void CrearPlataformas(int32 Cantidad);
	void EliminarPlataformaAleatoria();
};
