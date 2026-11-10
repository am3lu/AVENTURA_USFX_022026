// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoIceberg.h"

AObstaculoIceberg::AObstaculoIceberg()
{
	NombreObstaculo = TEXT("Iceberg");
	Familia = TEXT("Acuatico");
	ConfigurarMalla(EFormaObstaculo::Cono, FVector(3.0f, 3.0f, 3.0f), FLinearColor(0.7f, 0.9f, 1.0f), FRotator(0.0f, 0.0f, 0.0f));
}
