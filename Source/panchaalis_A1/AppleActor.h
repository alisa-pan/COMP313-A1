// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AppleActor.generated.h"

UCLASS()
class PANCHAALIS_A1_API AAppleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAppleActor();

	// calculated in blueprint: increases by 1 every time AppleActor collides with MyCharacter (the blueprint versions of those classes). 
	// an apple is destroyed when is reaches 2 crowHits. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int crowHits;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// when the crow eats an apple
	void GetEaten();


};
