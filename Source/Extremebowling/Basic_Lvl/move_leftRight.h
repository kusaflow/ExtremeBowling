// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "move_leftRight.generated.h"

UCLASS()
class EXTREMEBOWLING_API Amove_leftRight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Amove_leftRight();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* plane;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* Camera_Manupulator;


	float ypos, zpos;
	bool inpos = true;

	bool moveInY = true;

	float speed = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void setUp(bool Vsize, bool isInY, bool Rypos, bool Rzpos);


	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
