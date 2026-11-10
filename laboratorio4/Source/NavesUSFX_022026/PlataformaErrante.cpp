// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaErrante.h"

APlataformaErrante::APlataformaErrante()
{
	ColorPlataforma = FLinearColor(0.9f, 0.9f, 0.9f);
}

FVector APlataformaErrante::CalcularDesplazamiento(float TiempoMov) const
{
	const float Ang = Angulo(TiempoMov);
	const float Px = FaseAleatoria;
	const float Py = FaseAleatoria * 1.7f;
	const float Pz = FaseAleatoria * 2.3f;
	return FVector(
		Amplitud * 0.6f * (FMath::Sin(Ang + Px) - FMath::Sin(Px)),
		Amplitud * 0.6f * (FMath::Sin(1.7f * Ang + Py) - FMath::Sin(Py)),
		Amplitud * 0.15f * (FMath::Sin(2.3f * Ang + Pz) - FMath::Sin(Pz)));
}
