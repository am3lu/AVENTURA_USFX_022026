// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaCircular.h"

APlataformaCircular::APlataformaCircular()
{
	ColorPlataforma = FLinearColor(0.98f, 0.88f, 0.2f);
}

FVector APlataformaCircular::CalcularDesplazamiento(float TiempoMov) const
{
	const float Ang = Angulo(TiempoMov);
	return FVector(Amplitud * FMath::Sin(Ang), Amplitud * (1.0f - FMath::Cos(Ang)), 0.0f);
}
