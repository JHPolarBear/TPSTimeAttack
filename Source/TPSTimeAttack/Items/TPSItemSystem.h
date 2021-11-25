// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CommonDefines.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TPSItemSystem.generated.h"

/**
 * 
 */
UCLASS()
class TPSTIMEATTACK_API UTPSItemSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UTPSItemSystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

private:
	
	// Load Item table from resource
	// 리소스에서 아이템 테이블 로드
	bool	LoadItemTable();

	// Test Function
	void	Debug_PrintItemTable();

private:
	class UDataTable* TPSItemTable;
	
};
