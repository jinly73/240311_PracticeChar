// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_PC.h"
#include "EnhancedInputSubsystems.h"

void ABP_PC::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem && DefaultIMC)
	{
		Subsystem->AddMappingContext(DefaultIMC, 0);

	}
}
