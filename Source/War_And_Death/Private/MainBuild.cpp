// Fill out your copyright notice in the Description page of Project Settings.


#include "MainBuild.h"
#include "CharacterBase.h"
#include "Engine/World.h"

AMainBuild::AMainBuild()
{
	PrimaryActorTick.bCanEverTick = false;

	BuildMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildMesh"));
	RootComponent = BuildMesh;

	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnPoint"));
	SpawnPoint->SetupAttachment(RootComponent);
}

void AMainBuild::BeginPlay()
{
	Super::BeginPlay();
}

void AMainBuild::CreateVillager()
{
	if (!CharacterToSpawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("No se asignó una clase de personaje para crear"));
		return;
	}

	const FVector SpawnLocation = SpawnPoint->GetComponentLocation();
	const FRotator SpawnRotation = SpawnPoint->GetComponentRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	ACharacterBase* NewCharacter = GetWorld()->SpawnActor<ACharacterBase>(
		CharacterToSpawn, SpawnLocation, SpawnRotation, SpawnParams);

	if (NewCharacter)
	{
		NewCharacter->InitializeCharacter(ECharacterType::CT_Villager);
		UE_LOG(LogTemp, Warning, TEXT("Aldeano creado en la posicion: %s"), *SpawnLocation.ToString());
	}
}
