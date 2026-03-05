// Fill out your copyright notice in the Description page of Project Settings.


#include "FlappyBird/Public/Character/FP_BirdCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogFP_BirdCharacter, Log, All);

AFP_BirdCharacter::AFP_BirdCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom);
}

void AFP_BirdCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitializeMappingContext();
	SubscribeToOnPointReached();
}

void AFP_BirdCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComp->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComp->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
	}
}

bool AFP_BirdCharacter::CanJumpInternal_Implementation() const
{
	return true;
}

void AFP_BirdCharacter::InitializeMappingContext() const
{
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}
}

void AFP_BirdCharacter::SubscribeToOnPointReached()
{
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AFP_BirdCharacter::HandlePointReached);
}


void AFP_BirdCharacter::HandlePointReached(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                           UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                           const FHitResult& SweepResult)
{
	if (!OtherComp) return;

	if (OtherComp->ComponentHasTag("Point"))
	{
		UE_LOG(LogFP_BirdCharacter, Log, TEXT("Point reached!"));
		OnPointReached.Broadcast();
	}
}

void AFP_BirdCharacter::MakeJump()
{
	UE_LOG(LogFP_BirdCharacter, Log, TEXT("Jumping!"));
	Jump();
}

void AFP_BirdCharacter::StopJump()
{
	StopJumping();
}
