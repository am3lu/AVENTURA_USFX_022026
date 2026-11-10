// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaObstaculosTerrestres.h"
#include "ObstaculoRoca.h"
#include "ObstaculoTroncoRodante.h"
#include "ObstaculoPinchos.h"

AObstaculoFijo* AFabricaObstaculosTerrestres::CrearObstaculoFijo(const FVector& Posicion, const FRotator& Rotacion)
{
	return CrearObstaculo<AObstaculoRoca>(Posicion, Rotacion);
}

AObstaculoMovil* AFabricaObstaculosTerrestres::CrearObstaculoMovil(const FVector& Posicion, const FRotator& Rotacion)
{
	return CrearObstaculo<AObstaculoTroncoRodante>(Posicion, Rotacion);
}

AObstaculoPeligroso* AFabricaObstaculosTerrestres::CrearObstaculoPeligroso(const FVector& Posicion, const FRotator& Rotacion)
{
	return CrearObstaculo<AObstaculoPinchos>(Posicion, Rotacion);
}
