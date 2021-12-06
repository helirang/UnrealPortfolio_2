// Fill out your copyright notice in the Description page of Project Settings.


#include "Mode_Magic_PlayerState.h"

int32 AMode_Magic_PlayerState::GetMagicMap(EMagicEnum MagicKinds)
{
	if (MagicMap_PS.Contains(MagicKinds))
	{
		return MagicMap_PS[MagicKinds];
	}
	else
	{
		return 0;
	}
}

void AMode_Magic_PlayerState::SetMagicMap(EMagicEnum MagicKinds, int32 MagicGrade)
{
	if (MagicMap_PS.Contains(MagicKinds))
	{
		MagicMap_PS[MagicKinds] = MagicGrade;
	}
}

void AMode_Magic_PlayerState::SettingMagicComp(TMap<EMagicEnum, int32>& Temp_MagicMap_Comp)
{
	Temp_MagicMap_Comp = MagicMap_PS;
}
