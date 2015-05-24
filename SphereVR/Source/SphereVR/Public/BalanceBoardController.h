// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "wiimote.h"
#include "GameFramework/Actor.h"
#include "BalanceBoardController.generated.h"

UCLASS()
class SPHEREVR_API ABalanceBoardController : public AActor
{
	GENERATED_BODY()


//#ifdef WITH_BALANCE_BOARD_BINDING
private:
	bool connected = false;
	wiimote remote;

public:

	UFUNCTION(BlueprintImplementableEvent, Category = "BalanceBoard")
	void TopLeftWeightEvent(float weight);

	UFUNCTION(BlueprintImplementableEvent, Category="BalanceBoard")
	void TopRightWeightEvent(float weight);

	UFUNCTION(BlueprintImplementableEvent, Category = "BalanceBoard")
	void BottomLeftWeightEvent(float weight);

	UFUNCTION(BlueprintImplementableEvent, Category = "BalanceBoard")
	void BottomRightWeightEvent(float weight);

	UFUNCTION(BlueprintImplementableEvent, Category = "BalanceBoard")
	void TotalWeightEvent(float weight);

	/** the desired intensity for the light */

	virtual void Tick(float DeltaSeconds) override;

//#endif
};
