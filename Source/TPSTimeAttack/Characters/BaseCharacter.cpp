// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	// Create a camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	
	// Initialize camera type with TPS view
	SetCameraType(CameraType, true);

	
	
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FORCEINLINE void ABaseCharacter::SetCameraType(ECameraTypes eNewCameraType, bool init)
{
	if(!init && eNewCameraType == CameraType)
	{
		LOG_WARNING(TEXT("already set to camrea type: %d"), (int)eNewCameraType);
		return;
	}
	else
	{
		LOG_WARNING(TEXT("set to camrea type: %d"), (int)eNewCameraType);
	}

	CameraType = eNewCameraType;

	switch (CameraType)
	{	
	case ECameraTypes::ECamera_TPS:
	{
		CameraBoom->TargetArmLength = 1200.f;
		CameraBoom->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
		
		CameraBoom->bUsePawnControlRotation = false;

		CameraBoom->bInheritPitch = false;
		CameraBoom->bInheritRoll = false;
		CameraBoom->bInheritYaw = false;

		bUseControllerRotationYaw = true;
	}
		break;
	case ECameraTypes::ECamera_FPS:
		break;
	case ECameraTypes::ECamrea_Max:
	case ECameraTypes::ECamera_None:
	default:
		break;
	}
}

