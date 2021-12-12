// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidgetManager.generated.h"

/**
 * 
 */
UCLASS()
class MAGICIANGAME_API UUserWidgetManager : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable)
	void WidgetHidden(int WidgetNum);
	UFUNCTION(BlueprintCallable)
	void WidgetVisible(int WidgetNum);
	
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<UUserWidget*> WidgetArray;
};
