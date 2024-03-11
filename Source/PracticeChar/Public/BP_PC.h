// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BP_PC.generated.h"

class UInputMappingContext;

/**
 * 
 */
UCLASS()
class PRACTICECHAR_API ABP_PC : public APlayerController
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data");
	TObjectPtr<UInputMappingContext> DefaultIMC;

	virtual void BeginPlay() override;
	
};
