// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "CharacterBase.h"
#include "BuildBase.h"
#include "Kismet/GameplayStatics.h"

AGameManager::AGameManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGameManager::BeginPlay()
{
	Super::BeginPlay();

	ScanWorld();

	UE_LOG(LogTemp, Log, TEXT("GameManager iniciado. Personajes: %d | Edificios: %d"),
		AllCharacters.Num(), AllBuildings.Num());
}

void AGameManager::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	ElapsedSeconds += DeltaSeconds;

	if (IsObjectiveCompleted())
	{
		UE_LOG(LogTemp, Log, TEXT("Objetivo alcanzado: %d / %d unidades."),
			AllCharacters.Num(), TargetUnits);
	}
}

void AGameManager::RegisterCharacter(ACharacterBase* NewChar)
{
	if (!IsValid(NewChar)) return;

	AllCharacters.AddUnique(NewChar);

	UE_LOG(LogTemp, Log, TEXT("Registrado personaje (%s). Total: %d"),
		*NewChar->GetName(), AllCharacters.Num());
}

void AGameManager::RegisterBuilding(ABuildBase* NewBuild)
{
	if (!IsValid(NewBuild)) return;

	AllBuildings.AddUnique(NewBuild);

	UE_LOG(LogTemp, Log, TEXT("Registrado edificio (%s). Total: %d"),
		*NewBuild->GetName(), AllBuildings.Num());
}

void AGameManager::ScanWorld()
{
	AllCharacters.Reset();
	AllBuildings.Reset();

	TArray<AActor*> Found;

	// Buscar personajes
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACharacterBase::StaticClass(), Found);
	for (AActor* A : Found)
	{
		if (ACharacterBase* C = Cast<ACharacterBase>(A))
		{
			AllCharacters.Add(C);
		}
	}
	Found.Reset();

	// Buscar edificios
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABuildBase::StaticClass(), Found);
	for (AActor* A : Found)
	{
		if (ABuildBase* B = Cast<ABuildBase>(A))
		{
			AllBuildings.Add(B);
		}
	}
}