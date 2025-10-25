// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UENUM(BlueprintType)
enum class ECharacterType : uint8
{
	CT_Villager UMETA(DisplayName = "Villager"),
	CT_Soldier UMETA(DisplayName = "Soldier")
};

UCLASS()
class WAR_AND_DEATH_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	ECharacterType CharacterType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Stats")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character Stats")
	float Strength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
	float speed;

	UFUNCTION(BlueprintCallable, Category = "Character")
	void InitializeCharacter(ECharacterType Type);
};
