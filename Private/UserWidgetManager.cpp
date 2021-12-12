// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgetManager.h"

void UUserWidgetManager::WidgetHidden(int WidgetNum)
{
	if (WidgetArray.Num() > WidgetNum)
	{
		WidgetArray[WidgetNum]->SetVisibility(ESlateVisibility::Collapsed);
		UE_LOG(LogTemp,Log,TEXT("Hidden"));
	}
}

void UUserWidgetManager::WidgetVisible(int WidgetNum)
{
	if (WidgetArray.Num() > WidgetNum)
	{
		WidgetArray[WidgetNum]->SetVisibility(ESlateVisibility::Visible);
		UE_LOG(LogTemp, Log, TEXT("Visible"));
	}
}
