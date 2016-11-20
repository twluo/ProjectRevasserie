// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectRevasserie.h"
#include "boardTile.h"


// Sets default values
AboardTile::AboardTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	cost = -1;
}

// Called when the game starts or when spawned
void AboardTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AboardTile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

