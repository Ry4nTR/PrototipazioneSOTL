// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RubikWorldRotator.generated.h"

UCLASS()
class YOURGAME_API ARubikWorldRotator : public AActor
{
    GENERATED_BODY()

public:
    ARubikWorldRotator();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Call this to add a component to rotate
    UFUNCTION(BlueprintCallable)
    void AddRotationTarget(USceneComponent* Component, float AngleDelta);

    // Starts the rotation
    UFUNCTION(BlueprintCallable)
    void StartRotation(float Duration = 1.0f);

protected:
    virtual void BeginPlay() override;

private:
    TArray<USceneComponent*> ComponentsToRotate;
    TArray<FRotator> StartRotations;
    TArray<FRotator> TargetRotations;

    bool bIsRotating = false;
    float RotationTimeElapsed = 0.0f;
    float RotationDuration = 1.0f;
};
