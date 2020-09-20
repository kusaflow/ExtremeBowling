// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelMngr.generated.h"

UCLASS()
class EXTREMEBOWLING_API ALevelMngr : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelMngr();

	TQueue<TArray<AActor*>> LB_array;

	UPROPERTY(BlueprintReadOnly, Category = "kusavar")
		int next_Milestone;

	int xpos = -500000;

	bool start = true, init_block = true, hasNext = false;

	int Sat = 1;
	bool isCurvedPlatform = true;


	int wToSelect = 400;



	//kusaMesh-------------------------------------------------
	UPROPERTY(EditDefaultsOnly, category = "kusa_Meshes")
		TSubclassOf<class AActor> L1_Base_Track;

	UPROPERTY(EditDefaultsOnly, category = "kusa_Meshes")
		TSubclassOf<class AActor> L1_B_1;

	UPROPERTY(EditDefaultsOnly, category = "kusa_Meshes")
		TSubclassOf<class AActor> L1_B_2;

	UPROPERTY(EditDefaultsOnly, category = "kusa_Meshes")
		TSubclassOf<class AActor> L1_B_3;

	UPROPERTY(EditDefaultsOnly, category = "kusa_Meshes")
		TSubclassOf<class AActor> L1_B_4;

	UPROPERTY(EditDefaultsOnly, category = "kusa_Meshes")
		TSubclassOf<class AActor> L1_B_5;

	UPROPERTY(EditDefaultsOnly, category = "kusa_Meshes")
		TSubclassOf<class AActor> L1_B_6;
	
	UPROPERTY(EditDefaultsOnly, category = "kusa_Meshes")
		TSubclassOf<class AActor> L1_B_7;

	UPROPERTY(EditDefaultsOnly, category = "kusa_Meshes")
		TSubclassOf<class Ablock_9> satuM;


	UPROPERTY(EditDefaultsOnly, category = "kusa_Meshes")
		TSubclassOf<class AActor> plane;

	//powerUp
	UPROPERTY(EditDefaultsOnly, category = "kusa_Power")
		TSubclassOf<class AActor> P_speedUp;

	UPROPERTY(EditDefaultsOnly, category = "kusa_Power")
		TSubclassOf<class AActor> P_slowDown;




protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void UpdateLevel();

	void initBlocks();

	void CreateLevelBlock();

	void popBlock();

};

