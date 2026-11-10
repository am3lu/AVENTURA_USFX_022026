// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "AventuraUSFX022026L1GameMode.generated.h"

class APlataforma;
class AInventory;
class AFabricaObstaculos;
class AObstaculo;

UCLASS(MinimalAPI)
class AAventuraUSFX022026L1GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AAventuraUSFX022026L1GameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	AInventory* Inventory;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	TArray<APlataforma*> aPlataformas;
	
	FTimerHandle TimerEliminarPlataforma;

	void EliminarPlataforma();

	int tipoPlataformaActual;

	// ---- Laboratorio 5: obstaculos creados con el patron Abstract Factory ----

	// Cuantos obstaculos coloca cada fabrica (se reparten en fijo, movil y peligroso)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Obstaculos")
	int32 ObstaculosPorFamilia;

	// Altura (Z) a la que se colocan los obstaculos
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Obstaculos")
	float AlturaObstaculos;

	// Distancia desde el centro del escenario hasta el centro de cada zona
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Obstaculos")
	float DistanciaZonas;

	// Mitad del lado de cada zona cuadrada donde se reparten los obstaculos
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Obstaculos")
	float RadioZona;

	// Crea las cuatro fabricas concretas y coloca los obstaculos de cada familia en su zona
	void ColocarObstaculos();

private:
	// Coloca los obstaculos de UNA familia usando solo la interfaz abstracta de la fabrica
	void ColocarFamilia(AFabricaObstaculos* Fabrica, const FVector& Centro);

	UPROPERTY()
	TArray<AObstaculo*> Obstaculos;
};



