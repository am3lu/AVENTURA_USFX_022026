// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NavesUSFX_022026GameMode.generated.h"

class AEnemigo;
class AInventoryActor;
class AContenedorPlataformas;

UCLASS(MinimalAPI)
class ANavesUSFX_022026GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANavesUSFX_022026GameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// ---- Laboratorio 1: enemigos ----

	// Cuantos enemigos se colocan en la escena al empezar
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemigos")
	int32 CantidadEnemigos;

	// Zona del escenario donde aparecen y por donde se mueven (centro y mitad del tamano en cada eje)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemigos")
	FVector CentroZona;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemigos")
	FVector ExtensionZona;

	// Cada enemigo recibe una velocidad al azar entre estos dos valores (cm/s)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemigos")
	float VelocidadMinima;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemigos")
	float VelocidadMaxima;

	// ---- Laboratorio 3: objetos del inventario ----

	// Cuantos objetos recogibles se colocan en la escena al empezar
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventario")
	int32 CantidadObjetos;

	// Zona donde aparecen los objetos (centro y mitad del tamano en cada eje)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventario")
	FVector CentroObjetos;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventario")
	FVector ExtensionObjetos;

	// ---- Laboratorio 4: plataformas ----

	// Cuantas plataformas guarda el contenedor (minimo 200)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plataformas")
	int32 CantidadPlataformas;

private:
	void CrearEnemigos(UWorld* Mundo);
	void CrearObjetos(UWorld* Mundo);
	void CrearPlataformas(UWorld* Mundo);

	UPROPERTY()
	TArray<AEnemigo*> Enemigos;

	UPROPERTY()
	TArray<AInventoryActor*> Objetos;

	UPROPERTY()
	AContenedorPlataformas* Contenedor;
};
