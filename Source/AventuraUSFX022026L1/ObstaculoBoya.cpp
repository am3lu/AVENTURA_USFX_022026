// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoBoya.h"

AObstaculoBoya::AObstaculoBoya()
{
	NombreObstaculo = TEXT("Boya");
	Familia = TEXT("Acuatico");
	ConfigurarMalla(EFormaObstaculo::Esfera, FVector(1.0f, 1.0f, 1.0f), FLinearColor(1.0f, 0.5f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	EjeMovimiento = FVector(0.0f, 1.0f, 0.0f);
	Recorrido = 400.0f;
	Velocidad = 120.0f;
}
