// Fill out your copyright notice in the Description page of Project Settings.


#include "block_9.h"

// Sets default values
Ablock_9::Ablock_9()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh1"));
	mesh1->SetupAttachment(RootComponent);
	
	mesh2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh2"));
	mesh2->SetupAttachment(RootComponent);

	mesh3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh3"));
	mesh3->SetupAttachment(RootComponent);

	mesh4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh4"));
	mesh4->SetupAttachment(RootComponent);

	mesh5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh5"));
	mesh5->SetupAttachment(RootComponent);

	mesh6 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh6"));
	mesh6->SetupAttachment(RootComponent);

	mesh7 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh7"));
	mesh7->SetupAttachment(RootComponent);

	mesh8 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh8"));
	mesh8->SetupAttachment(RootComponent);

	mesh9 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mesh9"));
	mesh9->SetupAttachment(RootComponent);






}

// Called when the game starts or when spawned
void Ablock_9::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Ablock_9::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void Ablock_9::reArrange(int trans, float Xpos) {
	if (trans == 1) {
		mesh1->SetRelativeLocation(FVector(Xpos, 0, 20));
		mesh1->SetRelativeRotation(FRotator(0));

		mesh2->SetRelativeLocation(FVector(Xpos,587.844421,48.936539));
		mesh2->SetRelativeRotation(FRotator(0, 0, -10));

		mesh3->SetRelativeLocation(FVector(Xpos, 1148.723999, 231.934143));
		mesh3->SetRelativeRotation(FRotator(0, 0, -25));

		mesh4->SetRelativeLocation(FVector(Xpos,1642.204468,552.957947));
		mesh4->SetRelativeRotation(FRotator(0, 0, -40));

		mesh5->SetRelativeLocation(FVector(Xpos,2009.443726,1007.155518));
		mesh5->SetRelativeRotation(FRotator(0, 0, -60));
		///================================================================================================
		mesh6->SetRelativeLocation(FVector(Xpos, -587.844421, 48.936539));
		mesh6->SetRelativeRotation(FRotator(0, 0, 10));

		mesh7->SetRelativeLocation(FVector(Xpos, -1148.723999, 231.934143));
		mesh7->SetRelativeRotation(FRotator(0, 0, 25));

		mesh8->SetRelativeLocation(FVector(Xpos, -1642.204468, 552.957947));
		mesh8->SetRelativeRotation(FRotator(0, 0, 40));

		mesh9->SetRelativeLocation(FVector(Xpos, -2009.443726, 1007.155518));
		mesh9->SetRelativeRotation(FRotator(0, 0, 60));

	}

	else if (trans == 2) {
		mesh1->SetRelativeLocation(FVector(Xpos, 0, 20));
		mesh1->SetRelativeRotation(FRotator(0));

		mesh2->SetRelativeLocation(FVector(Xpos, 587.844421, 48.936539));
		mesh2->SetRelativeRotation(FRotator(0, 0, -10));

		mesh3->SetRelativeLocation(FVector(Xpos, 1156.370361, 213.474136));
		mesh3->SetRelativeRotation(FRotator(0, 0, -20));

		mesh4->SetRelativeLocation(FVector(Xpos, 1691.430664, 465.952454));
		mesh4->SetRelativeRotation(FRotator(0, 0, -30));

		mesh5->SetRelativeLocation(FVector(Xpos, 2131.88208, 833.232727));
		mesh5->SetRelativeRotation(FRotator(0, 0, -50));
		///================================================================================================
		mesh6->SetRelativeLocation(FVector(Xpos, -587.844421, 48.936539));
		mesh6->SetRelativeRotation(FRotator(0, 0, 10));

		mesh7->SetRelativeLocation(FVector(Xpos, -1156.370361, 213.474136));
		mesh7->SetRelativeRotation(FRotator(0, 0, 20));

		mesh8->SetRelativeLocation(FVector(Xpos, -1691.430664, 465.952454));
		mesh8->SetRelativeRotation(FRotator(0, 0, 30));

		mesh9->SetRelativeLocation(FVector(Xpos, -2131.88208, 833.232727));
		mesh9->SetRelativeRotation(FRotator(0, 0, 50));
	}
	else if (trans == 3) {
		mesh1->SetRelativeLocation(FVector(Xpos, 0, 20));
		mesh1->SetRelativeRotation(FRotator(0));

		mesh1->SetRelativeLocation(FVector(Xpos, 587.844421, 48.936539));
		mesh1->SetRelativeRotation(FRotator(0, 0, 8));

		mesh2->SetRelativeLocation(FVector(Xpos, 1166.7229, 174.837112));
		mesh2->SetRelativeRotation(FRotator(0, 0, 15));

		mesh3->SetRelativeLocation(FVector(Xpos, 1729.05249, 362.586426));
		mesh3->SetRelativeRotation(FRotator(0, 0, 20));

		mesh4->SetRelativeLocation(FVector(Xpos, 2247.421143, 633.356018));
		mesh4->SetRelativeRotation(FRotator(0, 0, 35));
		///================================================================================================
		mesh6->SetRelativeLocation(FVector(Xpos, -587.844421, 48.936539));
		mesh6->SetRelativeRotation(FRotator(0, 0, 8));

		mesh7->SetRelativeLocation(FVector(Xpos, -1166.7229, 174.837112));
		mesh7->SetRelativeRotation(FRotator(0, 0, 15));

		mesh8->SetRelativeLocation(FVector(Xpos, -1729.05249, 362.586426));
		mesh8->SetRelativeRotation(FRotator(0, 0, 20));

		mesh9->SetRelativeLocation(FVector(Xpos, -2247.421143, 633.356018));
		mesh9->SetRelativeRotation(FRotator(0, 0, 35));
	}
	else if (trans == 4) {
		mesh1->SetRelativeLocation(FVector(Xpos, 0, 20));
		mesh1->SetRelativeRotation(FRotator(0));

		mesh1->SetRelativeLocation(FVector(Xpos, 587.844421, 48.936539));
		mesh1->SetRelativeRotation(FRotator(0, 0, 8));

		mesh2->SetRelativeLocation(FVector(Xpos, 1166.7229, 174.837112));
		mesh2->SetRelativeRotation(FRotator(0, 0, 15));

		mesh3->SetRelativeLocation(FVector(Xpos, 1729.05249, 362.586426));
		mesh3->SetRelativeRotation(FRotator(0, 0, 20));

		mesh4->SetRelativeLocation(FVector(Xpos, 2247.421143, 633.356018));
		mesh4->SetRelativeRotation(FRotator(0, 0, 35));
		///================================================================================================
		mesh6->SetRelativeLocation(FVector(Xpos, -589.587585, 29.012642));
		mesh6->SetRelativeRotation(FRotator(0, 0, 5));

		mesh7->SetRelativeLocation(FVector(Xpos, -1177.141602, 115.748611));
		mesh7->SetRelativeRotation(FRotator(0, 0, 10));

		mesh8->SetRelativeLocation(FVector(Xpos, -1760.110229, 246.675201));
		mesh8->SetRelativeRotation(FRotator(0, 0, 15));

		mesh9->SetRelativeLocation(FVector(Xpos, -2319.244629, 436.020844));
		mesh9->SetRelativeRotation(FRotator(0, 0, 20));
	}
	else if (trans == 5) {
		mesh1->SetRelativeLocation(FVector(Xpos, 0, 20));
		mesh1->SetRelativeRotation(FRotator(0));

		mesh1->SetRelativeLocation(FVector(Xpos, 587.844421, 48.936539));
		mesh1->SetRelativeRotation(FRotator(0, 0, 8));

		mesh2->SetRelativeLocation(FVector(Xpos, 1166.7229, 174.837112));
		mesh2->SetRelativeRotation(FRotator(0, 0, 15));

		mesh3->SetRelativeLocation(FVector(Xpos, 1729.05249, 362.586426));
		mesh3->SetRelativeRotation(FRotator(0, 0, 20));

		mesh4->SetRelativeLocation(FVector(Xpos, 2247.421143, 633.356018));
		mesh4->SetRelativeRotation(FRotator(0, 0, 35));
		///================================================================================================
		mesh6->SetRelativeLocation(FVector(Xpos, -589.936584, 19.018734));
		mesh6->SetRelativeRotation(FRotator(0, 0, 2));

		mesh7->SetRelativeLocation(FVector(Xpos, -1183.759766, 56.122879));
		mesh7->SetRelativeRotation(FRotator(0, 0, 5));

		mesh8->SetRelativeLocation(FVector(Xpos, -1771.26355, 127.204834));
		mesh8->SetRelativeRotation(FRotator(0, 0, 7));

		mesh9->SetRelativeLocation(FVector(Xpos, -2357.44873, 219.363007));
		mesh9->SetRelativeRotation(FRotator(0, 0, 10));
	}
	else if (trans == 6) {
		mesh1->SetRelativeLocation(FVector(Xpos, 0, 20));
		mesh1->SetRelativeRotation(FRotator(0));

		mesh1->SetRelativeLocation(FVector(Xpos, 600, 0));
		mesh1->SetRelativeRotation(FRotator(0, 0, 0));

		mesh2->SetRelativeLocation(FVector(Xpos, 1200, 0));
		mesh2->SetRelativeRotation(FRotator(0, 0, 0));

		mesh3->SetRelativeLocation(FVector(Xpos, 1800, 0));
		mesh3->SetRelativeRotation(FRotator(0, 0, 0));

		mesh4->SetRelativeLocation(FVector(Xpos, 2400, 0));
		mesh4->SetRelativeRotation(FRotator(0, 0, 0));
		///================================================================================================
		mesh6->SetRelativeLocation(FVector(Xpos, -600, 0));
		mesh6->SetRelativeRotation(FRotator(0, 0, 0));

		mesh7->SetRelativeLocation(FVector(Xpos, -1200, 0));
		mesh7->SetRelativeRotation(FRotator(0, 0, 0));

		mesh8->SetRelativeLocation(FVector(Xpos, -1800, 0));
		mesh8->SetRelativeRotation(FRotator(0, 0, 0));

		mesh9->SetRelativeLocation(FVector(Xpos, -2400, 0));
		mesh9->SetRelativeRotation(FRotator(0, 0, 0));
	}

}

