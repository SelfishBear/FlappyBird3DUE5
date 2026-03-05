// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FP_MainGameMode.generated.h"

class AFP_MapCollector;
class UFP_MapOptimizer;
class UFP_LandscapeMover;
class UFP_TubeSpawner;

UCLASS()
class FLAPPYBIRD_API AFP_MainGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AFP_MainGameMode();
	
	UPROPERTY(EditDefaultsOnly, Category="Spawner")
	TSubclassOf<UFP_TubeSpawner> TubeSpawnerClass;
	
	UPROPERTY(EditDefaultsOnly, Category="Spawner")
	TSubclassOf<UFP_LandscapeMover> LandscapeMoverClass;
	
	UPROPERTY(EditDefaultsOnly, Category="Optimization")
	TSubclassOf<UFP_MapOptimizer> MapOptimizerClass;

protected:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;
	
private:
	void GetLandscapeActor();
	
	void InitSpawner();
	
	void InitLandscapeMover();
	
	void InitLandscapeOptimizer();
	
	UPROPERTY()
	AFP_MapCollector* MapCollector;
	
	UPROPERTY()
	TArray<AActor*> LandscapeActors;
	
	UPROPERTY()
	UFP_TubeSpawner* TubeSpawner;
	
	UPROPERTY()
	UFP_LandscapeMover* LandscapeMover;
	
	UPROPERTY()
	UFP_MapOptimizer* MapOptimizer;
};
