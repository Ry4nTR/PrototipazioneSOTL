// Fill out your copyright notice in the Description page of Project Settings.


#include "RubikWorldRotator.h"

ARubikWorldRotator::ARubikWorldRotator()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ARubikWorldRotator::BeginPlay()
{
    Super::BeginPlay();
}

void ARubikWorldRotator::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!bIsRotating || RotationDuration <= 0.f) return;

    RotationTimeElapsed += DeltaTime;
    float Alpha = FMath::Clamp(RotationTimeElapsed / RotationDuration, 0.f, 1.f);

    for (int32 i = 0; i < ComponentsToRotate.Num(); ++i)
    {
        if (USceneComponent* Comp = ComponentsToRotate[i])
        {
            const FRotator& StartRot = StartRotations[i];
            const FRotator& EndRot = TargetRotations[i];
            FRotator NewRot = FMath::Lerp(StartRot, EndRot, Alpha);
            Comp->SetWorldRotation(NewRot);
        }
    }

    // Done?
    if (Alpha >= 1.f)
    {
        bIsRotating = false;
        ComponentsToRotate.Empty();
        StartRotations.Empty();
        TargetRotations.Empty();
    }
}

void ARubikWorldRotator::AddRotationTarget(USceneComponent* Component, float AngleDelta)
{
    if (!Component) return;

    FRotator StartRot = Component->GetComponentRotation();
    FRotator TargetRot = StartRot;
    TargetRot.Yaw += AngleDelta;

    ComponentsToRotate.Add(Component);
    StartRotations.Add(StartRot);
    TargetRotations.Add(TargetRot);
}

void ARubikWorldRotator::StartRotation(float Duration)
{
    if (ComponentsToRotate.Num() == 0) return;

    RotationTimeElapsed = 0.0f;
    RotationDuration = Duration;
    bIsRotating = true;
}
