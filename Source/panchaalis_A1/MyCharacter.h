// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//include camera file so i can change camera placement
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"



UCLASS()
class PANCHAALIS_A1_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ApplesEaten;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool win = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//tutorial code
	// handles input for moving forward and backward
	UFUNCTION()
	void MoveForward(float Value);

	// handles input for moving right and left
	UFUNCTION()
	void MoveRight(float Value);

	// sets jump flag (from ACharacter base class) to true when key is pressed
	UFUNCTION()
	void StartJump();

	// clears jump flag when key is released
	UFUNCTION()
	void StopJump();

	//camera 
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* TPCameraComponent;

	//end tutorial code
	
	// eat apple
	UFUNCTION()
	void Eat();


};
