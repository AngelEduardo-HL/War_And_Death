
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "MainBuild.generated.h"

class ACharacterBase;

UCLASS()
class WAR_AND_DEATH_API AMainBuild : public AActor
{
	GENERATED_BODY()

public:
	AMainBuild();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* BuildMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<ACharacterBase> CharacterToSpawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	USceneComponent* SpawnPoint;

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void CreateVillager();
};
