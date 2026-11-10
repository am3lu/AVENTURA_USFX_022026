// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoRoca.h"

AObstaculoRoca::AObstaculoRoca()
{
	NombreObstaculo = TEXT("Roca");
	Familia = TEXT("Terrestre");
	ConfigurarMalla(EFormaObstaculo::Cubo, FVector(2.0f, 2.0f, 1.5f), FLinearColor(0.45f, 0.45f, 0.45f), FRotator(0.0f, 0.0f, 0.0f));
}
