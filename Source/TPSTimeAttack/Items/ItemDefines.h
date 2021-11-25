// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"

#include "Engine/DataTable.h"
#include "ItemDefines.generated.h"

USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_BODY()


public:
	FItemData() : Type(0), Name(TEXT("")), FireRate(1.f), IsProjectileBounce(false), ThumbnailPath(TEXT("")) {}

	// Weapon ID
	// use datatable index

	// Weapon Type
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	int32 Type;

	// Weapon English name
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
		FString Name;

	/** Weapon Fire Rate */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	float FireRate;

	/** can the projectile from weapon can be bounce */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	bool IsProjectileBounce;

	// Weapon Thumbnail file name
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Data)
	FString ThumbnailPath;
};