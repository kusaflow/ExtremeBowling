// Fill out your copyright notice in the Description page of Project Settings.


#include "move_leftRight.h"
#include "Components/BoxComponent.h"
#include "../char/C_mainChar.h"

// Sets default values
Amove_leftRight::Amove_leftRight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("bar"));
	RootComponent = plane;
	plane->SetWorldScale3D(FVector(5, 8, 1));

	Camera_Manupulator = CreateDefaultSubobject<UBoxComponent>(TEXT("cameraManupulatorBox"));
	Camera_Manupulator->SetupAttachment(RootComponent);

	ypos = 500;
	zpos = 500;
	
	speed = FMath::FRandRange(100,1000);

}

// Called when the game starts or when spawned
void Amove_leftRight::BeginPlay()
{
	Super::BeginPlay();

	Camera_Manupulator->OnComponentBeginOverlap.AddDynamic(this, &Amove_leftRight::OnOverlapBegin);

	
}

// Called every frame
void Amove_leftRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (inpos) {
		RootComponent->AddRelativeLocation(FVector(0, moveInY ? speed*DeltaTime : 0, moveInY ? 0 : speed * DeltaTime));
		if (moveInY ? RootComponent->GetComponentLocation().Y >= ypos : RootComponent->GetComponentLocation().Z >= zpos) {
			inpos = false;
		}
	}
	else {
		RootComponent->AddRelativeLocation(FVector(0, moveInY ? -1 * speed * DeltaTime : 0, moveInY ? 0 : -1 * speed * DeltaTime));
		if (moveInY ? RootComponent->GetComponentLocation().Y <= ypos*-1 : RootComponent->GetComponentLocation().Z <= zpos*-1) {
			inpos = true;
		}
	}

}

void Amove_leftRight :: setUp(bool Vsize, bool isInY, bool Rypos, bool Rzpos) {
	if (Vsize) {

	}

	moveInY = isInY;

	if (isInY) {
		zpos = 0;
	}
	else {
		ypos = 0;
	}
}

void Amove_leftRight::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AC_mainChar* mainC = Cast<AC_mainChar>(OtherActor);

	if (mainC) {

		mainC->boom_predicted_length = 1200;
		mainC->boom_predicted_Rot = FRotator(340, 0, 0);
		mainC->camera_predicted_Rot = FRotator(15, 0, 0);
		Camera_Manupulator->DestroyComponent();
	}


}
