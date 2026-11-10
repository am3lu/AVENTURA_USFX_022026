// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoVagoneta.h"

AObstaculoVagoneta::AObstaculoVagoneta()
{
	NombreObstaculo = TEXT("Vagoneta");
	Familia = TEXT("Subterraneo");
	ConfigurarMalla(EFormaObstaculo::Cubo, FVector(1.5f, 1.0f, 0.8f), FLinearColor(0.5f, 0.5f, 0.55f), FRotator(0.0f, 0.0f, 0.0f));
	EjeMovimiento = FVector(1.0f, 0.0f, 0.0f);
	Recorrido = 600.0f;
	Velocidad = 220.0f;
}
