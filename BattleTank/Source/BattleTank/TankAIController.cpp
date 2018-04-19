// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* AIControlledTank = GetControlledTank();
	if (AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found AI Controlled Tank: %s"), *AIControlledTank->GetName());
	}
	else UE_LOG(LogTemp, Error, TEXT("NOT Found AI Controlled Tank"));

	ATank* PlayerControlledTank = GetPlayerControlledTank();
	if (PlayerControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found Player Controlled Tank: %s"), *PlayerControlledTank->GetName());
	}
	else UE_LOG(LogTemp, Error, TEXT("NOT Found Player Controlled Tank"));
}

void ATankAIController::Tick(float DeltaTime)
{
	if (GetControlledTank())
	{
		GetControlledTank()->AimAt(GetPlayerControlledTank()->GetActorLocation());
	}
}
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
ATank* ATankAIController::GetPlayerControlledTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}



