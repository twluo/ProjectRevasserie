// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "myPlayerController.h"
#include "Board/board.h"
#include "myGameController.generated.h"

UCLASS()
class PROJECTREVASSERIE_API AmyGameController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AmyGameController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "GameControllerFunctions")
	TArray<AbasicCharacter*> getAllCharacters();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameControllerProperties")
	Aboard* board;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameControllerProperties")
	TArray<AmyPlayerController*> players;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameControllerProperties")
	float turnTimeLimit;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameControllerProperties")
	AmyPlayerController* activePlayer;
};
