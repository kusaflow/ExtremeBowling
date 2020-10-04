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
void AmainChar::BeginPlay()
{
	Super::BeginPlay();

	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
	gameInst->SpeedTimer = 0;

	boom_predicted_length = 400;
	
}

// Called every frame
void AmainChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
	gameInst->playerPos = RootComponent->GetComponentLocation().X;

	if (!brakeOn) {
		//sphere->AddAngularImpulseInDegrees(FVector(0, 3000 * DeltaTime, 0), NAME_None, true);
		sphere->AddAngularImpulseInDegrees(FVector(0, 4200 * DeltaTime, 0), NAME_None, true);
	}


	if (gameInst->SpeedTimer <= 500) {
		gameInst->SpeedTimer += 100 * DeltaTime;
	}

	///camera Update Interopolated
	if (cameraBoom->TargetArmLength > boom_predicted_length + 20) {
		cameraBoom->TargetArmLength -= 1200 * DeltaTime;
	}
	else if (cameraBoom->TargetArmLength < boom_predicted_length - 20) {
		cameraBoom->TargetArmLength += 1200 * DeltaTime;
	}

	cameraBoom->SetRelativeRotation(boom_predicted_Rot);

}

// Called to bind functionality to input
void AmainChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Dir", this, &AmainChar::Movement);
	PlayerInputComponent->BindAxis("Brake", this, &AmainChar::brake_F);

}


void AmainChar::Movement (float val) {
	/*
	if (val == -1) {
		sphere->AddForce(FVector(0, -2000, 0), NAME_None, true);
	}
	else if (val == 1){
		sphere->AddForce(FVector(0, 2000, 0), NAME_None, true);
	}*/

	if (val == -1) {
		sphere->AddAngularImpulseInDegrees(FVector(5000 * GetWorld()->GetDeltaSeconds(), 0, 0), NAME_None, true);
		//sphere->AddForce(FVector(0, -2000, 0), NAME_None, true);
	}
	else if (val == 1) {
		sphere->AddAngularImpulseInDegrees(FVector(-5000 * GetWorld()->GetDeltaSeconds(), 0, 0), NAME_None, true);
		//sphere->AddForce(FVector(0, 2000, 0), NAME_None, true);
	}


}



void AmainChar::brake_F(float val) {
	brakeOn = false;
	if (val == 1) {
		brakeOn = true;
		FVector currV = sphere->GetComponentVelocity();

		//currV.X /= 2.0f;
		//currV.X = -1 * currV.X;
		if (currV.X >=0)
			sphere->AddAngularImpulseInDegrees(FVector(0, -9500 *GetWorld()->GetDeltaSeconds(), 0), NAME_None, true);
		if (currV.X < 0)
			sphere->SetPhysicsLinearVelocity(FVector(0, currV.Y, currV.Z));
		//sphere->AddAngularImpulseInDegrees(currV);
		//sphere->AddForce(currV, NAME_None, true);
		//sphere->SetPhysicsLinearVelocity(currV);
	}
}

