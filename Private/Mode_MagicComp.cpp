// Fill out your copyright notice in the Description page of Project Settings.


#include "Mode_MagicComp.h"
#include "Mode_Magic_PlayerState.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
UMode_MagicComp::UMode_MagicComp()
{
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
}


// Called when the game starts
void UMode_MagicComp::BeginPlay()
{
	Super::BeginPlay();
	
	GetOwner();
	// ...

	ACharacter* TempOwner = Cast<ACharacter>(GetOwner());

	if (TempOwner->IsPlayerControlled())
	{
		PS_Magic = Cast<AMode_Magic_PlayerState>(TempOwner->GetPlayerState());
		PS_Magic->SettingMagicComp(MagicMap_Comp);

		for (auto& Elem : MagicMap_Comp)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d"), Elem.Value);
		}
	}
}

void UMode_MagicComp::MagicQuitFire(EMagicEnum MagicKinds)
{
	UClass* FireMagic;
	AActor* MyOwner = GetOwner();

	switch (MagicKinds)
	{
	case EMagicEnum::E_Fire:
		if(FireMagicProjectiles[MagicMap_Comp[MagicKinds]] != nullptr)
		FireMagic = FireMagicProjectiles[MagicMap_Comp[MagicKinds]];
		break;
	case EMagicEnum::E_Water:
		if (WaterMagicProjectiles[MagicMap_Comp[MagicKinds]] != nullptr)
		FireMagic = WaterMagicProjectiles[MagicMap_Comp[MagicKinds]];
		break;
	case EMagicEnum::E_Earth:
		if (EarthMagicProjectiles[MagicMap_Comp[MagicKinds]] != nullptr)
		FireMagic = EarthMagicProjectiles[MagicMap_Comp[MagicKinds]];
		break;
	default:
		if (FireMagicProjectiles[MagicMap_Comp[MagicKinds]] != nullptr)
		FireMagic = FireMagicProjectiles[MagicMap_Comp[MagicKinds]];
		break;
	}

	FVector tempVector = MyOwner->GetActorLocation() + MyOwner->GetActorForwardVector() * 180;
	FRotator tempRotatior = MyOwner->GetActorRotation();
	GetWorld()->SpawnActor(FireMagic, &tempVector, &tempRotatior, SpawnInfo);
}

