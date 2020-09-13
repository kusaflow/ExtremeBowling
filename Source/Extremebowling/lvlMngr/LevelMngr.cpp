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
		wToSelect = (int)FMath::FRandRange(1, 20);
	}
	hasNext = false;

	if (start)
		wToSelect = 10;

	//powerUp
	if ((int)(FMath::FRandRange(1, 100)) % 5 == 0) {
		int powerUp = (int)(FMath::FRandRange(1, 5));
		int yLocPower = FMath::FRandRange(-1800, 1800);
		if (powerUp == 1 && P_speedUp) {
			AActor* power = world->SpawnActor<AActor>(P_speedUp, FVector(xpos + 500, yLocPower, 1300), FRotator(0), spawnPara);
			blocks.Push(power);
		}
		else if (powerUp == 2 && P_slowDown) {
			AActor* power = world->SpawnActor<AActor>(P_slowDown, FVector(xpos + 500, yLocPower, 1300), FRotator(0), spawnPara);
			blocks.Push(power);
		}


	}

	if (wToSelect == 1) {
		next_Milestone += 1000;
		if (L1_B_1) {
			AActor* floor = world->SpawnActor<AActor>(L1_B_1, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
			blocks.Push(floor);
		}
		xpos += 1000;
	}
	else if (wToSelect == 2) {
		next_Milestone += 1000;
		if (L1_B_2) {
			AActor* floor = world->SpawnActor<AActor>(L1_B_2, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
			blocks.Push(floor);
		}
		xpos += 1000;
	}
	else if (wToSelect == 3) {
		next_Milestone += 1000;
		if (L1_B_3) {
			AActor* floor = world->SpawnActor<AActor>(L1_B_3, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
			blocks.Push(floor);
		}
		xpos += 1000;
	}
	else if (wToSelect == 4) {
		next_Milestone += 1000;
		if (L1_B_4) {
			AActor* floor = world->SpawnActor<AActor>(L1_B_4, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
			blocks.Push(floor);
		}
		xpos += 1000;
	}
	else if (wToSelect == 5) {
		next_Milestone += 1000;
		if (L1_B_5) {
			AActor* floor = world->SpawnActor<AActor>(L1_B_5, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
			blocks.Push(floor);
		}
		xpos += 1000;
	}
	else if (wToSelect == 6) {
		next_Milestone += 1000;
		if (L1_B_6) {
			AActor* floor = world->SpawnActor<AActor>(L1_B_6, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
			blocks.Push(floor);
		}
		xpos += 1000;
	}
	else if (wToSelect == 7) {
		next_Milestone += 1000;
		if (L1_B_7) {
			AActor* floor = world->SpawnActor<AActor>(L1_B_7, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
			blocks.Push(floor);
		}
		xpos += 1000;
	}
	///--------------------------------------------------------------------
	else {
		next_Milestone += 1000;
		if (L1_Base_Track) {
			AActor* floor = world->SpawnActor<AActor>(L1_Base_Track, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
			blocks.Push(floor);
		}
		xpos += 1000;
	}


	if (init_block)
		next_Milestone -= 1000;

	LB_array.Enqueue(blocks);
}
