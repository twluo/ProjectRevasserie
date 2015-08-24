// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "boardTile.h"
#include "board.generated.h"

UCLASS()
class PROJECTREVASSERIE_API Aboard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Aboard();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (ClampMin = 1, UIMin = 1))
	int32 NumOfTilesX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (ClampMin = 1, UIMin = 1))
	int32 NumOfTilesY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (ClampMin = 1, UIMin = 1))
	float TileSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	TArray<AboardTile*> mapArray;

	
};
