// Fill out your copyright notice in the Description page of Project Settings.


#include "seaSawPlank.h"

// Sets default values
AseaSawPlank::AseaSawPlank()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	plank = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("plank"));
	RootComponent = plank;

	block = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("block"));
	block->SetupAttachment(RootComponent);


}

// Called when the game starts or when spawned
void AseaSawPlank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AseaSawPlank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

