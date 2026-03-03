// Fill out your copyright notice in the Description page of Project Settings.


#include "FlappyBird/Public/Objects/FP_Tube.h"

AFP_Tube::AFP_Tube()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFP_Tube::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFP_Tube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move(DeltaTime);
}

void AFP_Tube::Move(float DeltaTime)
{
	FVector NewLocation = GetActorLocation();
	NewLocation.X -= MovementSpeed * DeltaTime;
	SetActorLocation(NewLocation, true);
}

