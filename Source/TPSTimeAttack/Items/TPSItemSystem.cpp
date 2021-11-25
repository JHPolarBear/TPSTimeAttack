// Fill out your copyright notice in the Description page of Project Settings.


#include "TPSItemSystem.h"

#include "Engine/DataTable.h"

UTPSItemSystem::UTPSItemSystem()
{
	// Load Item Table on construction
	// FObjectFinder는 생성자에서만 호출 가능
	LoadItemTable();

	LOG_WARNING(TEXT("Item System created"));
}

void UTPSItemSystem::Initialize(FSubsystemCollectionBase& Collection)
{
	LOG_WARNING(TEXT("Item System initialized"));
}

void UTPSItemSystem::Deinitialize()
{
	LOG_WARNING(TEXT("Item System deinitialized"));
}

bool UTPSItemSystem::LoadItemTable()
{
	//Load Item table
	FString ItemTablePath = TEXT("DataTable'/Game/Items/ItemTable.ItemTable'");
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_ITEMTABLE(*ItemTablePath);

	if (DT_ITEMTABLE.Succeeded())
	{
		TPSItemTable = DT_ITEMTABLE.Object;
	}

	if(TPSItemTable->GetRowMap().Num() <= 0)
	{
		LOG_ERROR(TEXT("InValid row size"));
		return false;
	}

#ifdef WITH_EDITOR
	// Print item table list (Only debug)
	Debug_PrintItemTable();
#endif // WITH_EDITOR

	return true;
}

void UTPSItemSystem::Debug_PrintItemTable()
{
	if(TPSItemTable == nullptr)
	{
		LOG_ERROR(TEXT("Item table not exists"));
		return;
	}

	if (TPSItemTable->GetRowMap().Num() <= 0)
	{
		LOG_ERROR(TEXT("InValid row size"));
		return;
	}

	TArray<TArray<FString>> itemLists = TPSItemTable->GetTableData();
	for (TArray<FString> lists : itemLists)
	{
		FString colList;

		for (FString col : lists)
		{
			colList.Append(col);
			colList.Append(" / ");
		}

		LOG_WARNING(TEXT("%s"), *colList);
	}
}
