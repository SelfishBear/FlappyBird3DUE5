// Fill out your copyright notice in the Description page of Project Settings.


#include "FlappyBird/Public/Core/FP_MainGameMode.h"
#include "FlappyBird/Public/Character/FP_BirdCharacter.h"
#include "FlappyBird/Public/Objects/FP_TubeSpawner.h"

AFP_MainGameMode::AFP_MainGameMode()
{
	DefaultPawnClass = AFP_BirdCharacter::StaticClass();
}

void AFP_MainGameMode::BeginPlay()
{
	Super::BeginPlay();

	InitSpawner();
}

void AFP_MainGameMode::InitSpawner()
{
	TubeSpawner = NewObject<UFP_TubeSpawner>(this, TubeSpawnerClass);
	TubeSpawner->StartSpawning();
}
