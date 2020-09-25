 // Fill out your copyright notice in the Description page of Project Settings.


#include "C_mainChar.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../essential/kusaGameInstance.h"


#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AC_mainChar::AC_mainChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	sphere = CreateDefaultSubobject<USphereComponent>(TEXT("sphere"));
	sphere->SetupAttachment(RootComponent);;

	wheel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh"));
	wheel->SetupAttachment(sphere);
	wheel->SetWorldScale3D(FVector(0.6f));

	cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	cameraBoom->SetupAttachment(sphere);
	cameraBoom->bDoCollisionTest = false;
	cameraBoom->TargetArmLength = 400;
	cameraBoom->SetRelativeRotation(FRotator(340, 0, 0));
	cameraBoom->bInheritPitch = false;
	cameraBoom->bInheritRoll = false;
	cameraBoom->bInheritYaw = false;


	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(cameraBoom, USpringArmComponent::SocketName);
	FollowCamera->SetRelativeRotation(FRotator(15, 0, 0));

}

// Called when the game starts or when spawned
void AC_mainChar::BeginPlay()
{
	Super::BeginPlay();

	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
	gameInst->SpeedTimer = 0;
	
}

// Called every frame
void AC_mainChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
	gameInst->playerPos = RootComponent->GetComponentLocation().X;

	RootComponent->SetWorldLocation(sphere->GetComponentLocation());
	wheel->SetRelativeRotation(sphere->GetRelativeRotation());

	if (!brakeOn) {
		//sphere->AddAngularImpulseInDegrees(FVector(0, 3000 * DeltaTime, 0), NAME_None, true);
		//sphere->AddAngularImpulse(FVector(0, 3000 * DeltaTime, 0), NAME_None, true);
		sphere->AddForce(FVector(50000*DeltaTime, 0, 0), NAME_None, true);
	}


	if (gameInst->SpeedTimer <= 500) {
		gameInst->SpeedTimer += 100 * DeltaTime;
	}

}

// Called to bind functionality to input
void AC_mainChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Dir", this, &AC_mainChar::Movement);
	PlayerInputComponent->BindAxis("Brake", this, &AC_mainChar::brake_F);

}

void AC_mainChar::Movement(float val) {
	if (val == -1) {
		sphere->AddForce(FVector(0, -2000, 0), NAME_None, true);
	}
	else if (val == 1) {
		sphere->AddForce(FVector(0, 2000, 0), NAME_None, true);
	}
}



void AC_mainChar::brake_F(float val) {
	brakeOn = false;
	if (val == 1) {
		brakeOn = true;
		FVector currV = sphere->GetComponentVelocity();// GetVelocity();

		if (currV.X >= 1000) {
			currV.X /= 1.03f;
			currV.Y /= 1.03f;
		}
		else {
			currV.X /= 1.2f;
			currV.Y /= 1.2f;
		}


		sphere->SetPhysicsLinearVelocity(currV);
		//sphere->AddAngularImpulseInDegrees(currV);
		//sphere->AddForce(currV, NAME_None, true);
	}
}


