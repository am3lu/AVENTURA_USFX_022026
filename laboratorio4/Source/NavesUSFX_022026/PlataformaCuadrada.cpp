// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaCuadrada.h"

APlataformaCuadrada::APlataformaCuadrada()
{
	ColorPlataforma = FLinearColor(0.95f, 0.35f, 0.8f);
}

FVector APlataformaCuadrada::CalcularDesplazamiento(float TiempoMov) const
{
	const float Recorrido = FMath::Fmod(Fase(TiempoMov), 1.0f) * 4.0f;
	const int32 Lado = FMath::Clamp(FMath::FloorToInt(Recorrido), 0, 3);
	const float U = Recorrido - Lado;

	switch (Lado)
	{
	case 0:  return FVector(Amplitud * U, 0.0f, 0.0f);
	case 1:  return FVector(Amplitud, Amplitud * U, 0.0f);
	case 2:  return FVector(Amplitud * (1.0f - U), Amplitud, 0.0f);
	default: return FVector(0.0f, Amplitud * (1.0f - U), 0.0f);
	}
}
