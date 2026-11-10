// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaOcho.h"

APlataformaOcho::APlataformaOcho()
{
	ColorPlataforma = FLinearColor(0.1f, 0.8f, 0.8f);
}

FVector APlataformaOcho::CalcularDesplazamiento(float TiempoMov) const
{
	const float Ang = Angulo(TiempoMov);
	return FVector(Amplitud * FMath::Sin(Ang), Amplitud * 0.5f * FMath::Sin(2.0f * Ang), 0.0f);
}
