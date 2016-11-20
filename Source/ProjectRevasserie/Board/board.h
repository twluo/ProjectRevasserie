// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "boardTile.h"
#include "board.generated.h"


USTRUCT(BlueprintType)
struct FMapDataTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()


	/** The 'Name' column is the same as the XP Level */

	/** Icon to use for Achivement */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelUp")
	int32 tileMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelUp")
	int32 tileCost;
};

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

	UFUNCTION(BlueprintCallable, Category = "Board|Functions")
	virtual TArray<AboardTile*> getNeighbors(AboardTile* tile);

	UFUNCTION(BlueprintCallable, Category = "Board|Functions")
	virtual TArray<AboardTile*> getTilesInRange(AboardTile* tile, int32 range);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Board|Functions")
	void highlightTiles(const TArray<AboardTile*>& tilesInRange, int32 movementCost);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Board|Functions")
	void unhighlightTiles(const TArray<AboardTile*>& tilesInRange);

	UFUNCTION(BlueprintCallable, Category = "Board|Functions")
	AboardTile* getTile(int32 x, int32 y);

	UFUNCTION(BlueprintCallable, Category = "Board|Functions")
	bool inBounds(int32 x, int32 y);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board|Properties", meta = (ClampMin = 1, UIMin = 1))
	int32 numOfTilesX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board|Properties", meta = (ClampMin = 1, UIMin = 1))
	int32 numOfTilesY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board|Properties", meta = (ClampMin = 1, UIMin = 1))
	float tileSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Board|Properties")
	TArray<AboardTile*> mapArray;

	
};