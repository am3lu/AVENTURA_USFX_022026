// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstaculoPeligroso.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/DamageType.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"

AObstaculoPeligroso::AObstaculoPeligroso()
{
	PrimaryActorTick.bCanEverTick = true;

	Danio = 10.0f;
	FuerzaEmpuje = 300.0f;
	VelocidadGiro = 0.0f;

	EscalaBase = FVector(1.0f, 1.0f, 1.0f);
	TiempoPulso = 0.0f;

	// Se atraviesa: no bloquea, solo avisa cuando alguien lo toca
	Malla->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	Malla->SetGenerateOverlapEvents(true);
}

void AObstaculoPeligroso::BeginPlay()
{
	Super::BeginPlay();

	EscalaBase = Malla->GetRelativeScale3D();
	Malla->OnComponentBeginOverlap.AddDynamic(this, &AObstaculoPeligroso::AlSolapar);
}

void AObstaculoPeligroso::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Late (crece y se encoge) para que se note que es peligroso
	TiempoPulso += DeltaTime;
	Malla->SetRelativeScale3D(EscalaBase * (1.0f + 0.08f * FMath::Sin(TiempoPulso * 4.0f)));

	if (VelocidadGiro != 0.0f)
	{
		AddActorLocalRotation(FRotator(0.0f, VelocidadGiro * DeltaTime, 0.0f));
	}
}

void AObstaculoPeligroso::AlSolapar(UPrimitiveComponent* ComponenteSolapado, AActor* OtroActor, UPrimitiveComponent* OtroComponente,
	int32 OtroIndiceCuerpo, bool bDesdeBarrido, const FHitResult& ResultadoBarrido)
{
	// Solo castiga a pawns (el jugador), no a otros obstaculos
	if (OtroActor == nullptr || OtroActor == this || Cast<APawn>(OtroActor) == nullptr)
	{
		return;
	}

	FVector Direccion = OtroActor->GetActorLocation() - GetActorLocation();
	Direccion.Z = 0.0f;
	OtroActor->AddActorWorldOffset(Direccion.GetSafeNormal() * FuerzaEmpuje, true);

	UGameplayStatics::ApplyDamage(OtroActor, Danio, nullptr, this, UDamageType::StaticClass());

	if (GEngine != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(10, 2.0f, FColor::Red, FString::Printf(TEXT("Cuidado! %s (%s): -%.0f"), *NombreObstaculo, *Familia, Danio));
	}
}
