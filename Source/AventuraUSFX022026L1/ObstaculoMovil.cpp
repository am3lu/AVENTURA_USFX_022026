// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoMovil.h"

AObstaculoMovil::AObstaculoMovil()
{
	PrimaryActorTick.bCanEverTick = true;

	EjeMovimiento = FVector(1.0f, 0.0f, 0.0f);
	Recorrido = 400.0f;
	Velocidad = 150.0f;

	PosicionInicial = FVector::ZeroVector;
	Distancia = 0.0f;
	Sentido = 1.0f;
}

void AObstaculoMovil::BeginPlay()
{
	Super::BeginPlay();

	PosicionInicial = GetActorLocation();
}

void AObstaculoMovil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Distancia += Sentido * Velocidad * DeltaTime;

	// Al llegar a un extremo da la vuelta
	if (Distancia >= Recorrido)
	{
		Distancia = Recorrido;
		Sentido = -1.0f;
	}
	else if (Distancia <= -Recorrido)
	{
		Distancia = -Recorrido;
		Sentido = 1.0f;
	}

	SetActorLocation(PosicionInicial + EjeMovimiento.GetSafeNormal() * Distancia);
}
