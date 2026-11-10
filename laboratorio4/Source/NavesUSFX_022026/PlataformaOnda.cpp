// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaOnda.h"

APlataformaOnda::APlataformaOnda()
{
	ColorPlataforma = FLinearColor(0.35f, 0.35f, 0.95f);
}

FVector APlataformaOnda::CalcularDesplazamiento(float TiempoMov) const
{
	const float Ang = Angulo(TiempoMov);
	return FVector(0.0f, Amplitud * OndaTriangular(Fase(TiempoMov)), Amplitud * 0.15f * (1.0f - FMath::Cos(4.0f * Ang)));
}
