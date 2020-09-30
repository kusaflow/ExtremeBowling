// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "block_9.generated.h"

UCLASS()
class EXTREMEBOWLING_API Ablock_9 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Ablock_9();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* mesh1;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* mesh2;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* mesh3;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* mesh4;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* mesh5;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* mesh6;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* mesh7;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* mesh8;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* mesh9;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* Camera_Manupulator;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void reArrange(int trans, float Xpos);

	void YRoatation(float RotInY);
	void Zpos(float val);

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, 
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
