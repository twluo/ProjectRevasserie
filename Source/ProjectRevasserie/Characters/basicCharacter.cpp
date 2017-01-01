// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectRevasserie.h"
#include "basicCharacter.h"


// Sets default values
AbasicCharacter::AbasicCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AbasicCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AbasicCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AbasicCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AbasicCharacter::setLocation(AboardTile* tile) {
	this->currentTile = tile; 
}

void AbasicCharacter::startTurn() {
	remainingMoves = movementRange;
	turnStatus = true;
}

void AbasicCharacter::endTurn() {
	turnStatus = false;
}

void AbasicCharacter::postMove_Implementation(AboardTile* tile) {

}
void AbasicCharacter::move(AboardTile* tile) {
    if (currentTile) {
        currentTile->characterOnTile = NULL;
    }
    currentTile = tile;
    currentTile->characterOnTile = this;
    postMove(currentTile);
}

/*
    1 means empty tile
    2 means enemy tile
    3 means friendly tile
*/
int32 AbasicCharacter::getTileStatus(AboardTile* tile) {
    if (tile) {
        if (!tile->characterOnTile) {
            return tile->cost > this->remainingMoves ? 2 : 1;
        }
        return playerControllerId == tile->characterOnTile->playerControllerId ? 3 : 2;
    }
    return 0;
}
