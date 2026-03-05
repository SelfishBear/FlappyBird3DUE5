// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FP_MapCollector.generated.h"

UCLASS()
class FLAPPYBIRD_API AFP_MapCollector : public AActor
{
	GENERATED_BODY()

public:
	AFP_MapCollector();
	
	UPROPERTY(EditAnywhere, Category="Map Parts")
	TArray<AActor*> MapParts;
};
