// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class AInventoryActor;

/**
 * Permite que el actor que lo contiene guarde AInventoryActor en un inventario
 * y los vuelva a colocar en el mundo.
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NAVESUSFX_022026_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();

	// Objetos que lleva guardados (el ultimo es el que se suelta primero)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventario")
	TArray<AInventoryActor*> CurrentInventory;

	// Agrega el objeto y devuelve su posicion en el inventario (o -1 si no se pudo)
	UFUNCTION(BlueprintCallable, Category = "Inventario")
	int32 AddToInventory(AInventoryActor* ActorToAdd);

	// Quita el objeto del inventario
	UFUNCTION(BlueprintCallable, Category = "Inventario")
	void RemoveFromInventory(AInventoryActor* ActorToRemove);
};
