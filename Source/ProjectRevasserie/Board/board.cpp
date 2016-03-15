// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectRevasserie.h"
#include "board.h"


// Sets default values
Aboard::Aboard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Aboard::BeginPlay()
{
	Super::BeginPlay(); 
	
}

// Called every frame
void Aboard::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

TArray<AboardTile*> Aboard::getNeighbors(int32 x, int32 y) {
	return mapArray;
}

TArray<AboardTile*> Aboard::getTilesInRange(int32 x, int32 y, int32 range) {
	return mapArray;
}

AboardTile* Aboard::getTile(int32 x, int32 y) {
	if (inBounds(x, y)) {
		int32 temp = y * NumOfTilesX + x;
		return mapArray[temp];
	}
	return NULL;
}

bool Aboard::inBounds(int32 x, int32 y) {
	if (y >= 0 && y < NumOfTilesY && x >= 0 && x < NumOfTilesX)
		return true;
	else
		return false;
}