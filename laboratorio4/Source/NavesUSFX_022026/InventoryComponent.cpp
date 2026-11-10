// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "InventoryActor.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// No necesita Tick: solo guarda y entrega objetos cuando se lo piden
	PrimaryComponentTick.bCanEverTick = false;
}

int32 UInventoryComponent::AddToInventory(AInventoryActor* ActorToAdd)
{
	if (ActorToAdd == nullptr || CurrentInventory.Contains(ActorToAdd))
	{
		return INDEX_NONE;
	}
	return CurrentInventory.Add(ActorToAdd);
}

void UInventoryComponent::RemoveFromInventory(AInventoryActor* ActorToRemove)
{
	CurrentInventory.Remove(ActorToRemove);
}
