// Copyright Epic Games, Inc. All Rights Reserved.

#include "AventuraUSFX022026L1GameMode.h"
#include "AventuraUSFX022026L1Pawn.h"
#include "Plataforma.h"
#include "PlataformaAerea.h"
#include "PlataformaTerrestre.h"
#include "PlataformaSubterranea.h"
#include "PlataformaAcuatica.h"
#include "Inventory.h"
#include "FabricaPlataformas.h"
#include "Obstaculo.h"
#include "ObstaculoFijo.h"
#include "ObstaculoMovil.h"
#include "ObstaculoPeligroso.h"
#include "FabricaObstaculos.h"
#include "FabricaObstaculosTerrestres.h"
#include "FabricaObstaculosAcuaticos.h"
#include "FabricaObstaculosAereos.h"
#include "FabricaObstaculosSubterraneos.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

AAventuraUSFX022026L1GameMode::AAventuraUSFX022026L1GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AAventuraUSFX022026L1Pawn::StaticClass();

	tipoPlataformaActual = 0;

	// Laboratorio 5: obstaculos
	ObstaculosPorFamilia = 9;
	AlturaObstaculos = 100.0f;
	DistanciaZonas = 1000.0f;
	RadioZona = 450.0f;
}

void AAventuraUSFX022026L1GameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();

	if (World == nullptr)
	{
		return;
	}

	//Implementacion de utilizacion de singleton para el inventario
	//Create 4 Inventory
	/*
	for (int i = 0; i <= 4; i++)
	{
		AInventory* SpawnedInventory = GetWorld()->SpawnActor<AInventory>(AInventory::StaticClass());
	
		if (SpawnedInventory)
		{
			//If the Spawn succeeds, set the Spawned inventory to the local one
			//and log the success string
			Inventory = SpawnedInventory;
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s has been created"), *Inventory->GetName()));
		}
	}
	*/

	/*AFabricaPlataformas* FabricaPlataformas = World->SpawnActor<AFabricaPlataformas>(AFabricaPlataformas::StaticClass());
		

	FRotator Rotacion = FRotator::ZeroRotator;
	FVector SpawnLocation = FVector::ZeroVector;
	

	Rotacion = FRotator(0.0f, 0.0f, 0.0f);
	SpawnLocation = FVector(-950.0f, 50.0f, 200.0f);

	for (int i = 0; i < 10; i++) {
		SpawnLocation = FVector(FMath::RandRange(-1500.0f, 1500.0f), FMath::RandRange(-1500.0f, 1500.0f), FMath::RandRange(50.0f, 1000.0f));
		FabricaPlataformas->CrearPlataforma("Aerea", SpawnLocation, Rotacion);
	}*/

	/*
	//ETipoPlataforma tipoPlataformaActual;
	int tipoPlataformaRandom;

	for (int i = 0; i < 50; i++) {
		
		SpawnLocation = FVector(FMath::RandRange(-1500.0f, 1500.0f), FMath::RandRange(-1500.0f, 1500.0f), FMath::RandRange(50.0f, 1000.0f));

		//plataformaActual->movimientoDireccion = FVector(1.0f, 0.0f, 0.0f);
		
		
		tipoPlataformaRandom = FMath::RandRange(0, 3);

		switch (tipoPlataformaRandom) {
			case 0:
				plataformaActual = World->SpawnActor<APlataformaAerea>(SpawnLocation, Rotacion);

				//tipoPlataformaActual = ETipoPlataforma::PLATAFORMA_AEREA;
				break;
			case 1:
				plataformaActual = World->SpawnActor<APlataformaTerrestre>(SpawnLocation, Rotacion);
				//tipoPlataformaActual = ETipoPlataforma::PLATAFORMA_TERRESTRE;
				break;
			case 2:
				plataformaActual = World->SpawnActor<APlataformaSubterranea>(SpawnLocation, Rotacion);
				//tipoPlataformaActual = ETipoPlataforma::PLATAFORMA_SUBTERRANEA;
				break;
			case 3:
				plataformaActual = World->SpawnActor<APlataformaAcuatica>(SpawnLocation, Rotacion);
				//tipoPlataformaActual = ETipoPlataforma::PLATAFORMA_ACUATICA;
				break;
			default:
				//tipoPlataformaActual = ETipoPlataforma::PLATAFORMA_TERRESTRE;
				break;
			}
		
		aPlataformas.Add(plataformaActual);

	}
	*/
	/*

	plataformaActual = World->SpawnActor<APlataformaAerea>(SpawnLocation, Rotacion);
	//plataformaActual->movimientoDireccion = FVector(1.0f, 1.0f, 0.0f);
	aPlataformas.Add(plataformaActual);

	Rotacion = FRotator(0.0f, 0.0f, 0.0f);
	SpawnLocation = FVector(-950.0f, 50.0f, 200.0f);
	
	for (int i = 0; i < 10; i++) {
		SpawnLocation = FVector(FMath::RandRange(-1500.0f, 1500.0f), FMath::RandRange(-1500.0f, 1500.0f), FMath::RandRange(50.0f, 1000.0f));
	
		plataformaActual = World->SpawnActor<APlataforma>(SpawnLocation, Rotacion);
		plataformaActual->movimientoDireccion = FVector(1.0f, 0.0f, 0.0f);
		aPlataformas.Add(plataformaActual);

		plataformaActual = World->SpawnActor<APlataforma>(SpawnLocation, Rotacion);
		plataformaActual->movimientoDireccion = FVector(0.0f, 1.0f, 0.0f);
		aPlataformas.Add(plataformaActual);
	}
	*/
	// Laboratorio 5: obstaculos de varias familias, creados con Abstract Factory
	ColocarObstaculos();

	GetWorldTimerManager().SetTimer(TimerEliminarPlataforma, this, &AAventuraUSFX022026L1GameMode::EliminarPlataforma, 1.0f, true);

}

void AAventuraUSFX022026L1GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAventuraUSFX022026L1GameMode::EliminarPlataforma()
{
	//switch (tipoPlataformaActual){
	//	case 0:
	//		tipoPlataformaActual = 1;
	//		break;
	//	case 1:
	//		tipoPlataformaActual = 2;
	//		break;
	//	case 2:
	//		tipoPlataformaActual = 3;
	//		break;
	//	case 3:
	//		tipoPlataformaActual = 0;
	//		break;
	//	default:
	//		//int32 Indice = FMath::RandRange(0, aPlataformas.Num());
	//		break;
	//}

	for (int32 i = 0; i < aPlataformas.Num(); i++)
	{
		if (aPlataformas[i] != nullptr)
		{
			// Verifica si la plataforma es de tipo ATerrestre
			APlataforma * plataformaActual = aPlataformas[i];

			if (plataformaActual != nullptr)
			{
				if (plataformaActual->tipoPlataforma == static_cast<ETipoPlataforma>(tipoPlataformaActual))
				{
					// Eliminamos el objeto del escenario
					plataformaActual->Destroy();

					// Lo eliminamos también del TArray
					aPlataformas.RemoveAt(i);

					// Salimos del bucle después de eliminar el primero
					break;
				}
			}
		}
	}
	if (tipoPlataformaActual >= 3)
	{
		tipoPlataformaActual = 0;
	}
	else
		tipoPlataformaActual++;

	/*if (aPlataformas.IsValidIndex(Indice))
	{
		if (IsValid(aPlataformas[Indice]))
		{
			aPlataformas[Indice]->Destroy();

			aPlataformas[Indice] = nullptr;
			aPlataformas.RemoveAt(Indice);
		}
	}*/

}

void AAventuraUSFX022026L1GameMode::ColocarObstaculos()
{
	UWorld* Mundo = GetWorld();
	if (Mundo == nullptr)
	{
		return;
	}

	// Una fabrica concreta por familia. De aqui en adelante solo se trabaja con AFabricaObstaculos.
	const TArray<UClass*> ClasesFabricas = {
		AFabricaObstaculosTerrestres::StaticClass(),
		AFabricaObstaculosAcuaticos::StaticClass(),
		AFabricaObstaculosAereos::StaticClass(),
		AFabricaObstaculosSubterraneos::StaticClass()
	};

	// Una zona del escenario para cada familia (las cuatro esquinas)
	const TArray<FVector> Centros = {
		FVector(DistanciaZonas, DistanciaZonas, AlturaObstaculos),
		FVector(-DistanciaZonas, DistanciaZonas, AlturaObstaculos),
		FVector(-DistanciaZonas, -DistanciaZonas, AlturaObstaculos),
		FVector(DistanciaZonas, -DistanciaZonas, AlturaObstaculos)
	};

	for (int32 i = 0; i < ClasesFabricas.Num(); i++)
	{
		AFabricaObstaculos* Fabrica = Mundo->SpawnActor<AFabricaObstaculos>(ClasesFabricas[i], FVector::ZeroVector, FRotator::ZeroRotator);
		if (Fabrica != nullptr)
		{
			ColocarFamilia(Fabrica, Centros[i]);
		}
	}

	UE_LOG(LogTemp, Log, TEXT("Obstaculos colocados: %d"), Obstaculos.Num());
	if (GEngine != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Orange, FString::Printf(TEXT("Obstaculos colocados: %d (4 familias x 3 tipos)"), Obstaculos.Num()));
	}
}

void AAventuraUSFX022026L1GameMode::ColocarFamilia(AFabricaObstaculos* Fabrica, const FVector& Centro)
{
	for (int32 i = 0; i < ObstaculosPorFamilia; i++)
	{
		const FVector Posicion = Centro + FVector(FMath::RandRange(-RadioZona, RadioZona), FMath::RandRange(-RadioZona, RadioZona), 0.0f);
		const FRotator Rotacion(0.0f, FMath::RandRange(0.0f, 360.0f), 0.0f);

		// La fabrica decide la clase concreta; aqui solo se pide un fijo, un movil o un peligroso
		AObstaculo* Obstaculo = nullptr;
		switch (i % 3)
		{
		case 0:
			Obstaculo = Fabrica->CrearObstaculoFijo(Posicion, Rotacion);
			break;
		case 1:
			Obstaculo = Fabrica->CrearObstaculoMovil(Posicion, Rotacion);
			break;
		default:
			Obstaculo = Fabrica->CrearObstaculoPeligroso(Posicion, Rotacion);
			break;
		}

		if (Obstaculo != nullptr)
		{
			Obstaculos.Add(Obstaculo);
			UE_LOG(LogTemp, Log, TEXT("%s en %s"), *Obstaculo->Describir(), *Posicion.ToString());
		}
	}
}
