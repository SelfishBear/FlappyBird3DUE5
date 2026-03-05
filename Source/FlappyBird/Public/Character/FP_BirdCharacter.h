// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputMappingContext.h"
#include "FP_BirdCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputAction;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPointReached);

UCLASS()
class FLAPPYBIRD_API AFP_BirdCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AFP_BirdCharacter();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Component")
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Component")
	UCameraComponent* FollowCamera;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnPointReached OnPointReached;

	UFUNCTION()
	void HandlePointReached(UPrimitiveComponent* OverlappedComponent, 
	                        AActor* OtherActor,
	                        UPrimitiveComponent* OtherComp,
	                        int32 OtherBodyIndex,
	                        bool bFromSweep,
	                        const FHitResult& SweepResult);

protected:
	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	virtual bool CanJumpInternal_Implementation() const override;

private:
	void MakeJump();
	void StopJump();

	void InitializeMappingContext() const;

	void SubscribeToOnPointReached();
};
