// Fill out your copyright notice in the Description page of Project Settings.


#include "seaSawPlank.h"

// Sets default values
AseaSawPlank::AseaSawPlank()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	plank = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("plank"));
	RootComponent = plank;

	block1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("block1"));
	block1->SetupAttachment(RootComponent);

	block2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("block2"));
	block2->SetupAttachment(RootComponent);

	plank->SetWorldScale3D(FVector(1,5,0.15));


}

// Called when the game starts or when spawned
void AseaSawPlank::BeginPlay()
{
	Super::BeginPlay();


	if (((int)(FMath::FRandRange(1, 100))) % 10 == 0) {
		if (((int)(FMath::FRandRange(1, 100))) % 2 == 0) {
			block1->SetRelativeLocation(FVector(0, 0, 200));
			block2->SetRelativeLocation(FVector(0, 0, 400));
		}
		else {

		}
	}
	
}

// Called every frame
void AseaSawPlank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

