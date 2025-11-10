// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDownPC.h"
#include "GameFramework/Character.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

ATopDownPC::ATopDownPC()
{
    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;
}

void ATopDownPC::SetupInputComponent()
{
    Super::SetupInputComponent();
    // Action Mapping "LMB"
    InputComponent->BindAction("LMB", IE_Pressed, this, &ATopDownPC::OnLMBPressed);
}

void ATopDownPC::OnLMBPressed()
{
    FHitResult Hit;
    GetHitResultUnderCursor(ECC_Visibility, false, Hit);

    if (AActor* HitActor = Hit.GetActor())
    {
        // Click sobre una unidad del jugador
        if (ACharacter* HitChar = Cast<ACharacter>(HitActor))
        {
            // Filtra por tag
            if (HitChar->ActorHasTag(FName("PlayerUnit")))
            {
                ToggleSelect(HitChar);
                return;
            }
        }
    }

    if (Hit.bBlockingHit)
    {
        MoveSelectionTo(Hit.ImpactPoint);
    }
}

void ATopDownPC::ToggleSelect(ACharacter* Unit)
{
    if (!Unit) return;

    if (SelectedUnits.Contains(Unit))
    {
        SelectedUnits.Remove(Unit);
        // Hook
    }
    else
    {
        SelectedUnits.Add(Unit);
        // Hook visual
    }
}

void ATopDownPC::MoveSelectionTo(const FVector& WorldPoint)
{
    for (TWeakObjectPtr<ACharacter>& WeakChar : SelectedUnits)
    {
        if (ACharacter* Unit = WeakChar.Get())
        {
            UAIBlueprintHelperLibrary::SimpleMoveToLocation(Unit->GetController(), WorldPoint);
        }
    }
}
