// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoEstalactita.h"

AObstaculoEstalactita::AObstaculoEstalactita()
{
	NombreObstaculo = TEXT("Estalactita");
	Familia = TEXT("Subterraneo");
	ConfigurarMalla(EFormaObstaculo::Cono, FVector(1.0f, 1.0f, 2.5f), FLinearColor(0.4f, 0.33f, 0.3f), FRotator(180.0f, 0.0f, 0.0f));
}
