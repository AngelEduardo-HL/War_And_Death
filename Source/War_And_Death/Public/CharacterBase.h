// CharacterBase.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

// TIPOS DE UNIDAD
UENUM(BlueprintType)
enum class ECharacterType : uint8
{
	CT_Villager UMETA(DisplayName="Villager"),
	CT_Soldier  UMETA(DisplayName="Soldier")
};

UCLASS()
class WAR_AND_DEATH_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ACharacterBase();

	// Estado básico
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	float Health = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	float Strength = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stats")
	float Speed = 300.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Type")
	ECharacterType CharacterType = ECharacterType::CT_Villager;

	// Inicializa stats según el tipo
	UFUNCTION(BlueprintCallable, Category="Init")
	void InitializeCharacter(ECharacterType Type);

protected:
	virtual void BeginPlay() override;
};
