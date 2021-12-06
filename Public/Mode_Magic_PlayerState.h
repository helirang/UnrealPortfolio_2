// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Mode_Magic_PlayerState.generated.h"

UENUM(BlueprintType)
enum class EMagicEnum : uint8
{
	E_Fire = 0 UMETA(DisplayName = "FireMagic"),
	E_Water  UMETA(DisplayName = "WaterMagic"),
	E_Earth  UMETA(DisplayName = "EarthMagic"),
};

UCLASS()
class MAGICIANGAME_API AMode_Magic_PlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	int32 GetMagicMap(EMagicEnum MagicKinds);
	void SetMagicMap(EMagicEnum MagicKinds, int32 MagicGrade);
	void SettingMagicComp(TMap<EMagicEnum, int32>& Temp_MagicMap_Comp);
	
protected:
	UPROPERTY(EditAnywhere,Category = "Mode_Magic")
	TMap<EMagicEnum, int32> MagicMap_PS;
};
