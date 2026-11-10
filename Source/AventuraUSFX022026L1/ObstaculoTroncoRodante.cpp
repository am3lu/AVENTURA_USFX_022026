// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoTroncoRodante.h"

AObstaculoTroncoRodante::AObstaculoTroncoRodante()
{
	NombreObstaculo = TEXT("Tronco rodante");
	Familia = TEXT("Terrestre");
	ConfigurarMalla(EFormaObstaculo::Cilindro, FVector(0.6f, 0.6f, 2.5f), FLinearColor(0.45f, 0.28f, 0.12f), FRotator(0.0f, 0.0f, 90.0f));
	EjeMovimiento = FVector(1.0f, 0.0f, 0.0f);
	Recorrido = 500.0f;
	Velocidad = 150.0f;
}
