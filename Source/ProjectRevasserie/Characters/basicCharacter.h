// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "Board/board.h"
#include "basicCharacter.generated.h"

UCLASS()
class PROJECTREVASSERIE_API AbasicCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AbasicCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//Functions
	UFUNCTION(BlueprintCallable, Category = "Character|Functions")
	virtual void setLocation(AboardTile* tile);

	UFUNCTION(BlueprintCallable, Category = "Character|Functions")
	virtual void startTurn();

	UFUNCTION(BlueprintCallable, Category = "Character|Functions")
	virtual void endTurn();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Character|Functions")
	void move(AboardTile* tile);

	//Stats
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Character|Stats")
	int32 hp;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Character|Stats")
	int32 mp;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Character|Stats")
	int32 attackPower;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Character|Stats")
	int32 defense;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Character|Stats")
	int32 movementRange;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Character|Stats")
	int32 attackRange;

	//Properties
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Character|Properties")
	bool turnStatus;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Character|Properties")
	int32 remainingMoves;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Character|Properties")
	TArray<AboardTile*> tilesInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Properties", Meta = (ExposeOnSpawn = true))
	AboardTile* currentTile;

	
};
