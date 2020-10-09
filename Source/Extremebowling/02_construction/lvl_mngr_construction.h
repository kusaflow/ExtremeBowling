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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
