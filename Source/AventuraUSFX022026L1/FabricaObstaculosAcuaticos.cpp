// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaObstaculosAcuaticos.h"
#include "ObstaculoIceberg.h"
#include "ObstaculoBoya.h"
#include "ObstaculoRemolino.h"

AObstaculoFijo* AFabricaObstaculosAcuaticos::CrearObstaculoFijo(const FVector& Posicion, const FRotator& Rotacion)
{
	return CrearObstaculo<AObstaculoIceberg>(Posicion, Rotacion);
}

AObstaculoMovil* AFabricaObstaculosAcuaticos::CrearObstaculoMovil(const FVector& Posicion, const FRotator& Rotacion)
{
	return CrearObstaculo<AObstaculoBoya>(Posicion, Rotacion);
}

AObstaculoPeligroso* AFabricaObstaculosAcuaticos::CrearObstaculoPeligroso(const FVector& Posicion, const FRotator& Rotacion)
{
	return CrearObstaculo<AObstaculoRemolino>(Posicion, Rotacion);
}
