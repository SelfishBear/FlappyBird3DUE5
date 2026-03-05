// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FP_LandscapeMover.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FLAPPYBIRD_API UFP_LandscapeMover : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Movement")
	float MovementSpeed = 100.0f;
	
	void Move(float DeltaTime, TArray<AActor*> LandscapeActors);
};
