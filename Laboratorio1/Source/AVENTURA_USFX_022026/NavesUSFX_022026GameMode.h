// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NavesUSFX_022026GameMode.generated.h"

class AEnemigo;

UCLASS(MinimalAPI)
class ANavesUSFX_022026GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANavesUSFX_022026GameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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

private:
	UPROPERTY()
		TArray<AEnemigo*> Enemigos;
};

