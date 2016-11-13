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

void AbasicCharacter::setLocation(int32 x, int32 y) {
	this->x = x;
	this->y = y;
}

void AbasicCharacter::startTurn() {
	remainingMoves = movementRange;
	turnStatus = true;
}

void AbasicCharacter::endTurn() {
	turnStatus = false;
}
