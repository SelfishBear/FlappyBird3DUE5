// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FP_TubeSpawner.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FLAPPYBIRD_API UFP_TubeSpawner : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "Tube Spawner")
	TSubclassOf<AActor> TubeClass;
	
	UPROPERTY(EditDefaultsOnly, Category = "Tube Spawner")
	float SpawnInterval = 2.0f;
	
	UPROPERTY(EditDefaultsOnly, Category = "Tube Spawner")
	float MaxHeightRange = 200.0f;
	
	UPROPERTY(EditDefaultsOnly, Category = "Tube Spawner")
	float MinHeightRange = -200.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Tube Spawner")
	float XSpawnOffset = 150.0f;
	
	FTimerHandle FTubeTimerHandle;
	
	void StartSpawning();
	
	void SpawnTube() const;
};
