// Fill out your copyright notice in the Description page of Project Settings.


#include "Plataforma.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
APlataforma::APlataforma()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MallaPlataforma = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaPlataforma"));
	RootComponent = MallaPlataforma;

	// Malla incluida en el motor (no depende del Content del proyecto): un cubo aplastado
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (MallaAsset.Succeeded())
	{
		MallaPlataforma->SetStaticMesh(MallaAsset.Object);
	}
	MallaPlataforma->SetMobility(EComponentMobility::Movable);
	MallaPlataforma->SetRelativeScale3D(FVector(3.0f, 3.0f, 0.3f));

	DuracionPausa = 5.0f;
	DuracionMovimiento = 10.0f;
	Amplitud = 300.0f;
	Frecuencia = 0.2f;

	ColorPlataforma = FLinearColor::White;
	FaseAleatoria = 0.0f;

	PosicionInicial = FVector::ZeroVector;
	TiempoEnFase = 0.0f;
	TiempoMovimiento = 0.0f;
	bEnMovimiento = false;
}

// Called when the game starts or when spawned
void APlataforma::BeginPlay()
{
	Super::BeginPlay();

	// El movimiento siempre se calcula respecto al punto donde aparecio
	PosicionInicial = GetActorLocation();
	FaseAleatoria = FMath::FRandRange(0.0f, 2.0f * PI);

	UMaterialInstanceDynamic* Material = MallaPlataforma->CreateAndSetMaterialInstanceDynamic(0);
	if (Material != nullptr)
	{
		Material->SetVectorParameterValue(TEXT("Color"), ColorPlataforma);
	}
}

void APlataforma::ConfigurarMovimiento(float NuevaAmplitud, float NuevaFrecuencia)
{
	Amplitud = NuevaAmplitud;
	Frecuencia = NuevaFrecuencia;
}

float APlataforma::Fase(float TiempoMov) const
{
	return TiempoMov * Frecuencia;
}

float APlataforma::Angulo(float TiempoMov) const
{
	return 2.0f * PI * Fase(TiempoMov);
}

float APlataforma::OndaTriangular(float FaseActual)
{
	return 4.0f * FMath::Abs(FMath::Fmod(FaseActual + 0.75f, 1.0f) - 0.5f) - 1.0f;
}

// Called every frame
void APlataforma::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Avanza el ciclo pausa -> movimiento -> pausa ... sin perder el tiempo sobrante al cambiar de fase
	float Restante = DeltaTime;
	bool bSeMovio = false;

	for (int32 Intentos = 0; Restante > 0.0f && Intentos < 4; Intentos++)
	{
		const float Duracion = FMath::Max(bEnMovimiento ? DuracionMovimiento : DuracionPausa, KINDA_SMALL_NUMBER);
		const float Paso = FMath::Min(Restante, Duracion - TiempoEnFase);

		TiempoEnFase += Paso;
		Restante -= Paso;

		if (bEnMovimiento)
		{
			TiempoMovimiento += Paso;
			bSeMovio = true;
		}

		if (TiempoEnFase >= Duracion)
		{
			bEnMovimiento = !bEnMovimiento;
			TiempoEnFase = 0.0f;
		}
	}

	// Durante la pausa la plataforma no se toca: queda quieta donde termino
	if (bSeMovio)
	{
		SetActorLocation(PosicionInicial + CalcularDesplazamiento(TiempoMovimiento));
	}
}
