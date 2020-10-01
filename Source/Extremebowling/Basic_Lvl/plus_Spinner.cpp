// Fill out your copyright notice in the Description page of Project Settings.


#include "plus_Spinner.h"
#include "Components/BoxComponent.h"
#include "../char/C_mainChar.h"

// Sets default values
Aplus_Spinner::Aplus_Spinner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	plane = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("bar"));
	RootComponent = plane;

	Camera_Manupulator = CreateDefaultSubobject<UBoxComponent>(TEXT("cameraManupulatorBox"));
	Camera_Manupulator->SetupAttachment(plane);

	plane->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void Aplus_Spinner::BeginPlay()
{
	Super::BeginPlay();
	
	//plane->AddRelativeLocation(FVector(0, 0, -70));
	Camera_Manupulator->OnComponentBeginOverlap.AddDynamic(this, &Aplus_Spinner::OnOverlapBegin);

	
}

// Called every frame
void Aplus_Spinner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Aplus_Spinner::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AC_mainChar* mainC = Cast<AC_mainChar>(OtherActor);

	if (mainC) {

		mainC->boom_predicted_length = 1500;
		mainC->boom_predicted_Rot = FRotator(315, 0, 0);
		//mainC->camera_predicted_Rot = FRotator(15, 0, 0);
		Camera_Manupulator->DestroyComponent();
	}


}

