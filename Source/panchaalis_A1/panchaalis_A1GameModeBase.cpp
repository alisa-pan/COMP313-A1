// Copyright Epic Games, Inc. All Rights Reserved.


#include "panchaalis_A1GameModeBase.h"

//code from https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/ProgrammingWithCPP/CPPTutorials/FirstPersonShooter/1/
//when the game begins, the TEXT below will be displayed onscreen for 5 seconds in yellow
void Apanchaalis_A1GameModeBase::StartPlay() {
	Super::StartPlay();

	check(GEngine != nullptr);

	//Display debug message for five seconds
	//The -1 "Key" value argument prevents the message from being updated or refreshed.
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Hello World, this is panchaalis_A1GameMode!"));
}