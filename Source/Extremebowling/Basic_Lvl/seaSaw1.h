// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "seaSaw1.generated.h"

UCLASS()
class EXTREMEBOWLING_API AseaSaw1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AseaSaw1();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* bar;

	UPROPERTY(EditDefaultsOnly, category = "planks")
		TSubclassOf<class AseaSawPlank> planks;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* Camera_Manupulator;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
			class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
