// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Characters/basicCharacter.h"
#include "myPlayerController.generated.h"

UCLASS()
class PROJECTREVASSERIE_API AmyPlayerController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AmyPlayerController();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, Category = "PlayerController|Functions")
	TArray<AbasicCharacter*> getAllCharacters();

	UFUNCTION(BlueprintCallable, Category = "PlayerController|Functions")
	void startTurn();

	UFUNCTION(BlueprintCallable, Category = "PlayerController|Functions")
	void endTurn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerController|Properties")
	bool turnStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerController|Properties")
	int32 playerId;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerController|Properties")
	TArray<AbasicCharacter*> characterList;
};
