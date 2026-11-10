// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryCharacter.h"
#include "InventoryActor.h"
#include "InventoryComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

// Segundos que tarda en poder recoger de nuevo despues de soltar un objeto
#define ESPERA_RECOGER 1.0f

// Sets default values
AInventoryCharacter::AInventoryCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	UltimoSoltado = -ESPERA_RECOGER;

	MyInventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("MyInventory"));

	// Camara en primera persona, a la altura de los ojos
	Camara = CreateDefaultSubobject<UCameraComponent>(TEXT("Camara"));
	Camara->SetupAttachment(GetCapsuleComponent());
	Camara->SetRelativeLocation(FVector(0.0f, 0.0f, 64.0f));
	Camara->bUsePawnControlRotation = true;
	bUseControllerRotationYaw = true;
}

// Called to bind functionality to input
void AInventoryCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Los nombres coinciden con Config/DefaultInput.ini
	PlayerInputComponent->BindAxis("MoveForward", this, &AInventoryCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AInventoryCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("DropItem", IE_Pressed, this, &AInventoryCharacter::DropItem);
}

void AInventoryCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AInventoryCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AInventoryCharacter::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	// Si choca con un objeto del inventario, lo recoge
	AInventoryActor* InventoryItem = Cast<AInventoryActor>(Other);
	if (InventoryItem != nullptr && GetWorld() != nullptr &&
		GetWorld()->GetTimeSeconds() - UltimoSoltado >= ESPERA_RECOGER)
	{
		TakeItem(InventoryItem);
	}
}

void AInventoryCharacter::TakeItem(AInventoryActor* InventoryItem)
{
	if (InventoryItem == nullptr)
	{
		return;
	}

	if (MyInventory->AddToInventory(InventoryItem) != INDEX_NONE)
	{
		InventoryItem->PickUp();
		MostrarInventario(FString::Printf(TEXT("Recogiste: %s"), *InventoryItem->NombreObjeto));
	}
}

void AInventoryCharacter::DropItem()
{
	if (MyInventory->CurrentInventory.Num() == 0)
	{
		MostrarInventario(TEXT("El inventario esta vacio"));
		return;
	}

	AInventoryActor* Item = MyInventory->CurrentInventory.Last();
	MyInventory->RemoveFromInventory(Item);

	// Lo coloca delante del personaje, fuera de su capsula
	FVector ItemOrigin;
	FVector ItemBounds;
	Item->GetActorBounds(false, ItemOrigin, ItemBounds);
	const float Distancia = GetCapsuleComponent()->GetScaledCapsuleRadius() + ItemBounds.GetMax() + 20.0f;
	const FVector Posicion = GetActorLocation() + GetActorForwardVector() * Distancia;

	Item->PutDown(FTransform(GetActorRotation(), Posicion));
	UltimoSoltado = GetWorld()->GetTimeSeconds();
	MostrarInventario(FString::Printf(TEXT("Soltaste: %s"), *Item->NombreObjeto));
}

void AInventoryCharacter::MostrarInventario(const FString& Mensaje)
{
	UE_LOG(LogTemp, Log, TEXT("%s (en inventario: %d)"), *Mensaje, MyInventory->CurrentInventory.Num());
	if (GEngine != nullptr)
	{
		// Misma clave (1) para que el mensaje se reemplace y no se apilen
		GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Green,
			FString::Printf(TEXT("%s | Inventario: %d objeto(s)"), *Mensaje, MyInventory->CurrentInventory.Num()));
	}
}
