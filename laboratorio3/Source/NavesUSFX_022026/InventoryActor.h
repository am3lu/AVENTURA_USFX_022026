// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "InventoryActor.generated.h"

/**
 * Objeto que se puede recoger y guardar en un inventario (receta "Creating an InventoryComponent
 * for an RPG", cap. 4 del libro). Cuando esta en el mundo es un actor con fisica; al recogerlo
 * se oculta y deja de interactuar; al soltarlo vuelve a aparecer en el lugar indicado.
 */
UCLASS()
class NAVESUSFX_022026_API AInventoryActor : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AInventoryActor();

	// Nombre que se muestra en pantalla
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventario")
	FString NombreObjeto;

	// Si es true el objeto cae y rueda por el escenario (necesita un piso con colision)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventario")
	bool bSimularFisica;

	// Guarda el objeto: lo oculta y le quita fisica, colision y tick
	virtual void PickUp();

	// Devuelve el objeto al mundo en la transformacion indicada
	virtual void PutDown(FTransform TargetLocation);

protected:
	virtual void BeginPlay() override;
};
