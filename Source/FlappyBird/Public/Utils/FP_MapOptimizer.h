// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FP_MapOptimizer.generated.h"

/**
 * 
 * 
 */
UCLASS(Blueprintable)
class FLAPPYBIRD_API UFP_MapOptimizer : public UObject
{
	GENERATED_BODY()
	
public:
	void SwitchLandscape(const FVector& To, AActor* LandscapeActor) const;
	
	void StartLoopSwitching();
};
