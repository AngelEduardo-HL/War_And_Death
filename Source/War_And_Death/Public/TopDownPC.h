// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TopDownPC.generated.h"

class ACharacter;

UCLASS()
class WAR_AND_DEATH_API ATopDownPC : public APlayerController
{
	GENERATED_BODY()

public:
	ATopDownPC();

protected:
	virtual void SetupInputComponent() override;

private:
	UPROPERTY()
	TArray<TWeakObjectPtr<ACharacter>> SelectedUnits;

	void OnLMBPressed();

	void ToggleSelect(ACharacter* Unit);
	void MoveSelectionTo(const FVector& WorldPoint);
};
