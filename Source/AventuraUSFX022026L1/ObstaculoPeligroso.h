// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstaculo.h"
#include "ObstaculoPeligroso.generated.h"

/**
 * Producto abstracto C: obstaculo que se puede atravesar pero castiga al pawn que lo toca:
 * lo empuja hacia afuera y le aplica dano. Late y puede girar.
 */
UCLASS(Abstract)
class AVENTURAUSFX022026L1_API AObstaculoPeligroso : public AObstaculo
{
	GENERATED_BODY()

public:
	AObstaculoPeligroso();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual FString GetTipo() const override { return TEXT("Peligroso"); }

protected:
	virtual void BeginPlay() override;

	// Dano que aplica al tocarlo
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstaculo|Peligro")
	float Danio;

	// Distancia (cm) a la que empuja al pawn hacia afuera
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstaculo|Peligro")
	float FuerzaEmpuje;

	// Giro continuo (grados por segundo); 0 = no gira
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Obstaculo|Peligro")
	float VelocidadGiro;

	UFUNCTION()
	void AlSolapar(UPrimitiveComponent* ComponenteSolapado, AActor* OtroActor, UPrimitiveComponent* OtroComponente,
		int32 OtroIndiceCuerpo, bool bDesdeBarrido, const FHitResult& ResultadoBarrido);

private:
	FVector EscalaBase;
	float TiempoPulso;
};
