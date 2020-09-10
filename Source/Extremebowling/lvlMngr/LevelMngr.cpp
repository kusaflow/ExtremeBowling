// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelMngr.h"
#include "../essential/kusaGameInstance.h"

// Sets default values
ALevelMngr::ALevelMngr()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelMngr::BeginPlay()
{
	Super::BeginPlay();
	initBlocks();
	
}

// Called every frame
void ALevelMngr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
	int playerPosX = gameInst->playerPos;



	if (playerPosX >= next_Milestone) {
		UpdateLevel();
	}

}


void ALevelMngr::initBlocks() {

	init_block = true;
	for (int i = 0; i < 10; i++) {
		CreateLevelBlock();
		if (i == 2) {
			next_Milestone = xpos;

		}if (i == 5) {
			start = false;
		}

	}

	init_block = false;

}


void ALevelMngr::popBlock() {

	if (LB_array.IsEmpty()) {
		return;
	}
	TArray<AActor*> rem;
	LB_array.Peek(rem);
	LB_array.Pop();
	//UE_LOG(LogTemp, Warning, TEXT("%d"), rem.Num());
	if (rem.Num() >= 0) {
		while (rem.Num() != 0) {
			AActor* toDest = rem.Pop();
			if (toDest) {
				toDest->Destroy();
			}
		}
	}


}

void ALevelMngr::UpdateLevel() {

	//next_Milestone += 1000;

	CreateLevelBlock();
	popBlock();

}

void ALevelMngr::CreateLevelBlock() {

	FActorSpawnParameters spawnPara;
	spawnPara.Owner = this;

	TArray<AActor*> blocks;

	UWorld* world = GetWorld();

	int y_sz = 10;

	int wToSelect = 10;

	if (!hasNext) {
		//wToSelect = (int)FMath::FRandRange(1, 4);
	}
	hasNext = false;

	if (start)
		wToSelect = 10;

	if (wToSelect == 1) {

	}
	else {
		next_Milestone += 1000;
		if (Base_Track) {
			AActor* floor = world->SpawnActor<AActor>(Base_Track, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
			blocks.Push(floor);
		}
		xpos += 1000;
	}


	if (init_block)
		next_Milestone -= 1000;

	LB_array.Enqueue(blocks);
}
