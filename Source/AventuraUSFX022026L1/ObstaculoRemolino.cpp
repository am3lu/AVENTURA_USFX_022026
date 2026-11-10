// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoRemolino.h"

AObstaculoRemolino::AObstaculoRemolino()
{
	NombreObstaculo = TEXT("Remolino");
	Familia = TEXT("Acuatico");
	ConfigurarMalla(EFormaObstaculo::Cilindro, FVector(3.0f, 3.0f, 0.2f), FLinearColor(0.1f, 0.4f, 0.9f), FRotator(0.0f, 0.0f, 0.0f));
	Danio = 5.0f;
	FuerzaEmpuje = 250.0f;
	VelocidadGiro = 180.0f;
}
