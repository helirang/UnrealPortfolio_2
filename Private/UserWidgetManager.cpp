// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgetManager.h"

static int32 DebugWidget = 0;
FAutoConsoleVariableRef CVARDebugWidget(
	TEXT("MainGame.DebugWidget"),
	DebugWidget,
	TEXT("Draw Widget OnOff"),
	ECVF_Cheat); //콘솔변수


void UUserWidgetManager::WidgetHidden(int WidgetNum)
{
	if (WidgetArray.Num() > WidgetNum)
	{
		WidgetArray[WidgetNum]->SetVisibility(ESlateVisibility::Collapsed);

		if(DebugWidget > 0)
		UE_LOG(LogTemp,Log,TEXT("Hidden"));
	}
}

void UUserWidgetManager::WidgetVisible(int WidgetNum)
{
	if (WidgetArray.Num() > WidgetNum)
	{
		WidgetArray[WidgetNum]->SetVisibility(ESlateVisibility::Visible);

		if (DebugWidget > 0)
		UE_LOG(LogTemp, Log, TEXT("Visible"));
	}
}
