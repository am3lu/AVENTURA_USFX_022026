// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoPinchos.h"

AObstaculoPinchos::AObstaculoPinchos()
{
	NombreObstaculo = TEXT("Pinchos");
	Familia = TEXT("Terrestre");
	ConfigurarMalla(EFormaObstaculo::Cono, FVector(1.0f, 1.0f, 1.5f), FLinearColor(0.8f, 0.1f, 0.1f), FRotator(0.0f, 0.0f, 0.0f));
	Danio = 10.0f;
	FuerzaEmpuje = 300.0f;
	VelocidadGiro = 0.0f;
}
