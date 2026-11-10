// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoNube.h"

AObstaculoNube::AObstaculoNube()
{
	NombreObstaculo = TEXT("Nube");
	Familia = TEXT("Aereo");
	ConfigurarMalla(EFormaObstaculo::Esfera, FVector(3.0f, 2.0f, 1.2f), FLinearColor(0.95f, 0.95f, 1.0f), FRotator(0.0f, 0.0f, 0.0f));
}
