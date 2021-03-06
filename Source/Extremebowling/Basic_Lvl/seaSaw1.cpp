// Fill out your copyright notice in the Description page of Project Settings.


#include "seaSaw1.h"
#include "seaSawPlank.h"
#include "Components/BoxComponent.h"
#include "../char/C_mainChar.h"

// Sets default values
AseaSaw1::AseaSaw1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bar = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("bar"));
	RootComponent = bar;

	Camera_Manupulator = CreateDefaultSubobject<UBoxComponent>(TEXT("cameraManupulatorBox"));
	Camera_Manupulator->SetupAttachment(bar);

	bar->SetWorldScale3D(FVector(40, 0.4, 0.7));

}

// Called when the game starts or when spawned
void AseaSaw1::BeginPlay()
{
	Super::BeginPlay();
	FActorSpawnParameters spawnPara;
	spawnPara.Owner = this;

	Camera_Manupulator->OnComponentBeginOverlap.AddDynamic(this, &AseaSaw1::OnOverlapBegin);

	int xpos = bar->GetComponentLocation().X - 3750;
	for (int i = 0; i < 10; i++) {
		AseaSawPlank* aa = GetWorld()->SpawnActor<AseaSawPlank>(planks, FVector(xpos, 0, 0), FRotator(0), spawnPara);
		xpos += 200*2;
		xpos += 50;
	}
	
}

// Called every frame
void AseaSaw1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AseaSaw1::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
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