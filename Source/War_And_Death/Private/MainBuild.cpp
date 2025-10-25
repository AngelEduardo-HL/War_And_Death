// Fill out your copyright notice in the Description page of Project Settings.


#include "MainBuild.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMainBuild::AMainBuild()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BuildMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildingMesh"));
	RootComponent = BuildMesh;

	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnPoint"));
	SpawnPoint->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMainBuild::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainBuild::CreateVillager()
{
	if (!CharacterToSpawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("No se asigno una clase de personaje para crear"))
			return;
	}

	FVector SpawnLocation = SpawnPoint->GetComponentLocation();
	FRotator SpawnRotation = SpawnPoint->GetComponentRotation();

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride
		= ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	ACharacterBase* NewCharacter = GetWorld()->SpawnActor<ACharacterBase>(
		CharacterToSpawn, SpawnLocation, SpawnRotation);

	if (NewCharacter)
	{
		NewCharacter->InitializeCharacter(ECharacterType::CT_Villager);
		UE_LOG(LogTemp, Warning, TEXT("Aldeano creado en la posicion: %s"), *SpawnLocation.ToString())
	}
}
