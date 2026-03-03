// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FP_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FLAPPYBIRD_API AFP_PlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void SetupInputComponent() override;
};
