
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "BuildBase.generated.h"


class ACharacterBase;

UENUM(BlueprintType)
enum class EBuildRole : uint8
{
	Forge     UMETA(DisplayName = "Forge"),
	Farm      UMETA(DisplayName = "Farm"),
	Barracks  UMETA(DisplayName = "Barracks")
};

UCLASS()
class WAR_AND_DEATH_API ABuildBase : public AActor
{
	GENERATED_BODY()

public:
	ABuildBase();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* BuildMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USceneComponent* SpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Build")
	EBuildRole BuildRole = EBuildRole::Forge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<ACharacterBase> VillagerClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<ACharacterBase> SoldierClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effects")
	float SpeedMultiplier = 1.25f;

	UFUNCTION(BlueprintCallable, Category = "Build")
	void CreateUnit();

	UFUNCTION(BlueprintCallable, Category = "Build")
	void ApplyBuildingEffect(ACharacterBase* Target);
};
