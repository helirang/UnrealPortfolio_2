// Fill out your copyright notice in the Description page of Project Settings.


#include "Mode_MagicComp.h"
#include "Mode_Magic_PlayerState.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
UMode_MagicComp::UMode_MagicComp()
{
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
}

void UMode_MagicComp::BeginPlay()
{
	Super::BeginPlay();
	
	GetOwner();

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

// MagicKinds ��û ���� �迭 @Todo MagicGrade ��� ���� ����� ������ �߰� ����.
// ex -> grade 1 == ���̾, grade 2 == ���̾�� ��
void UMode_MagicComp::MagicQuitFire(EMagicEnum MagicKinds)
{
	UClass* FireMagic = nullptr;
	AActor* MyOwner = GetOwner();

	switch (MagicKinds)
	{
	case EMagicEnum::E_Fire:
		if (FireMagicProjectiles.Num() != 0) //@Todo ��û�ϴ� ��ų ��� ����ȭ, �ش� ��޿� ���� Num ����
		FireMagic = FireMagicProjectiles[MagicMap_Comp[MagicKinds]];
		break;
	case EMagicEnum::E_Water:
		if (WaterMagicProjectiles.Num() != 0)
		FireMagic = WaterMagicProjectiles[MagicMap_Comp[MagicKinds]];
		break;
	case EMagicEnum::E_Earth:
		if (EarthMagicProjectiles.Num() != 0)
		FireMagic = EarthMagicProjectiles[MagicMap_Comp[MagicKinds]];
		break;
	default:
		if (FireMagicProjectiles.Num() != 0)
		FireMagic = FireMagicProjectiles[MagicMap_Comp[MagicKinds]];
		break;
	}
	
	if (FireMagic != nullptr)
	{
		FVector tempVector = MyOwner->GetActorLocation() + MyOwner->GetActorForwardVector() * 180;
		FRotator tempRotatior = MyOwner->GetActorRotation();
		GetWorld()->SpawnActor(FireMagic, &tempVector, &tempRotatior, SpawnInfo);
	}
}

