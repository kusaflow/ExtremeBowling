// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "lvl_mngr_construction.generated.h"

UCLASS()
class EXTREMEBOWLING_API Alvl_mngr_construction : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Alvl_mngr_construction();

	TQueue<TArray<AActor*>> LB_array;

	UPROPERTY(BlueprintReadOnly, Category = "kusavar")
		int next_Milestone;

	int xpos = -500000;

	bool start = true, init_block = true, hasNext = false;

	int wToSelect = 400;
	int backUp_wToSelect = 0;

	//---------blocks=====================
	UPROPERTY(EditDefaultsOnly, category = "tempBlocks")
		TSubclassOf<class AActor> block;

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
