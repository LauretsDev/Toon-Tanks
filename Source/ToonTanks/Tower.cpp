// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"

ATower::ATower()
{
	FireRange = 150.f;
	FireRate = 2.f;
}

void ATower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Find the distance to the tank
	if (bIsTankWithinRange())
	{
		RotateTurret(Tank->GetActorLocation());
	}

	// Check to see if the tank is in range

	// If in range, rotate turret towards tank
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
	UE_LOG(LogTemp, Warning, TEXT("Tower was Destroyed"));
}

void ATower::BeginPlay()
{
	Super::BeginPlay();
	
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
	if (bIsTankWithinRange())
	{
		Fire();
	}
}

bool ATower::bIsTankWithinRange()
{
	if (Tank && Tank->bAlive)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		return Distance <= FireRange;
	}
	return false;
}
