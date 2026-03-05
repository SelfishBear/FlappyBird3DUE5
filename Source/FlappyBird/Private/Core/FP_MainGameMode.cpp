// Fill out your copyright notice in the Description page of Project Settings.


#include "FlappyBird/Public/Core/FP_MainGameMode.h"
#include "FlappyBird/Public/Character/FP_BirdCharacter.h"
#include "FlappyBird/Public/Objects/FP_TubeSpawner.h"
#include "Kismet/GameplayStatics.h"
#include "Utils/FP_LandscapeMover.h"
#include "Utils/FP_MapCollector.h"
#include "Utils/FP_MapOptimizer.h"

AFP_MainGameMode::AFP_MainGameMode()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultPawnClass = AFP_BirdCharacter::StaticClass();
}

void AFP_MainGameMode::BeginPlay()
{
	Super::BeginPlay();

	InitSpawner();
	GetLandscapeActor();

	InitLandscapeMover();
	InitLandscapeOptimizer();
}

void AFP_MainGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UE_LOG(LogTemp, Warning, TEXT("FP_MainGameMode::Tick"));
	if (LandscapeMover && MapCollector->MapParts.Num() > 0)
	{
		LandscapeMover->Move(DeltaSeconds, MapCollector->MapParts);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("LandscapeMover is not initialized."));
	}
}

void AFP_MainGameMode::GetLandscapeActor()
{
	MapCollector = Cast<AFP_MapCollector>(UGameplayStatics::GetActorOfClass(GetWorld(), AFP_MapCollector::StaticClass()));
}

void AFP_MainGameMode::InitSpawner()
{
	TubeSpawner = NewObject<UFP_TubeSpawner>(this, TubeSpawnerClass);
	TubeSpawner->StartSpawning();
}

void AFP_MainGameMode::InitLandscapeMover()
{
	LandscapeMover = NewObject<UFP_LandscapeMover>(this, LandscapeMoverClass);
}

void AFP_MainGameMode::InitLandscapeOptimizer()
{
	MapOptimizer = NewObject<UFP_MapOptimizer>(this, MapOptimizerClass);
}
