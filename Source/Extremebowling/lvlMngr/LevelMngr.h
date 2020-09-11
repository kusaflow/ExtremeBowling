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


	//kusaMesh-------------------------------------------------
	UPROPERTY(EditDefaultsOnly, category = "kusa_Meshes")
		TSubclassOf<class AActor> Base_Track;

	UPROPERTY(EditDefaultsOnly, category = "kusa_Meshes")
		TSubclassOf<class AActor> B_obs_1;

	UPROPERTY(EditDefaultsOnly, category = "kusa_Meshes")
		TSubclassOf<class AActor> B_obs_2;

	UPROPERTY(EditDefaultsOnly, category = "kusa_Meshes")
		TSubclassOf<class AActor> B_obs_3;

	UPROPERTY(EditDefaultsOnly, category = "kusa_Meshes")
		TSubclassOf<class AActor> B_obs_4;

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

