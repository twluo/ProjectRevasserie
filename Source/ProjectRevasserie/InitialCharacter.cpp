// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectRevasserie.h"
#include "InitialCharacter.h"


// Sets default values
AInitialCharacter::AInitialCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "CharacterData")
	hp = 10000;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "CharacterData")
	mp = 100;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "CharacterData")
	attackPower = 50;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "CharacterData")
	defense = 5;

}

// Called when the game starts or when spawned
void AInitialCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInitialCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AInitialCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

