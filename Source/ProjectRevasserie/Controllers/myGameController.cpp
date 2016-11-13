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
	activePlayer = players[(activePlayer->playerId + 1) % players.Num()];
	activePlayer->startTurn();
}