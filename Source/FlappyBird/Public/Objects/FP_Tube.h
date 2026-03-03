// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FP_Tube.generated.h"

UCLASS()
class FLAPPYBIRD_API AFP_Tube : public AActor
{
	GENERATED_BODY()

public:
	AFP_Tube();

	UPROPERTY(EditDefaultsOnly, Category="Movement")
	float MovementSpeed = 100.0f;

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	void Move(float DeltaTime);
};
