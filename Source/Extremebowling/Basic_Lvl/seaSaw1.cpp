// Fill out your copyright notice in the Description page of Project Settings.


#include "seaSaw1.h"
#include "seaSawPlank.h"

// Sets default values
AseaSaw1::AseaSaw1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bar = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("bar"));
	RootComponent = bar;

	bar->SetWorldScale3D(FVector(40, 0.4, 0.7));

}

// Called when the game starts or when spawned
void AseaSaw1::BeginPlay()
{
	Super::BeginPlay();
	FActorSpawnParameters spawnPara;
	spawnPara.Owner = this;
	int xpos = bar->GetComponentLocation().X;
	for (int i = 0; i < 10; i++) {
		AseaSawPlank* aa = GetWorld()->SpawnActor<AseaSawPlank>(planks, FVector(xpos, 0, 0), FRotator(0), spawnPara);
		xpos += 300;
	}
	
}

// Called every frame
void AseaSaw1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

