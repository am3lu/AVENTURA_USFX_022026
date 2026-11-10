// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaOrbital.h"

APlataformaOrbital::APlataformaOrbital()
{
	ColorPlataforma = FLinearColor(0.6f, 0.9f, 0.25f);
}

FVector APlataformaOrbital::CalcularDesplazamiento(float TiempoMov) const
{
	const float Ang = Angulo(TiempoMov);
	const float Radio = Amplitud * 0.5f;
	return FVector(Radio * FMath::Sin(Ang), 0.0f, Radio * (1.0f - FMath::Cos(Ang)));
}
