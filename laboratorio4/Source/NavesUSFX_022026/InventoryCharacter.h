// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InventoryCharacter.generated.h"

class AInventoryActor;
class UCameraComponent;
class UInventoryComponent;

/**
 * Personaje del jugador con inventario: recoge los AInventoryActor contra los que choca
 * y suelta el ultimo recogido con la tecla Q (accion "DropItem").
 */
UCLASS()
class NAVESUSFX_022026_API AInventoryCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AInventoryCharacter();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Se llama cuando el personaje choca contra algo mientras se mueve
	virtual void NotifyHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp,
		bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventario")
	UInventoryComponent* MyInventory;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camara")
	UCameraComponent* Camara;

	// Guarda el objeto en el inventario
	UFUNCTION(BlueprintCallable, Category = "Inventario")
	void TakeItem(AInventoryActor* InventoryItem);

	// Suelta el ultimo objeto recogido delante del personaje
	UFUNCTION(BlueprintCallable, Category = "Inventario")
	void DropItem();

protected:
	void MoveForward(float Value);
	void MoveRight(float Value);

private:
	// Momento (segundos de juego) en que se solto el ultimo objeto, para no recogerlo de inmediato
	float UltimoSoltado;

	void MostrarInventario(const FString& Mensaje);
};
