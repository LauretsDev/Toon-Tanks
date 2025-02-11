// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()

public:
	ATower();
	virtual void Tick(float DeltaSeconds) override;
	void HandleDestruction();

protected:
	virtual void BeginPlay() override;

private:
	class ATank* Tank;
	UPROPERTY(EditAnywhere, Category="FireSettings")
	float FireRange;

	FTimerHandle FireRateTimerHandle;
	float FireRate;
	void CheckFireCondition();
	bool bIsTankWithinRange();
};
