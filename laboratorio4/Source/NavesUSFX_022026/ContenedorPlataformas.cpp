// Fill out your copyright notice in the Description page of Project Settings.


#include "ContenedorPlataformas.h"
#include "NavesUSFX_022026.h"
#include "Plataforma.h"
#include "PlataformaVaiven.h"
#include "PlataformaAscensor.h"
#include "PlataformaCircular.h"
#include "PlataformaOrbital.h"
#include "PlataformaHelicoidal.h"
#include "PlataformaOcho.h"
#include "PlataformaZigzag.h"
#include "PlataformaOnda.h"
#include "PlataformaPendulo.h"
#include "PlataformaCuadrada.h"
#include "PlataformaErrante.h"
#include "PlataformaRebote.h"
#include "Components/SceneComponent.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
AContenedorPlataformas::AContenedorPlataformas()
{
	// El contenedor no necesita Tick: trabaja con un timer
	PrimaryActorTick.bCanEverTick = false;

	Raiz = CreateDefaultSubobject<USceneComponent>(TEXT("Raiz"));
	RootComponent = Raiz;

	CentroZona = FVector(2500.0f, 0.0f, 0.0f);
	Columnas = 20;
	Separacion = 450.0f;
	AlturaMinima = 350.0f;
	AlturaMaxima = 1100.0f;

	AmplitudMinima = 200.0f;
	AmplitudMaxima = 500.0f;
	FrecuenciaMinima = 0.08f;
	FrecuenciaMaxima = 0.25f;

	IntervaloDesaparicion = 0.3f;
	RetrasoDesaparicion = 5.0f;
}

void AContenedorPlataformas::Iniciar(int32 Cantidad)
{
	CrearPlataformas(FMath::Max(Cantidad, static_cast<int32>(CantidadMinima)));

	// Una sola vez se programa el timer; se repite cada IntervaloDesaparicion
	GetWorldTimerManager().SetTimer(TimerDesaparicion, this, &AContenedorPlataformas::EliminarPlataformaAleatoria,
		IntervaloDesaparicion, true, RetrasoDesaparicion);
}

void AContenedorPlataformas::CrearPlataformas(int32 Cantidad)
{
	UWorld* Mundo = GetWorld();
	if (Mundo == nullptr)
	{
		return;
	}

	// Un tipo de plataforma por cada forma de moverse; se reparten de forma rotativa
	const TArray<UClass*> Tipos = {
		APlataformaVaiven::StaticClass(),
		APlataformaAscensor::StaticClass(),
		APlataformaCircular::StaticClass(),
		APlataformaOrbital::StaticClass(),
		APlataformaHelicoidal::StaticClass(),
		APlataformaOcho::StaticClass(),
		APlataformaZigzag::StaticClass(),
		APlataformaOnda::StaticClass(),
		APlataformaPendulo::StaticClass(),
		APlataformaCuadrada::StaticClass(),
		APlataformaErrante::StaticClass(),
		APlataformaRebote::StaticClass()
	};

	FActorSpawnParameters Parametros;
	Parametros.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	const int32 ColumnasUsadas = FMath::Max(Columnas, 1);
	const int32 Filas = FMath::CeilToInt(static_cast<float>(Cantidad) / ColumnasUsadas);

	Plataformas.Empty(Cantidad);
	for (int32 i = 0; i < Cantidad; i++)
	{
		const int32 Fila = i / ColumnasUsadas;
		const int32 Columna = i % ColumnasUsadas;

		// Cuadricula centrada en CentroZona, cada plataforma a una altura distinta
		const FVector Posicion(
			CentroZona.X + (Fila - (Filas - 1) * 0.5f) * Separacion,
			CentroZona.Y + (Columna - (ColumnasUsadas - 1) * 0.5f) * Separacion,
			FMath::RandRange(AlturaMinima, AlturaMaxima));

		APlataforma* Plataforma = Mundo->SpawnActor<APlataforma>(Tipos[i % Tipos.Num()], Posicion, FRotator::ZeroRotator, Parametros);
		if (Plataforma != nullptr)
		{
			Plataforma->ConfigurarMovimiento(
				FMath::RandRange(AmplitudMinima, AmplitudMaxima),
				FMath::RandRange(FrecuenciaMinima, FrecuenciaMaxima));
			Plataformas.Add(Plataforma);
		}
	}

	UE_LOG(LogNavesUSFX_022026, Log, TEXT("Plataformas creadas: %d"), Plataformas.Num());
	if (GEngine != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Orange, FString::Printf(TEXT("Plataformas creadas: %d"), Plataformas.Num()));
	}
}

void AContenedorPlataformas::EliminarPlataformaAleatoria()
{
	// Descarta referencias a plataformas que ya no existan
	for (int32 i = Plataformas.Num() - 1; i >= 0; i--)
	{
		if (!IsValid(Plataformas[i]))
		{
			Plataformas.RemoveAtSwap(i);
		}
	}

	if (Plataformas.Num() == 0)
	{
		GetWorldTimerManager().ClearTimer(TimerDesaparicion);
		return;
	}

	const int32 Indice = FMath::RandRange(0, Plataformas.Num() - 1);
	Plataformas[Indice]->Destroy();
	Plataformas.RemoveAtSwap(Indice);

	if (GEngine != nullptr)
	{
		// Misma clave (2) para que el mensaje se reemplace y no se apilen
		GEngine->AddOnScreenDebugMessage(2, 1.0f, FColor::Orange, FString::Printf(TEXT("Plataformas restantes: %d"), Plataformas.Num()));
	}
}
