// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoGlobo.h"

AObstaculoGlobo::AObstaculoGlobo()
{
	NombreObstaculo = TEXT("Globo");
	Familia = TEXT("Aereo");
	ConfigurarMalla(EFormaObstaculo::Esfera, FVector(1.0f, 1.0f, 1.3f), FLinearColor(1.0f, 0.2f, 0.4f), FRotator(0.0f, 0.0f, 0.0f));
	EjeMovimiento = FVector(0.0f, 0.0f, 1.0f);
	Recorrido = 250.0f;
	Velocidad = 100.0f;
}
