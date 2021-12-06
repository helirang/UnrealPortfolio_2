// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mode_MagicSpawnManager.generated.h"

USTRUCT()
struct FMagicRequsetStruct
{
	GENERATED_USTRUCT_BODY()

public:
	FVector RequesterLocation,RequesterDirection;
	FString MagicKinds;
	int32 MagicGrade,TeamNum;
};

UCLASS()
class MAGICIANGAME_API AMode_MagicSpawnManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMode_MagicSpawnManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable)
	void MagicRequest(AActor* Requester, FString MagicKinds, int32 MagicGrade, int32 TeamNum);

protected:
	UPROPERTY(EditAnywhere, Category = "MagicProjectile")
	TArray<UClass*> FireMagicProjectiles;
	TArray<UClass*> WaterMagicProjectiles;
	TArray<UClass*> EarthMagicProjectiles;
	TMap<FString, UClass*> MagicMap;
	TQueue<FMagicRequsetStruct> RequestQueue;

	FActorSpawnParameters SpawnInfo;
	bool bIsReady;
};
