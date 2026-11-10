// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstaculo.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInstanceDynamic.h"

// Sets default values
AObstaculo::AObstaculo()
{
	PrimaryActorTick.bCanEverTick = false;

	NombreObstaculo = TEXT("Obstaculo");
	Familia = TEXT("Generica");
	Color = FLinearColor::White;

	// La malla cuelga de una raiz para poder girarla sin cambiar la orientacion del actor
	Raiz = CreateDefaultSubobject<USceneComponent>(TEXT("Raiz"));
	RootComponent = Raiz;

	Malla = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla"));
	Malla->SetupAttachment(Raiz);
	Malla->SetMobility(EComponentMobility::Movable);
}

void AObstaculo::ConfigurarMalla(EFormaObstaculo Forma, const FVector& Escala, const FLinearColor& NuevoColor, const FRotator& Giro)
{
	const TCHAR* Ruta = TEXT("/Engine/BasicShapes/Cube.Cube");
	switch (Forma)
	{
	case EFormaObstaculo::Esfera:   Ruta = TEXT("/Engine/BasicShapes/Sphere.Sphere"); break;
	case EFormaObstaculo::Cilindro: Ruta = TEXT("/Engine/BasicShapes/Cylinder.Cylinder"); break;
	case EFormaObstaculo::Cono:     Ruta = TEXT("/Engine/BasicShapes/Cone.Cone"); break;
	default: break;
	}

	// Solo se puede usar dentro de un constructor: las subclases la llaman desde el suyo
	ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(Ruta);
	if (MallaAsset.Succeeded())
	{
		Malla->SetStaticMesh(MallaAsset.Object);
	}
	Malla->SetRelativeScale3D(Escala);
	Malla->SetRelativeRotation(Giro);
	Color = NuevoColor;
}

// Called when the game starts or when spawned
void AObstaculo::BeginPlay()
{
	Super::BeginPlay();

	UMaterialInstanceDynamic* Material = Malla->CreateAndSetMaterialInstanceDynamic(0);
	if (Material != nullptr)
	{
		Material->SetVectorParameterValue(TEXT("Color"), Color);
	}
}

FString AObstaculo::Describir() const
{
	return FString::Printf(TEXT("%s [%s - %s]"), *NombreObstaculo, *GetTipo(), *Familia);
}
