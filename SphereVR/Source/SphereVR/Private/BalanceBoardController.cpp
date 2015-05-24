// Fill out your copyright notice in the Description page of Project Settings.

#include "SphereVR.h"
#include "BalanceBoardController.h"

//ABalanceBoardController::ABalanceBoardController(const FObjectInitializer& ObjectInitializer)
//	: Super(ObjectInitializer)
//{
//#ifdef WITH_BALANCE_BOARD_BINDING
//	UE_LOG(LogTemp, Warning, TEXT("WITH_BALANCE_BOARD_BINDING"));
//
//	remote.CallbackTriggerFlags = (state_change_flags)(CONNECTED |
//		EXTENSION_CHANGED |
//		MOTIONPLUS_CHANGED);
//#endif
//}


void ABalanceBoardController::Tick(float DeltaSeconds)
{
	//TEST
	//this->TopLeftWeightEvent(20.0f);
	//this->TopRightWeightEvent(30.0f);
	//this->BottomLeftWeightEvent(40.0f);
	//this->BottomRightWeightEvent(50.0f);
	//this->TotalWeightEvent(60.0f);

	UE_LOG(LogTemp, Warning, TEXT("Tick_Balance_Board"));

	if (connected)
	{
		if (remote.ConnectionLost())
		{
			connected = false;
			return;
		}

		if (remote.IsBalanceBoard())
		{
			this->TopLeftWeightEvent(remote.BalanceBoard.Kg.TopL);
			this->TopRightWeightEvent(remote.BalanceBoard.Kg.TopR);
			this->BottomLeftWeightEvent(remote.BalanceBoard.Kg.BottomL);
			this->BottomRightWeightEvent(remote.BalanceBoard.Kg.BottomR);
			this->TotalWeightEvent(remote.BalanceBoard.Kg.Total);
		}
	}
	else
	{
		int count = 0;

		while (!remote.Connect(wiimote::FIRST_AVAILABLE))
		{

			count++;
			//UE_LOG(LogTemp, Warning, TEXT("EACH_TICK_LOG Current count is %d"), count);
			if (count > 60) return;
		}

		UE_LOG(LogTemp, Warning, TEXT("BalanceBoardConnected"));
		connected = true;
	}
}
