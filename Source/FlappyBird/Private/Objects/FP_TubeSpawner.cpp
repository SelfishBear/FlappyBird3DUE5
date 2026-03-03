// Fill out your copyright notice in the Description page of Project Settings.


#include "FlappyBird/Public/Objects/FP_TubeSpawner.h"

void UFP_TubeSpawner::StartSpawning()
{
	GetWorld()->GetTimerManager().SetTimer(FTubeTimerHandle, this, &UFP_TubeSpawner::SpawnTube, SpawnInterval, true);
}

void UFP_TubeSpawner::SpawnTube() const
{
	GetWorld()->SpawnActor<AActor>(TubeClass, FVector(XSpawnOffset, 0.0f, FMath::RandRange(MinHeightRange, MaxHeightRange)), FRotator::ZeroRotator);
}
