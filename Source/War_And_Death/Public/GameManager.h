// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterBase.h"
#include "BuildBase.h"
#include "GameManager.generated.h"

class ACharacterBase;
class ABuildBase;

UCLASS()
class WAR_AND_DEATH_API AGameManager : public AActor
{
	GENERATED_BODY()

public:
	AGameManager();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
	TArray<ACharacterBase*> AllCharacters;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
	TArray<ABuildBase*> AllBuildings;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Game")
	float ElapsedSeconds = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Objective")
	int32 TargetUnits = 5;

	UFUNCTION(BlueprintCallable, Category = "Game")
	void RegisterCharacter(ACharacterBase* NewChar);

	UFUNCTION(BlueprintCallable, Category = "Game")
	void RegisterBuilding(ABuildBase* NewBuild);

	UFUNCTION(BlueprintCallable, Category = "Game")
	void ScanWorld();

	UFUNCTION(BlueprintPure, Category = "Objective")
	bool IsObjectiveCompleted() const { return AllCharacters.Num() >= TargetUnits; }

	UFUNCTION(BlueprintPure, Category = "Game")
	float GetElapsedTimeSeconds() const { return ElapsedSeconds; }
};