// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"

#include "boardTile.generated.h"



UCLASS()
class PROJECTREVASSERIE_API AboardTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AboardTile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardTile|Properties", meta = (ClampMin = 1, UIMin = 1, ExposeOnSpawn = true))
	float Size;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardTile|Properties", meta = (ExposeOnSpawn = true))
	int32 X;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardTile|Properties", meta = (ExposeOnSpawn = true))
	int32 Y;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardTile|Properties", meta = (ExposeOnSpawn = true))
	int32 MovementCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardTile|Properties")
	int32 Cost;

};
