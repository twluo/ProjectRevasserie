// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectRevasserie.h"
#include "myPlayerController.h"


// Sets default values
AmyPlayerController::AmyPlayerController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AmyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AmyPlayerController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

TArray<AbasicCharacter*> AmyPlayerController::getAllCharacters() {
	return characterList;
}

void AmyPlayerController::startTurn() {
	this->turnStatus = true;
	for (int i = 0; i < characterList.Num(); i++) {
		characterList[i]->startTurn();
	}
}

void AmyPlayerController::endTurn() {
	this->turnStatus = false;
	for (int i = 0; i < characterList.Num(); i++) {
		characterList[i]->endTurn();
	}
}

AbasicCharacter* AmyPlayerController::selectCharacter(AbasicCharacter* character, TArray<AboardTile*> tilesInRange){
	activeCharacter = character;
	activeCharacter->tilesInRange = tilesInRange;
	return activeCharacter;
}

AbasicCharacter* AmyPlayerController::deselectCharacter(){
	AbasicCharacter *character = activeCharacter;
	activeCharacter = NULL;
	return character;
}

void AmyPlayerController::moveCharacter(AboardTile* tile) {
	activeCharacter->move(tile);
	activeCharacter->remainingMoves -= tile->cost;
}