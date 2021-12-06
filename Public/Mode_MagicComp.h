// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Mode_MagicComp.generated.h"

class AMode_Magic_PlayerState;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAGICIANGAME_API UMode_MagicComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMode_MagicComp();

protected:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	void MagicQuitFire(EMagicEnum MagicKinds);

protected:
	UPROPERTY(VisibleAnywhere, Category = "Mode_Magic")
	TMap<EMagicEnum, int32> MagicMap_Comp;
	UPROPERTY()
	AMode_Magic_PlayerState* PS_Magic;

	UPROPERTY(EditAnywhere, Category = "MagicProjectile")
	TArray<UClass*> FireMagicProjectiles;
	UPROPERTY(EditAnywhere, Category = "MagicProjectile")
	TArray<UClass*> WaterMagicProjectiles;
	UPROPERTY(EditAnywhere, Category = "MagicProjectile")
	TArray<UClass*> EarthMagicProjectiles;

	FActorSpawnParameters SpawnInfo;
};
