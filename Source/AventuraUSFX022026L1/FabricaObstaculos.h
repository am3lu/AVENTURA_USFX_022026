// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "ObstaculoFijo.h"
#include "ObstaculoMovil.h"
#include "ObstaculoPeligroso.h"
#include "FabricaObstaculos.generated.h"

/**
 * Fabrica abstracta del patron ABSTRACT FACTORY. Declara como crear una FAMILIA completa de
 * obstaculos relacionados (uno fijo, uno movil y uno peligroso). Cada fabrica concreta produce
 * los tres productos de UNA misma familia, asi que el codigo cliente nunca mezcla familias y
 * tampoco conoce las clases concretas: solo usa esta interfaz y los productos abstractos.
 *
 * (A diferencia del Factory Method de AFabricaEnemigos, que crea un solo tipo de producto
 * con un unico metodo, aqui una fabrica ofrece varios metodos de creacion que forman una familia.)
 */
UCLASS(Abstract)
class AVENTURAUSFX022026L1_API AFabricaObstaculos : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFabricaObstaculos();

	virtual AObstaculoFijo* CrearObstaculoFijo(const FVector& Posicion, const FRotator& Rotacion)
		PURE_VIRTUAL(AFabricaObstaculos::CrearObstaculoFijo, return nullptr;);

	virtual AObstaculoMovil* CrearObstaculoMovil(const FVector& Posicion, const FRotator& Rotacion)
		PURE_VIRTUAL(AFabricaObstaculos::CrearObstaculoMovil, return nullptr;);

	virtual AObstaculoPeligroso* CrearObstaculoPeligroso(const FVector& Posicion, const FRotator& Rotacion)
		PURE_VIRTUAL(AFabricaObstaculos::CrearObstaculoPeligroso, return nullptr;);

	// Nombre de la familia que produce esta fabrica
	virtual FString GetNombreFamilia() const
		PURE_VIRTUAL(AFabricaObstaculos::GetNombreFamilia, return FString(););

protected:
	// Plantilla comun a todas las fabricas concretas: coloca en el mundo el producto de tipo T
	template<class T>
	T* CrearObstaculo(const FVector& Posicion, const FRotator& Rotacion)
	{
		UWorld* Mundo = GetWorld();
		if (Mundo == nullptr)
		{
			return nullptr;
		}

		FActorSpawnParameters Parametros;
		Parametros.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		return Mundo->SpawnActor<T>(T::StaticClass(), Posicion, Rotacion, Parametros);
	}
};
