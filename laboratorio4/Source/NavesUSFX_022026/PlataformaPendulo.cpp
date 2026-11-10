// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaPendulo.h"

APlataformaPendulo::APlataformaPendulo()
{
	ColorPlataforma = FLinearColor(0.65f, 0.35f, 0.95f);
}

FVector APlataformaPendulo::CalcularDesplazamiento(float TiempoMov) const
{
	const float Theta = FMath::DegreesToRadians(60.0f) * FMath::Sin(Angulo(TiempoMov));
	return FVector(Amplitud * FMath::Sin(Theta), 0.0f, Amplitud * (1.0f - FMath::Cos(Theta)));
}
