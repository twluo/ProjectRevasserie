// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectRevasserie.h"
#include "myGameController.h"


// Sets default values
AmyGameController::AmyGameController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AmyGameController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AmyGameController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

TArray<AbasicCharacter*> AmyGameController::getAllCharacters() {
	TArray<AbasicCharacter*> characterList;
	for (int i = 0; i < players.Num(); i++) {
		characterList.Append(players[i]->getAllCharacters());
	}
	return characterList;
}

void AmyGameController::nextTurn() {
	activePlayer->endTurn();
    if (activePlayer->activeCharacter) {
        board->unhighlightTiles(activePlayer->deselectCharacter());
    }
	activePlayer = players[(activePlayer->playerId + 1) % players.Num()];
	activePlayer->startTurn();
}

void AmyGameController::onCharacterClicked(AbasicCharacter* character){
	if (!character || !character->turnStatus) {
		return;
	}
	TArray<AboardTile*> tilesInRange = board->getTilesInRange(character->currentTile, character->remainingMoves + character->attackRange);
	if (!activePlayer->activeCharacter) {
		board->highlightTiles(activePlayer->selectCharacter(character, tilesInRange));
	}
	else if (activePlayer->activeCharacter == character) {
		board->unhighlightTiles(activePlayer->deselectCharacter());
	}
	else {
		board->unhighlightTiles(activePlayer->deselectCharacter());
		board->highlightTiles(activePlayer->selectCharacter(character, tilesInRange));
	}
}

void AmyGameController::onTileClicked(AboardTile* tile) {
	if (!tile || !activePlayer->activeCharacter) {
		return;
	}
	if (activePlayer->activeCharacter->tilesInRange.Contains(tile) && activePlayer->activeCharacter->remainingMoves >= tile->cost && !tile->isOccupied()) {
		activePlayer->moveCharacter(tile);
		board->unhighlightTiles(activePlayer->deselectCharacter());
	}
}