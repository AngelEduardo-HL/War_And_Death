// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterBase.h"
#include "MainBuild.generated.h"

UCLASS()
class WAR_AND_DEATH_API AMainBuild : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainBuild();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Mesh del edificio
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* BuildMesh;

	// Reference to the character to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<ACharacterBase> CharacterToSpawn;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	USceneComponent* SpawnPoint;

	// Crea aldeanos (función expuesta a Blueprint)
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void CreateVillager();
};
