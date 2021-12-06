// Fill out your copyright notice in the Description page of Project Settings.


#include "Mode_MagicSpawnManager.h"

// Sets default values
AMode_MagicSpawnManager::AMode_MagicSpawnManager()
{
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	bIsReady = true;
}

// Called when the game starts or when spawned
void AMode_MagicSpawnManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMode_MagicSpawnManager::MagicRequest(AActor* Requester, FString MagicKinds, int32 MagicGrade, int32 TeamNum)
{
	if (bIsReady)
	{
		if (FireMagicProjectiles[0] != nullptr)
		{
			FVector tempVector = Requester->GetActorLocation() + Requester->GetActorForwardVector()*180;
			FRotator tempRotatior = Requester->GetActorRotation();
			GetWorld()->SpawnActor(FireMagicProjectiles[0], &tempVector, &tempRotatior, SpawnInfo);
		}
	}
	else
	{

	}
}
