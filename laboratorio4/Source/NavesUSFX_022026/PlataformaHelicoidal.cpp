// Fill out your copyright notice in the Description page of Project Settings.


#include "PlataformaHelicoidal.h"

APlataformaHelicoidal::APlataformaHelicoidal()
{
	ColorPlataforma = FLinearColor(0.15f, 0.8f, 0.45f);
}

FVector APlataformaHelicoidal::CalcularDesplazamiento(float TiempoMov) const
{
	const float Ang = Angulo(TiempoMov);
	const float Radio = Amplitud * 0.5f;
	return FVector(Radio * FMath::Sin(Ang), Radio * (1.0f - FMath::Cos(Ang)), Amplitud * 0.5f * (1.0f - FMath::Cos(Ang * 0.25f)));
}
