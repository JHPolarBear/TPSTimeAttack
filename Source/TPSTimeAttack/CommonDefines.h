// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "Characters/CharacterDefines.h"

DECLARE_LOG_CATEGORY_EXTERN(TPS, Log, All);

// Custom Log and Null check
#define LOG_CALLINFO (FString(__FUNCTION__) + TEXT("[") + FString::FromInt(__LINE__) + TEXT("]"))
#define LOG_WARNING(format, ...) UE_LOG(TPS, Warning, TEXT("%s %s"), *LOG_CALLINFO, *FString::Printf(format, ##__VA_ARGS__)) 
#define LOG_ERROR(format, ...) UE_LOG(TPS, Error, TEXT("%s %s"), *LOG_CALLINFO, *FString::Printf(format, ##__VA_ARGS__)) 

#define ASSERT_CHECK(Expr, ...) {if(!(Expr)) { LOG_ERROR(TEXT("ASSERTION : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__; }}