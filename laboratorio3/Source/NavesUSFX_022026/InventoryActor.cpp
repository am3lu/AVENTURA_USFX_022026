// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryActor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

AInventoryActor::AInventoryActor()
{
	PrimaryActorTick.bCanEverTick = false;

	NombreObjeto = TEXT("Objeto");
	bSimularFisica = true;

	// AStaticMeshActor nace como Static; para moverlo y simular fisica debe ser Movable
	UStaticMeshComponent* Malla = GetStaticMeshComponent();
	Malla->SetMobility(EComponentMobility::Movable);
	Malla->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);

	// Malla incluida en el motor (no depende del Content del proyecto)
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (MallaAsset.Succeeded())
	{
		Malla->SetStaticMesh(MallaAsset.Object);
	}
	Malla->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
}

void AInventoryActor::BeginPlay()
{
	Super::BeginPlay();

	GetStaticMeshComponent()->SetSimulatePhysics(bSimularFisica);
}

void AInventoryActor::PickUp()
{
	// Sin fisica no sigue cayendo oculto dentro del inventario
	GetStaticMeshComponent()->SetSimulatePhysics(false);
	SetActorTickEnabled(false);
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void AInventoryActor::PutDown(FTransform TargetLocation)
{
	SetActorEnableCollision(true);
	SetActorHiddenInGame(false);
	SetActorTickEnabled(true);
	SetActorLocationAndRotation(TargetLocation.GetLocation(), TargetLocation.GetRotation(), false, nullptr, ETeleportType::TeleportPhysics);
	GetStaticMeshComponent()->SetSimulatePhysics(bSimularFisica);
}
