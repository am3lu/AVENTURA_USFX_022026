// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoTormenta.h"

AObstaculoTormenta::AObstaculoTormenta()
{
	NombreObstaculo = TEXT("Tormenta");
	Familia = TEXT("Aereo");
	ConfigurarMalla(EFormaObstaculo::Esfera, FVector(2.0f, 2.0f, 1.0f), FLinearColor(0.3f, 0.3f, 0.45f), FRotator(0.0f, 0.0f, 0.0f));
	Danio = 20.0f;
	FuerzaEmpuje = 500.0f;
	VelocidadGiro = 90.0f;
}
