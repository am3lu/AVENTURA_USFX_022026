// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaAscensor.h"

APlataformaAscensor::APlataformaAscensor()
{
	ColorPlataforma = FLinearColor(0.98f, 0.6f, 0.15f);
}

FVector APlataformaAscensor::CalcularDesplazamiento(float TiempoMov) const
{
	return FVector(0.0f, 0.0f, Amplitud * 0.5f * (1.0f - FMath::Cos(Angulo(TiempoMov))));
}
