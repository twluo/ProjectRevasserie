// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Board/board.h"
#include "hexBoard.generated.h"

/**
 * 
 */

UCLASS()
class PROJECTREVASSERIE_API AhexBoard : public Aboard
{
	GENERATED_BODY()
	
	
public:

	virtual TArray<AboardTile*> getNeighbors(AboardTile* tile) override;

	virtual TArray<AboardTile*> getTilesInRange(AboardTile* tile, int32 range) override;
	
};
