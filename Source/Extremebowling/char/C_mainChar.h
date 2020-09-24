// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "C_mainChar.generated.h"

UCLASS()
class EXTREMEBOWLING_API AC_mainChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AC_mainChar();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* sphere;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = mesh, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* wheel;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* cameraBoom;

	/* main camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;


	bool brakeOn = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		void Movement(float val);

	UFUNCTION(BlueprintCallable)
		void brake_F(float val);

};
