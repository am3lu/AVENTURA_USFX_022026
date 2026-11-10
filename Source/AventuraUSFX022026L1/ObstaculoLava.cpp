// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoLava.h"

AObstaculoLava::AObstaculoLava()
{
	NombreObstaculo = TEXT("Lava");
	Familia = TEXT("Subterraneo");
	ConfigurarMalla(EFormaObstaculo::Cubo, FVector(3.0f, 3.0f, 0.15f), FLinearColor(1.0f, 0.35f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
	Danio = 25.0f;
	FuerzaEmpuje = 250.0f;
	VelocidadGiro = 0.0f;
}
