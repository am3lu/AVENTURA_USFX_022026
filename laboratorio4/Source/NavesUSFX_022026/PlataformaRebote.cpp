// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaRebote.h"

APlataformaRebote::APlataformaRebote()
{
	ColorPlataforma = FLinearColor(0.55f, 0.4f, 0.25f);
}

FVector APlataformaRebote::CalcularDesplazamiento(float TiempoMov) const
{
	const float FaseActual = Fase(TiempoMov);
	return FVector(
		Amplitud * OndaTriangular(FaseActual),
		Amplitud * 0.7f * OndaTriangular(FaseActual * 1.3f),
		Amplitud * 0.2f * OndaTriangular(FaseActual * 0.7f));
}
