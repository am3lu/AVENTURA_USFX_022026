// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaZigzag.h"

APlataformaZigzag::APlataformaZigzag()
{
	ColorPlataforma = FLinearColor(0.2f, 0.55f, 0.95f);
}

FVector APlataformaZigzag::CalcularDesplazamiento(float TiempoMov) const
{
	const float FaseActual = Fase(TiempoMov);
	return FVector(Amplitud * OndaTriangular(FaseActual), Amplitud * 0.3f * OndaTriangular(FaseActual * 5.0f), 0.0f);
}
