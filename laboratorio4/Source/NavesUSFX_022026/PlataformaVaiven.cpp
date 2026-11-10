// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaVaiven.h"

APlataformaVaiven::APlataformaVaiven()
{
	ColorPlataforma = FLinearColor(0.95f, 0.3f, 0.3f);
}

FVector APlataformaVaiven::CalcularDesplazamiento(float TiempoMov) const
{
	return FVector(Amplitud * OndaTriangular(Fase(TiempoMov)), 0.0f, 0.0f);
}
