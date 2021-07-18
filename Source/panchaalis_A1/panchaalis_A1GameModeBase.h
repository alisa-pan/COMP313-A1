// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "panchaalis_A1GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PANCHAALIS_A1_API Apanchaalis_A1GameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	//function declaration to override StartPlay (code from tutorial)
	virtual void StartPlay() override;

};
