// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesUSFX_022026GameMode.h"
#include "NavesUSFX_022026.h"
#include "Enemigo.h"
#include "InventoryActor.h"
#include "InventoryCharacter.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

ANavesUSFX_022026GameMode::ANavesUSFX_022026GameMode()
{
	// Laboratorio 3: el jugador es un personaje con inventario
	DefaultPawnClass = AInventoryCharacter::StaticClass();

	// Laboratorio 1: enemigos
	CantidadEnemigos = 10;
	CentroZona = FVector(1500.0f, 0.0f, 500.0f);
	ExtensionZona = FVector(1200.0f, 1500.0f, 400.0f);
	VelocidadMinima = 250.0f;
	VelocidadMaxima = 600.0f;

	// Laboratorio 3: objetos recogibles (aparecen en el aire delante del jugador y caen al piso)
	CantidadObjetos = 8;
	CentroObjetos = FVector(700.0f, 0.0f, 150.0f);
	ExtensionObjetos = FVector(500.0f, 800.0f, 0.0f);
}

void ANavesUSFX_022026GameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* Mundo = GetWorld();
	if (Mundo == nullptr)
	{
		return;
	}

	CrearEnemigos(Mundo);
	CrearObjetos(Mundo);
}

void ANavesUSFX_022026GameMode::CrearEnemigos(UWorld* Mundo)
{
	FActorSpawnParameters Parametros;
	Parametros.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// Se colocan los enemigos en la escena por codigo, en puntos al azar de la zona
	for (int32 i = 0; i < CantidadEnemigos; i++)
	{
		const FVector PosicionInicial = CentroZona + FVector(
			FMath::RandRange(-ExtensionZona.X, ExtensionZona.X),
			FMath::RandRange(-ExtensionZona.Y, ExtensionZona.Y),
			FMath::RandRange(-ExtensionZona.Z, ExtensionZona.Z));

		AEnemigo* Enemigo = Mundo->SpawnActor<AEnemigo>(AEnemigo::StaticClass(), PosicionInicial, FRotator::ZeroRotator, Parametros);
		if (Enemigo != nullptr)
		{
			Enemigo->SetVelocidad(FMath::RandRange(VelocidadMinima, VelocidadMaxima));
			Enemigo->DefinirZonaMovimiento(CentroZona, ExtensionZona);
			Enemigos.Add(Enemigo);
		}
	}

	UE_LOG(LogNavesUSFX_022026, Log, TEXT("Enemigos creados: %d"), Enemigos.Num());
	if (GEngine != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Yellow, FString::Printf(TEXT("Enemigos creados: %d"), Enemigos.Num()));
	}
}

void ANavesUSFX_022026GameMode::CrearObjetos(UWorld* Mundo)
{
	FActorSpawnParameters Parametros;
	Parametros.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	// Objetos recogibles repartidos por el escenario, tambien creados por codigo
	for (int32 i = 0; i < CantidadObjetos; i++)
	{
		const FVector Posicion = CentroObjetos + FVector(
			FMath::RandRange(-ExtensionObjetos.X, ExtensionObjetos.X),
			FMath::RandRange(-ExtensionObjetos.Y, ExtensionObjetos.Y),
			FMath::RandRange(-ExtensionObjetos.Z, ExtensionObjetos.Z));

		AInventoryActor* Objeto = Mundo->SpawnActor<AInventoryActor>(AInventoryActor::StaticClass(), Posicion, FRotator::ZeroRotator, Parametros);
		if (Objeto != nullptr)
		{
			Objeto->NombreObjeto = FString::Printf(TEXT("Objeto %d"), i + 1);
			Objetos.Add(Objeto);
		}
	}

	UE_LOG(LogNavesUSFX_022026, Log, TEXT("Objetos de inventario creados: %d"), Objetos.Num());
	if (GEngine != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Cyan, FString::Printf(TEXT("Objetos para recoger: %d (choca con ellos; Q para soltar)"), Objetos.Num()));
	}
}
