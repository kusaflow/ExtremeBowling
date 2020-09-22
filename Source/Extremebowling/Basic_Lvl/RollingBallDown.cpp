// Fill out your copyright notice in the Description page of Project Settings.


#include "RollingBallDown.h"

// Sets default values
ARollingBallDown::ARollingBallDown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("base"));
	RootComponent = Base;

	LeftWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("left"));
	LeftWall->SetupAttachment(RootComponent);

	rightWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("right"));
	rightWall->SetupAttachment(RootComponent);

	floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("floor"));
	floor->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ARollingBallDown::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARollingBallDown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

