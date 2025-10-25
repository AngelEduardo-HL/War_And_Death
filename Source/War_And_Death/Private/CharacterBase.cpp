// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Health = 100.0f;
	Strength = 10.0f;
	speed = 300.0f;

}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharacterBase::InitializeCharacter(ECharacterType Type)
{
	CharacterType = Type;

	switch (CharacterType)
	{
		case ECharacterType::CT_Villager:
			Health = 80.0f;
			Strength = 5.0f;
			speed = 250.0f;
			UE_LOG(LogTemp, Warning, TEXT("Unidad Creada: Aldeano"))
			break;

		case ECharacterType::CT_Soldier:
			Health = 150.0f;
			Strength = 20.0f;
			speed = 350.0f;
			UE_LOG(LogTemp, Warning, TEXT("Unidad Creada: Soldado"))
			break;
	}
}

