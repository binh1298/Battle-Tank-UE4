// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Runtime/Engine/Classes/Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	public:
		ATank* GetControlledTank() const;
	
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
		
		void AimTowardsCrosshair();
	private:
		bool GetSightRayHitLocation(FVector& HitLocation) const;
		UPROPERTY(EditAnywhere)
			float CrosshairXLocation = 0.5;
		UPROPERTY(EditAnywhere)
			float CrosshairYLocation = 0.3333;
		UPROPERTY(EditAnywhere)
			float LineTraceRange = 1000000;
		// Get the Unit Vector that tells the direction at which the camera is looking
		// So front would be 1 0 0, right would be 0 1 0, etc
		bool GetLookDirection(FVector2D ScreenCrosshairLocation, FVector& LookDirection) const;
		bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
