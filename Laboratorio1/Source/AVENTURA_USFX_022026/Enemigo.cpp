// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

// Sets default values
AEnemigo::AEnemigo()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Raiz = CreateDefaultSubobject<USceneComponent>(TEXT("Raiz"));
	RootComponent = Raiz;

	MallaEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEnemigo"));
	MallaEnemigo->SetupAttachment(Raiz);

	// Malla incluida en el motor (no depende del Content del proyecto).
	// La punta del cono apunta a +Z, se gira -90 grados de pitch para que mire al frente (+X).
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(TEXT("/Engine/BasicShapes/Cone.Cone"));
	if (MallaAsset.Succeeded())
	{
		MallaEnemigo->SetStaticMesh(MallaAsset.Object);
	}
	MallaEnemigo->SetRelativeRotation(FRotator(-90.0f, 0.0f, 0.0f));
	MallaEnemigo->SetRelativeScale3D(FVector(1.5f, 1.5f, 2.0f));

	Velocidad = 400.0f;
	VelocidadGiro = 120.0f;
	DistanciaLlegada = 50.0f;
	TiempoEspera = 0.5f;

	CentroZona = FVector::ZeroVector;
	ExtensionZona = FVector(1000.0f, 1000.0f, 500.0f);
	Destino = FVector::ZeroVector;
	TiempoEsperaRestante = 0.0f;
	bZonaDefinida = false;
}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();

	// Si nadie definio la zona, se mueve alrededor del punto donde aparecio
	if (!bZonaDefinida)
	{
		CentroZona = GetActorLocation();
		ElegirNuevoDestino();
	}
}

void AEnemigo::DefinirZonaMovimiento(const FVector& NuevoCentro, const FVector& NuevaExtension)
{
	CentroZona = NuevoCentro;
	ExtensionZona = NuevaExtension;
	bZonaDefinida = true;
	ElegirNuevoDestino();
}

void AEnemigo::SetVelocidad(float NuevaVelocidad)
{
	Velocidad = NuevaVelocidad;
}

void AEnemigo::ElegirNuevoDestino()
{
	Destino = CentroZona + FVector(
		FMath::RandRange(-ExtensionZona.X, ExtensionZona.X),
		FMath::RandRange(-ExtensionZona.Y, ExtensionZona.Y),
		FMath::RandRange(-ExtensionZona.Z, ExtensionZona.Z));
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Esperando en el destino anterior
	if (TiempoEsperaRestante > 0.0f)
	{
		TiempoEsperaRestante -= DeltaTime;
		return;
	}

	const FVector Posicion = GetActorLocation();
	const FVector HaciaDestino = Destino - Posicion;
	const float Distancia = HaciaDestino.Size();

	// Llego: espera un momento y elige otro lugar del escenario
	if (Distancia <= DistanciaLlegada)
	{
		TiempoEsperaRestante = TiempoEspera;
		ElegirNuevoDestino();
		return;
	}

	const FVector Direccion = HaciaDestino / Distancia;

	// Gira la nave poco a poco hacia donde va
	SetActorRotation(FMath::RInterpConstantTo(GetActorRotation(), Direccion.Rotation(), DeltaTime, VelocidadGiro));

	// Avanza sin pasarse del destino
	const float Paso = FMath::Min(Velocidad * DeltaTime, Distancia);
	SetActorLocation(Posicion + Direccion * Paso);
}

