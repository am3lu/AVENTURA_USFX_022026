// Copyright Epic Games, Inc. All Rights Reserved.

#include "NavesUSFX_022026GameMode.h"
#include "AVENTURA_USFX_022026.h"
#include "Enemigo.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/DefaultPawn.h"

ANavesUSFX_022026GameMode::ANavesUSFX_022026GameMode()
{
	// Pawn volador del motor (WASD + mouse) para recorrer el escenario y ver a los enemigos
	DefaultPawnClass = ADefaultPawn::StaticClass();

	CantidadEnemigos = 10;
	CentroZona = FVector(1500.0f, 0.0f, 500.0f);
	ExtensionZona = FVector(1200.0f, 1500.0f, 400.0f);
	VelocidadMinima = 250.0f;
	VelocidadMaxima = 600.0f;
}

void ANavesUSFX_022026GameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld* Mundo = GetWorld();
	if (Mundo == nullptr)
	{
		return;
	}

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

	UE_LOG(LogTemp, Log, TEXT("Enemigos creados: %d"), Enemigos.Num());
	if (GEngine != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Yellow, FString::Printf(TEXT("Enemigos creados: %d"), Enemigos.Num()));
	}
}
