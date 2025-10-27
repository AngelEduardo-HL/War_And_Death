


#include "CharacterBase.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
	Health = 100.0f;
	Strength = 10.0f;
	speed = 300.0f;
}

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
		UE_LOG(LogTemp, Warning, TEXT("Unidad Creada: Aldeano"));
		break;

	case ECharacterType::CT_Soldier:
		Health = 150.0f;
		Strength = 20.0f;
		speed = 350.0f;
		UE_LOG(LogTemp, Warning, TEXT("Unidad Creada: Soldado"));
		break;
	}
}
