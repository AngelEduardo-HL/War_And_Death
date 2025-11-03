// CharacterBase.cpp
#include "CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

	// Asegurar velocidad en el MovementComponent si existe
	if (auto* Move = GetCharacterMovement())
	{
		Move->MaxWalkSpeed = Speed;
	}
}

void ACharacterBase::InitializeCharacter(ECharacterType Type)
{
	CharacterType = Type;

	switch (CharacterType)
	{
	case ECharacterType::CT_Villager:
		Health = 80.f;
		Strength = 5.f;
		Speed = 250.f;
		UE_LOG(LogTemp, Warning, TEXT("Unidad Creada: Aldeano"));
		break;

	case ECharacterType::CT_Soldier:
		Health = 150.f;
		Strength = 20.f;
		Speed = 350.f;
		UE_LOG(LogTemp, Warning, TEXT("Unidad Creada: Soldado"));
		break;
	}

	// Actualizar velocidad si ya hay MovementComponent
	if (auto* Move = GetCharacterMovement())
	{
		Move->MaxWalkSpeed = Speed;
	}
}
