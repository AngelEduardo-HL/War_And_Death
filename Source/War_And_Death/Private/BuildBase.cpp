


#include "BuildBase.h"
#include "CharacterBase.h"
#include "Engine/World.h"

ABuildBase::ABuildBase()
{
	PrimaryActorTick.bCanEverTick = false;

	BuildMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildMesh"));
	RootComponent = BuildMesh;

	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnPoint"));
	SpawnPoint->SetupAttachment(RootComponent);
}

void ABuildBase::BeginPlay()
{
	Super::BeginPlay();
}

void ABuildBase::CreateUnit()
{
	TSubclassOf<ACharacterBase> ClassToSpawn = nullptr;
	ECharacterType Type = ECharacterType::CT_Villager;

	switch (BuildRole)
	{
	case EBuildRole::Forge:
		ClassToSpawn = SoldierClass;
		Type = ECharacterType::CT_Soldier;
		break;
	case EBuildRole::Barracks:
		ClassToSpawn = SoldierClass ? SoldierClass : VillagerClass;
		Type = SoldierClass ? ECharacterType::CT_Soldier : ECharacterType::CT_Villager;
		break;
	case EBuildRole::Farm:
		UE_LOG(LogTemp, Warning, TEXT("Farm: no crea unidades. Usa ApplyBuildingEffect()"));
		return;
	}

	if (!ClassToSpawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildBase: Clase de unidad no asignada"));
		return;
	}

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	ACharacterBase* Unit = GetWorld()->SpawnActor<ACharacterBase>(
		ClassToSpawn,
		SpawnPoint->GetComponentLocation(),
		SpawnPoint->GetComponentRotation(),
		Params);

	if (Unit)
	{
		Unit->InitializeCharacter(Type);
		UE_LOG(LogTemp, Warning, TEXT("Unidad creada por BuildBase"));
	}
}

void ABuildBase::ApplyBuildingEffect(ACharacterBase* Target)
{
	if (!Target)
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildBase: Target nulo en ApplyBuildingEffect"));
		return;
	}

	if (BuildRole == EBuildRole::Farm)
	{
		Target->speed *= SpeedMultiplier;
		UE_LOG(LogTemp, Warning, TEXT("Efecto de Farm aplicado: Velocidad aumentada x%.2f"), SpeedMultiplier);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("BuildBase: Este edificio no aplica efecto"));
	}
}
