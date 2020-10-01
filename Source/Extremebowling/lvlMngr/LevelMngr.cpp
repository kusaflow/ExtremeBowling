// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelMngr.h"
#include "../essential/kusaGameInstance.h"
#include "../Basic_Lvl/block_9.h"
#include "../Basic_Lvl/RollingBallDown.h"
#include "../Basic_Lvl/move_leftRight.h"

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

	//saturation from Bevel To straight is 300
	//saturation from straight to Bevel is 301
	//saturation from straight to Bevel is 500

	//helper starts from 1000

	//bowling from staright path and covers starts from 400




	if (!hasNext) {
		//wToSelect = (int)FMath::FRandRange(1, 20);
		wToSelect = 502;
	}
	hasNext = false;

	if (start)
		wToSelect = -10;

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

	//saturation
	//if ()

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
	///----------------------Saturation-----------------------------------------------------------------
	else if (wToSelect == 300) {
		if (Sat >= 10)
			Sat = 10;

		next_Milestone += 1000;
		if (satuM) {
			Ablock_9* floor = world->SpawnActor<Ablock_9>(satuM, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
			floor->reArrange(Sat++, xpos + 500);
			blocks.Push(floor);
		}
		xpos += 1000;
	}
	else if (wToSelect == 301) {
		if (Sat < 0)
			Sat = 0;

		next_Milestone += 1000;
		if (satuM) {
			Ablock_9* floor = world->SpawnActor<Ablock_9>(satuM, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
			floor->reArrange(Sat--, xpos + 500);
			blocks.Push(floor);
		}
		xpos += 1000;
	}
	//=========saturatio end ====================================================================================
	//400-------------------------------------------------------------------------------------------
	else if (wToSelect == 400) {
		hasNext = true;
		wToSelect = 401;
		next_Milestone += 10*200;
		if (plane) {
			AActor* floor = world->SpawnActor<AActor>(plane, FVector(xpos + 
				((10*200)/2), 0, 0), FRotator(0), spawnPara);
			floor->SetActorScale3D(FVector(10,27,1));
			blocks.Push(floor);
		}
		xpos += 10*200;

	}
	else if (wToSelect == 401) {
		hasNext = true;
		wToSelect = 402;
		next_Milestone += 10 * 200;
		if (plane) {
			AActor* floor = world->SpawnActor<AActor>(plane, FVector(xpos +
				((10 * 200) / 2), -1800, 0), FRotator(0), spawnPara);
			floor->SetActorScale3D(FVector(10, 9, 1));
			blocks.Push(floor);

			AActor* f2 = world->SpawnActor<AActor>(plane, FVector(xpos +
				((10 * 200) / 2), 1800, 0), FRotator(0), spawnPara);
			f2->SetActorScale3D(FVector(10, 9, 1));
			blocks.Push(f2);

			AActor* f3 = world->SpawnActor<AActor>(plane, FVector(xpos +
				((10 * 200) / 2)-(9*200), 0, -10), FRotator(15,0,0), spawnPara);
			f3->SetActorScale3D(FVector(8, 6, 3));
			blocks.Push(f3);
		}
		xpos += 10 * 200;

	}
	else if (wToSelect == 402) {
		hasNext = true;
		wToSelect = 403;
		next_Milestone += 10 * 200;
		if (plane) {
			AActor* floor = world->SpawnActor<AActor>(plane, FVector(xpos +
				((10 * 200) / 2), 0, 0), FRotator(0), spawnPara);
			floor->SetActorScale3D(FVector(10, 27, 1));
			blocks.Push(floor);
		}
		xpos += 10 * 200;
	}
	else if (wToSelect == 403) {
		hasNext = true;
		wToSelect = 404;
		next_Milestone += 40 * 200;
		if (rollingBall) {
			ARollingBallDown* floor = world->SpawnActor<ARollingBallDown>(rollingBall, FVector(xpos +
				((40 * 200) / 2), 0, 0), FRotator(0), spawnPara);
			floor->SetActorScale3D(FVector(1, 1, 1));
			blocks.Push(floor);
		}
		xpos += 40 * 200;
	}
	//400 ens=================================================================================
	else if (wToSelect == 500) {
		hasNext = true;
		wToSelect = 999;
		int sB = 40;
		next_Milestone += sB * 200;
		if (seaSaw1) {
			AActor* floor = world->SpawnActor<AActor>(seaSaw1, FVector(xpos +
				((sB * 200) / 2), 0, 0), FRotator(0), spawnPara);
			blocks.Push(floor);
		}
		xpos += 40 * 200;
	}
	else if (wToSelect == 501) {
		hasNext = true;
		wToSelect = 999;
		int len  = ((int)(FMath::FRandRange(3,11)));
		int sB = 5 * len;

		if (moveB1) {
			for (int i = 0; i < len; i++) {
				Amove_leftRight* floor = world->SpawnActor<Amove_leftRight>(moveB1, FVector(xpos +
					((5 * 200) / 2), 0, 0), FRotator(0), spawnPara);
				floor->setUp(false, false, false, false);
				blocks.Push(floor);
				xpos += (5 * 200);
			}
		}

		next_Milestone += sB * 200;
	}
	// plus rotation ===================================
	else if (wToSelect == 502) {
		hasNext = true;
		wToSelect = 150201;
		next_Milestone += 1000;
		if (satuM) {
			Ablock_9* floor = world->SpawnActor<Ablock_9>(satuM, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
			floor->reArrange(10, xpos + 500);
			floor->YRoatation(12);
			floor->Zpos(100);
			floor->destroyBox();
			blocks.Push(floor);
		}
		xpos += 1000;
	}
	//helper for pluss(1 for heper ,502 helping for,01 helpernumber)
	else if (wToSelect == 150201) {
		hasNext = true;
		wToSelect = 150202;
		next_Milestone += 900;
		if (satuM) {
			Ablock_9* floor = world->SpawnActor<Ablock_9>(satuM, FVector(xpos + 450, 0, 0), FRotator(0), spawnPara);
			floor->reArrange(10, xpos + 450);
			floor->YRoatation(15);
			floor->Zpos(320.0);
			floor->destroyBox();
			blocks.Push(floor);
		}
		xpos += 900;
	}
	else if (wToSelect == 150202) {
		hasNext = true;
		wToSelect = 150203;
		next_Milestone += 1000;
		if (satuM) {
			Ablock_9* floor = world->SpawnActor<Ablock_9>(satuM, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
			floor->reArrange(10, xpos + 500);
			floor->Zpos(440.0);
			floor->destroyBox();
			blocks.Push(floor);
		}
		xpos += 1000;
	}
	//mainWheel
	else if (wToSelect == 150203) {
		hasNext = true;
		wToSelect = 150204;
		int sb = 35;

		if (plusRot) {
			AActor* floor = world->SpawnActor<AActor>(plusRot, FVector(xpos +
				((sb * 200) / 2), 0, 0), FRotator(0), spawnPara);

			blocks.Push(floor);
		}

		next_Milestone += sb * 200;
		xpos += (sb+1) * 200;
	}
	else if (wToSelect == 150204) {
		hasNext = true;
		wToSelect = 150205;
		next_Milestone += 900;
		if (satuM) {
			Ablock_9* floor = world->SpawnActor<Ablock_9>(satuM, FVector(xpos + 450, 0, 0), FRotator(0), spawnPara);
			floor->reArrange(10, xpos + 450);
			floor->Zpos(-420);
			floor->destroyBox();
			blocks.Push(floor);
		}
		xpos += 900;
	}
	else if (wToSelect == 150205) {
		hasNext = true;
		wToSelect = 150206;
		next_Milestone += 900;
		if (satuM) {
			Ablock_9* floor = world->SpawnActor<Ablock_9>(satuM, FVector(xpos + 450, 0, 0), FRotator(0), spawnPara);
			floor->reArrange(10, xpos + 450);
			floor->YRoatation(20);
			floor->Zpos(-270);
			blocks.Push(floor);
		}
		xpos += 900;
	}
	else if (wToSelect == 150206) {
		hasNext = true;
		wToSelect = 999;
		next_Milestone += 1000;
		if (satuM) {
			Ablock_9* floor = world->SpawnActor<Ablock_9>(satuM, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
			floor->reArrange(10, xpos + 500);
			floor->YRoatation(10);
			floor->Zpos(-20);
			blocks.Push(floor);
		}
		xpos += 1000;
	}
	///--------------------------------------------------------------------
	else {
		next_Milestone += 1000;
		if (satuM) {
			Ablock_9* floor = world->SpawnActor<Ablock_9>(satuM, FVector(xpos + 500, 0, 0), FRotator(0), spawnPara);
			floor->reArrange(isCurvedPlatform ? 1 : 10, xpos + 500);
			blocks.Push(floor);
		}
		xpos += 1000;
	}


	if (init_block)
		next_Milestone -= 1000;

	LB_array.Enqueue(blocks);
}
