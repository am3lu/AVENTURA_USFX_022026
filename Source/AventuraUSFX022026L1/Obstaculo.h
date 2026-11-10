// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Obstaculo.generated.h"

class USceneComponent;
class UStaticMeshComponent;

// Formas incluidas en el motor (no dependen del Content del proyecto)
enum class EFormaObstaculo
{
	Cubo,
	Esfera,
	Cilindro,
	Cono
};

/**
 * Producto abstracto raiz del patron ABSTRACT FACTORY. Todo obstaculo tiene una malla,
 * un nombre, una familia (Terrestre, Acuatico, Aereo o Subterraneo) y un tipo
 * (Fijo, Movil o Peligroso) que define cada clase intermedia.
 */
UCLASS(Abstract)
class AVENTURAUSFX022026L1_API AObstaculo : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AObstaculo();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstaculo")
	FString NombreObstaculo;

	// Familia a la que pertenece: la fija la fabrica concreta que lo crea
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstaculo")
	FString Familia;

	// Fijo, Movil o Peligroso (lo define cada clase intermedia)
	virtual FString GetTipo() const
		PURE_VIRTUAL(AObstaculo::GetTipo, return FString(););

	// Texto legible, por ejemplo "Roca [Fijo - Terrestre]"
	FString Describir() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Elige la forma, la escala, el color y (opcional) el giro de la malla
	void ConfigurarMalla(EFormaObstaculo Forma, const FVector& Escala, const FLinearColor& NuevoColor,
		const FRotator& Giro = FRotator::ZeroRotator);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Obstaculo")
	USceneComponent* Raiz;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Obstaculo")
	UStaticMeshComponent* Malla;

private:
	FLinearColor Color;
};
