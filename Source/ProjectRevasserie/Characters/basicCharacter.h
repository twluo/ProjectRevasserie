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
	UFUNCTION(BlueprintCallable, Category = "basicCharacter|Functions")
	virtual void setLocation(AboardTile* tile);

	UFUNCTION(BlueprintCallable, Category = "basicCharacter|Functions")
	virtual void startTurn();

	UFUNCTION(BlueprintCallable, Category = "basicCharacter|Functions")
	virtual void endTurn();

    UFUNCTION(BlueprintCallable, Category = "basicCharacter|Functions")
    void move(AboardTile* tile);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "basicCharacter|Functions")
	void postMove(AboardTile* tile);

    UFUNCTION(BlueprintCallable, Category = "basicCharacter|Functions")
    int32 getTileStatus(AboardTile* tile);

	//Stats
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "basicCharacter|Stats")
	int32 hp;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "basicCharacter|Stats")
	int32 mp;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "basicCharacter|Stats")
	int32 attackPower;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "basicCharacter|Stats")
	int32 defense;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "basicCharacter|Stats")
	int32 movementRange;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "basicCharacter|Stats")
	int32 attackRange;

	//Properties
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "basicCharacter|Properties")
	bool turnStatus;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "basicCharacter|Properties")
	int32 remainingMoves;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "basicCharacter|Properties")
	TArray<AboardTile*> tilesInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "basicCharacter|Properties", Meta = (ExposeOnSpawn = true))
	AboardTile* currentTile;

    UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "basicCharacter|Properties")
    int32 playerControllerId;
};
