// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaObstaculosSubterraneos.h"
#include "ObstaculoEstalactita.h"
#include "ObstaculoVagoneta.h"
#include "ObstaculoLava.h"

AObstaculoFijo* AFabricaObstaculosSubterraneos::CrearObstaculoFijo(const FVector& Posicion, const FRotator& Rotacion)
{
	return CrearObstaculo<AObstaculoEstalactita>(Posicion, Rotacion);
}

AObstaculoMovil* AFabricaObstaculosSubterraneos::CrearObstaculoMovil(const FVector& Posicion, const FRotator& Rotacion)
{
	return CrearObstaculo<AObstaculoVagoneta>(Posicion, Rotacion);
}

AObstaculoPeligroso* AFabricaObstaculosSubterraneos::CrearObstaculoPeligroso(const FVector& Posicion, const FRotator& Rotacion)
{
	return CrearObstaculo<AObstaculoLava>(Posicion, Rotacion);
}
