// Fill out your copyright notice in the Description page of Project Settings.


#include "plus_Spinner.h"

// Sets default values
Aplus_Spinner::Aplus_Spinner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("bar"));
	RootComponent = plane;

	plane->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void Aplus_Spinner::BeginPlay()
{
	Super::BeginPlay();
	
	plane->AddRelativeLocation(FVector(0, 0, -70));
	

	
}

// Called every frame
void Aplus_Spinner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

