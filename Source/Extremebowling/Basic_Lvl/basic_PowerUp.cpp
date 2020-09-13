// Fill out your copyright notice in the Description page of Project Settings.


#include "basic_PowerUp.h"
#include "Components/SkeletalMeshComponent.h"
#include "../essential/kusaGameInstance.h"
#include "Components/BoxComponent.h"

// Sets default values
Abasic_PowerUp::Abasic_PowerUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	box = CreateDefaultSubobject<UBoxComponent>(TEXT("box"));
	RootComponent = box;

	power = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("power"));
	power->SetupAttachment(box);

	bg = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("bg"));
	bg->SetupAttachment(box);
	

}

// Called when the game starts or when spawned
void Abasic_PowerUp::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void Abasic_PowerUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

