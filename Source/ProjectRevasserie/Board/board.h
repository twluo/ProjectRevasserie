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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
		TAssetPtr<UMaterial> tileMaterial;
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

	UFUNCTION(BlueprintCallable, Category = "Functions")
	virtual TArray<AboardTile*> getNeighbors(int32 x, int32 y);

	UFUNCTION(BlueprintCallable, Category = "Functions")
	virtual TArray<AboardTile*> getTilesInRange(int32 x, int32 y, int32 range);

	UFUNCTION(BlueprintCallable, Category = "Functions")
	AboardTile* getTile(int32 x, int32 y);

	UFUNCTION(BlueprintCallable, Category = "Functions")
	bool inBounds(int32 x, int32 y);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (ClampMin = 1, UIMin = 1))
	int32 NumOfTilesX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (ClampMin = 1, UIMin = 1))
	int32 NumOfTilesY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties", meta = (ClampMin = 1, UIMin = 1))
	float TileSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
	TArray<AboardTile*> mapArray;

	
};

