// Fill out your copyright notice in the Description page of Project Settings.


#include "Utils/FP_LandscapeMover.h"

void UFP_LandscapeMover::Move(float DeltaTime, TArray<AActor*> LandscapeActors)
{
	for (AActor* LandscapeActor : LandscapeActors)
	{
		FVector NewLocation = LandscapeActor->GetActorLocation();
		NewLocation.X += MovementSpeed * DeltaTime; 
		LandscapeActor->SetActorLocation(NewLocation);
	}
}
