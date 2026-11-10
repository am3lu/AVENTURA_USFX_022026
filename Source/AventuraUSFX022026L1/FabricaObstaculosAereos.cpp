// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaObstaculosAereos.h"
#include "ObstaculoNube.h"
#include "ObstaculoGlobo.h"
#include "ObstaculoTormenta.h"

AObstaculoFijo* AFabricaObstaculosAereos::CrearObstaculoFijo(const FVector& Posicion, const FRotator& Rotacion)
{
	return CrearObstaculo<AObstaculoNube>(Posicion, Rotacion);
}

AObstaculoMovil* AFabricaObstaculosAereos::CrearObstaculoMovil(const FVector& Posicion, const FRotator& Rotacion)
{
	return CrearObstaculo<AObstaculoGlobo>(Posicion, Rotacion);
}

AObstaculoPeligroso* AFabricaObstaculosAereos::CrearObstaculoPeligroso(const FVector& Posicion, const FRotator& Rotacion)
{
	return CrearObstaculo<AObstaculoTormenta>(Posicion, Rotacion);
}
