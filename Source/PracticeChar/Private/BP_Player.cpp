// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Player.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"



// Sets default values
ABP_Player::ABP_Player()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	GetMesh()->SetRelativeLocation(FVector(0, 0, -GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));
	GetMesh()->SetRelativeRotation(FRotator(0, -90.0f, 0));

}

// Called when the game starts or when spawned
void ABP_Player::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABP_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* UEIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (UEIC)
	{
		UEIC->BindAction(IA_Jump, ETriggerEvent::Triggered, this, &ABP_Player::Jump);
		UEIC->BindAction(IA_Jump, ETriggerEvent::Canceled, this, &ABP_Player::StopJumping);

		UEIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ABP_Player::Move);
		UEIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ABP_Player::Look);

	}




}

void ABP_Player::Move(const FInputActionValue& Value)
{
	FVector2D Dir = Value.Get<FVector2D>();

	FRotator CameraRotator = GetControlRotation();
	FRotator DirectionRotator = FRotator(0, CameraRotator.Yaw, 0);

	FVector ForwardVector = UKismetMathLibrary::GetForwardVector(DirectionRotator);
	FVector RightVector = UKismetMathLibrary::GetRightVector(DirectionRotator);

	AddMovementInput(ForwardVector, Dir.Y);
	AddMovementInput(RightVector, Dir.X);
}

void ABP_Player::Look(const FInputActionValue& Value)
{
	FVector2D Rotation = Value.Get<FVector2D>();

	AddControllerYawInput(Rotation.X);
	AddControllerPitchInput(Rotation.Y);
}

