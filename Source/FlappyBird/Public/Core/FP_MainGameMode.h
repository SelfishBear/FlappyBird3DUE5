// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FP_MainGameMode.generated.h"

class UFP_TubeSpawner;

UCLASS()
class FLAPPYBIRD_API AFP_MainGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AFP_MainGameMode();
	
	UPROPERTY(EditDefaultsOnly, Category="Spawner")
	TSubclassOf<UFP_TubeSpawner> TubeSpawnerClass;
	
protected:
	virtual void BeginPlay() override;
	
private:
	void InitSpawner();
	
	UPROPERTY()
	UFP_TubeSpawner* TubeSpawner;
};
