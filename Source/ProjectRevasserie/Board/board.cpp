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



