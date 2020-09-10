// Fill out your copyright notice in the Description page of Project Settings.


#include "mainChar.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../essential/kusaGameInstance.h"

// Sets default values
AmainChar::AmainChar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sphere = CreateDefaultSubobject<USphereComponent>(TEXT("sphere"));
	RootComponent = sphere;

	wheel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
	wheel->SetupAttachment(RootComponent);

	cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	cameraBoom->SetupAttachment(RootComponent);
	cameraBoom->bDoCollisionTest = false;
	cameraBoom->TargetArmLength = 300;
	cameraBoom->SetRelativeRotation(FRotator(-30, 0, 0));
	cameraBoom->bInheritPitch = false;
	cameraBoom->bInheritRoll = false;
	cameraBoom->bInheritYaw = false;


	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(cameraBoom, USpringArmComponent::SocketName);

}

// Called when the game starts or when spawned
void AmainChar::BeginPlay()
{
	Super::BeginPlay();

	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
	gameInst->SpeedTimer = 0;
	
}

// Called every frame
void AmainChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
	gameInst->playerPos = RootComponent->GetComponentLocation().X;

	

	if (!brakeOn) {
		sphere->AddAngularImpulse(FVector(0, 100 * DeltaTime, 0), NAME_None, true);
	}


	if (gameInst->SpeedTimer <= 500) {
		gameInst->SpeedTimer += 100 * DeltaTime;
	}

}

// Called to bind functionality to input
void AmainChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Dir", this, &AmainChar::Movement);
	PlayerInputComponent->BindAxis("Brake", this, &AmainChar::brake_F);

}


void AmainChar::Movement (float val) {
	if (val == -1) {
		sphere->AddForce(FVector(0, -2000, 0), NAME_None, true);
	}
	else if (val == 1){
		sphere->AddForce(FVector(0, 2000, 0), NAME_None, true);
	}
}



void AmainChar::brake_F(float val) {
	brakeOn = false;
	if (val == 1) {
		brakeOn = true;
		FVector currV = GetVelocity();

		currV.X *= -1;
		currV.Y *= -1;
		
		sphere->AddForce(currV, NAME_None, true);
	}
}
