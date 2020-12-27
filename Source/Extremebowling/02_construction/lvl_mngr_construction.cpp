// Fill out your copyright notice in the Description page of Project Settings.


#include "lvl_mngr_construction.h"
#include "../essential/kusaGameInstance.h"

// Sets default values
Alvl_mngr_construction::Alvl_mngr_construction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Alvl_mngr_construction::BeginPlay()
{
	Super::BeginPlay();
	initBlocks();
	
}

// Called every frame
void Alvl_mngr_construction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UkusaGameInstance* gameInst = Cast<UkusaGameInstance>(GetGameInstance());
	int playerPosX = gameInst->playerPos;



	if (playerPosX >= next_Milestone) {
		UpdateLevel();
	}

}

void Alvl_mngr_construction::initBlocks() {

	init_block = true;
	for (int i = 0; i < 20; i++) {
		CreateLevelBlock();
		if (i == 9) {
			next_Milestone = xpos;

		}if (i == 5) {
			start = false;
		}

	}

	init_block = false;

}

void Alvl_mngr_construction::popBlock() {

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

void Alvl_mngr_construction::UpdateLevel() {

	//next_Milestone += 1000;

	CreateLevelBlock();
	popBlock();

}


void Alvl_mngr_construction :: CreateLevelBlock() {
	FActorSpawnParameters spawnPara;
	spawnPara.Owner = this;

	TArray<AActor*> blocks;

	UWorld* world = GetWorld();

	int y_sz = 10;

	if (!hasNext) {
		wToSelect = (int)FMath::FRandRange(1, 15);
		//wToSelect = 503;
	}
	hasNext = false;

	if (start)
		wToSelect = -10;

	//1 to   is for random blocks in plane surface
	if (wToSelect == 1) {
		//world->Spawn
	}


	//---------temp
	next_Milestone += 2000;
	if (block) {
		AActor* floor = world->SpawnActor<AActor>(block, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
		blocks.Push(floor);
	}
	xpos += 2000;






	if (init_block)
		next_Milestone -= 1000;

	LB_array.Enqueue(blocks);

}

