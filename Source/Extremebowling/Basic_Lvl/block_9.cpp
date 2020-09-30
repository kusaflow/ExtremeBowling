// Fill out your copyright notice in the Description page of Project Settings.


#include "block_9.h"
#include "Components/BoxComponent.h"
#include "../char/C_mainChar.h"

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

	Camera_Manupulator = CreateDefaultSubobject<UBoxComponent>(TEXT("cameraManupulatorBox"));
	Camera_Manupulator->SetupAttachment(RootComponent);






}

// Called when the game starts or when spawned
void Ablock_9::BeginPlay()
{
	Super::BeginPlay();

	Camera_Manupulator->OnComponentBeginOverlap.AddDynamic(this, &Ablock_9::OnOverlapBegin);
	
}

// Called every frame
void Ablock_9::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Ablock_9::reArrange(int trans, float Xpos) {
	mesh1->SetRelativeLocation(FVector(Xpos, 0, 20));
	mesh1->SetRelativeRotation(FRotator(0));

	Camera_Manupulator->SetRelativeLocation(FVector(Xpos, 0, 0));

	if (trans == 1) {
		mesh2->SetRelativeLocation(FVector(Xpos, -587.844421, 68.936539));
		mesh2->SetRelativeRotation(FRotator(0, 0, 9));

		mesh3->SetRelativeLocation(FVector(Xpos, -1156.776978, 233.632263));
		mesh3->SetRelativeRotation(FRotator(0, 0, 22.5));

		mesh4->SetRelativeLocation(FVector(Xpos, -1669.941895, 531.534241));
		mesh4->SetRelativeRotation(FRotator(0, 0, 36));

		mesh5->SetRelativeLocation(FVector(Xpos, -2086.937256, 952.364014));
		mesh5->SetRelativeRotation(FRotator(0, 0, 54));
		///================================================================================================
		mesh6->SetRelativeLocation(FVector(Xpos, 587.844421, 68.936539));
		mesh6->SetRelativeRotation(FRotator(0, 0, -9));

		mesh7->SetRelativeLocation(FVector(Xpos, 1156.776978, 233.632263));
		mesh7->SetRelativeRotation(FRotator(0, 0, -22.5));

		mesh8->SetRelativeLocation(FVector(Xpos, 1669.941895, 531.534241));
		mesh8->SetRelativeRotation(FRotator(0, 0, -36));

		mesh9->SetRelativeLocation(FVector(Xpos, 2086.937256, 952.364014));
		mesh9->SetRelativeRotation(FRotator(0, 0, -54));
	}
	else if (trans == 2) {
		mesh2->SetRelativeLocation(FVector(Xpos, -587.844421, 68.936539));
		mesh2->SetRelativeRotation(FRotator(0, 0, 8));

		mesh3->SetRelativeLocation(FVector(Xpos, -1163.61731, 214.838409));
		mesh3->SetRelativeRotation(FRotator(0, 0, 20));

		mesh4->SetRelativeLocation(FVector(Xpos, -1701.737061, 480.651428));
		mesh4->SetRelativeRotation(FRotator(0, 0, 32));

		mesh5->SetRelativeLocation(FVector(Xpos, -2155.299805, 863.896973));
		mesh5->SetRelativeRotation(FRotator(0, 0, 48));
		///================================================================================================
		mesh6->SetRelativeLocation(FVector(Xpos, 587.844421, 68.936539));
		mesh6->SetRelativeRotation(FRotator(0, 0, -8));

		mesh7->SetRelativeLocation(FVector(Xpos, 1163.61731, 214.838409));
		mesh7->SetRelativeRotation(FRotator(0, 0, -20));

		mesh8->SetRelativeLocation(FVector(Xpos, 1701.737061, 480.651428));
		mesh8->SetRelativeRotation(FRotator(0, 0, -32));

		mesh9->SetRelativeLocation(FVector(Xpos, 2155.299805, 863.896973));
		mesh9->SetRelativeRotation(FRotator(0, 0, -48));
	}
	else if (trans == 3) {
		mesh2->SetRelativeLocation(FVector(Xpos, -589.06311, 59.011078));
		mesh2->SetRelativeRotation(FRotator(0, 0, 7));

		mesh3->SetRelativeLocation(FVector(Xpos, -1169.63147, 195.764069));
		mesh3->SetRelativeRotation(FRotator(0, 0, 17.5));

		mesh4->SetRelativeLocation(FVector(Xpos, -1707.551636, 427.114655));
		mesh4->SetRelativeRotation(FRotator(0, 0, 28));

		mesh5->SetRelativeLocation(FVector(Xpos, -2193.228271, 776.940002));
		mesh5->SetRelativeRotation(FRotator(0, 0, 42));
		///================================================================================================
		mesh6->SetRelativeLocation(FVector(Xpos, 589.06311, 59.011078));
		mesh6->SetRelativeRotation(FRotator(0, 0, -7));

		mesh7->SetRelativeLocation(FVector(Xpos, 1169.63147, 195.764069));
		mesh7->SetRelativeRotation(FRotator(0, 0, -17.5));

		mesh8->SetRelativeLocation(FVector(Xpos, 1707.551636, 427.114655));
		mesh8->SetRelativeRotation(FRotator(0, 0, -28));

		mesh9->SetRelativeLocation(FVector(Xpos, 2193.228271, 776.940002));
		mesh9->SetRelativeRotation(FRotator(0, 0, -42));
	}
	else if (trans == 4) {
		mesh2->SetRelativeLocation(FVector(Xpos, -589.06311, 59.011078));
		mesh2->SetRelativeRotation(FRotator(0, 0, 6));

		mesh3->SetRelativeLocation(FVector(Xpos, -1165.148438, 173.857361));
		mesh3->SetRelativeRotation(FRotator(0, 0, 15));

		mesh4->SetRelativeLocation(FVector(Xpos, -1727.88855, 381.437317));
		mesh4->SetRelativeRotation(FRotator(0, 0, 24));

		mesh5->SetRelativeLocation(FVector(Xpos, -2235.827393, 684.282776));
		mesh5->SetRelativeRotation(FRotator(0, 0, 36));
		///================================================================================================
		mesh6->SetRelativeLocation(FVector(Xpos, 589.06311, 59.011078));
		mesh6->SetRelativeRotation(FRotator(0, 0, -6));

		mesh7->SetRelativeLocation(FVector(Xpos, 1165.148438, 173.857361));
		mesh7->SetRelativeRotation(FRotator(0, 0, -15));

		mesh8->SetRelativeLocation(FVector(Xpos, 1727.88855, 381.437317));
		mesh8->SetRelativeRotation(FRotator(0, 0, -24));

		mesh9->SetRelativeLocation(FVector(Xpos, 2235.827393, 684.282776));
		mesh9->SetRelativeRotation(FRotator(0, 0, -36));
	}
	else if (trans == 5) {
		mesh2->SetRelativeLocation(FVector(Xpos, -589.06311, 55.0));
		mesh2->SetRelativeRotation(FRotator(0, 0, 5));

		mesh3->SetRelativeLocation(FVector(Xpos, -1169.477295, 154.331451));
		mesh3->SetRelativeRotation(FRotator(0, 0, 12.5));

		mesh4->SetRelativeLocation(FVector(Xpos, -1735.592407, 331.032562));
		mesh4->SetRelativeRotation(FRotator(0, 0, 20));

		mesh5->SetRelativeLocation(FVector(Xpos, -2268.50708, 587.679993));
		mesh5->SetRelativeRotation(FRotator(0, 0, 30));
		///================================================================================================
		mesh6->SetRelativeLocation(FVector(Xpos, 589.06311, 55.0));
		mesh6->SetRelativeRotation(FRotator(0, 0, -5));

		mesh7->SetRelativeLocation(FVector(Xpos, 1169.477295, 154.331451));
		mesh7->SetRelativeRotation(FRotator(0, 0, -12.5));

		mesh8->SetRelativeLocation(FVector(Xpos, 1735.592407, 331.032562));
		mesh8->SetRelativeRotation(FRotator(0, 0, -20));

		mesh9->SetRelativeLocation(FVector(Xpos, 2268.50708, 587.679993));
		mesh9->SetRelativeRotation(FRotator(0, 0, -30));
	}
	else if (trans == 6) {
		mesh2->SetRelativeLocation(FVector(Xpos, -589.760681, 45.024361));
		mesh2->SetRelativeRotation(FRotator(0, 0, 4));

		mesh3->SetRelativeLocation(FVector(Xpos, -1174.686646, 124.787209));
		mesh3->SetRelativeRotation(FRotator(0, 0, 10));

		mesh4->SetRelativeLocation(FVector(Xpos, -1752.130493, 273.356903));
		mesh4->SetRelativeRotation(FRotator(0, 0, 16));

		mesh5->SetRelativeLocation(FVector(Xpos, -2313.248291, 487.190094));
		mesh5->SetRelativeRotation(FRotator(0, 0, 24));
		///================================================================================================
		mesh6->SetRelativeLocation(FVector(Xpos, 589.760681, 45.024361));
		mesh6->SetRelativeRotation(FRotator(0, 0, -4));

		mesh7->SetRelativeLocation(FVector(Xpos, 1174.686646, 124.787209));
		mesh7->SetRelativeRotation(FRotator(0, 0, -10));

		mesh8->SetRelativeLocation(FVector(Xpos, 1752.130493, 273.356903));
		mesh8->SetRelativeRotation(FRotator(0, 0, -16));

		mesh9->SetRelativeLocation(FVector(Xpos, 2313.248291, 487.190094));
		mesh9->SetRelativeRotation(FRotator(0, 0, -24));
	}
	else if (trans == 7) {
		mesh2->SetRelativeLocation(FVector(Xpos, -589.760681, 40.0));
		mesh2->SetRelativeRotation(FRotator(0, 0, 3));

		mesh3->SetRelativeLocation(FVector(Xpos, -1178.602539, 95.043854));
		mesh3->SetRelativeRotation(FRotator(0, 0, 7.5));

		mesh4->SetRelativeLocation(FVector(Xpos, -1766.684204, 204.886566));
		mesh4->SetRelativeRotation(FRotator(0, 0, 12));

		mesh5->SetRelativeLocation(FVector(Xpos, -2331.309082, 366.883026));
		mesh5->SetRelativeRotation(FRotator(0, 0, 18));
		///================================================================================================
		mesh6->SetRelativeLocation(FVector(Xpos, 589.760681, 40.0));
		mesh6->SetRelativeRotation(FRotator(0, 0, -3));

		mesh7->SetRelativeLocation(FVector(Xpos, 1178.602539, 95.043854));
		mesh7->SetRelativeRotation(FRotator(0, 0, -7.5));

		mesh8->SetRelativeLocation(FVector(Xpos, 1766.684204, 204.886566));
		mesh8->SetRelativeRotation(FRotator(0, 0, -12));

		mesh9->SetRelativeLocation(FVector(Xpos, 2331.309082, 366.883026));
		mesh9->SetRelativeRotation(FRotator(0, 0, -18));
	}
	else if (trans == 8) {
		mesh2->SetRelativeLocation(FVector(Xpos, -590.10968, 35.0));
		mesh2->SetRelativeRotation(FRotator(0, 0, 2));

		mesh3->SetRelativeLocation(FVector(Xpos, -1180.345703, 75.119965));
		mesh3->SetRelativeRotation(FRotator(0, 0, 5));

		mesh4->SetRelativeLocation(FVector(Xpos, -1775.034546, 145.47049));
		mesh4->SetRelativeRotation(FRotator(0, 0, 8));

		mesh5->SetRelativeLocation(FVector(Xpos, -2366.039795, 251.584488));
		mesh5->SetRelativeRotation(FRotator(0, 0, 12));
		///================================================================================================
		mesh6->SetRelativeLocation(FVector(Xpos, 590.10968, 35.0));
		mesh6->SetRelativeRotation(FRotator(0, 0, -2));

		mesh7->SetRelativeLocation(FVector(Xpos, 1180.345703, 75.119965));
		mesh7->SetRelativeRotation(FRotator(0, 0, -5));

		mesh8->SetRelativeLocation(FVector(Xpos, 1775.034546, 145.47049));
		mesh8->SetRelativeRotation(FRotator(0, 0, -8));

		mesh9->SetRelativeLocation(FVector(Xpos, 2366.039795, 251.584488));
		mesh9->SetRelativeRotation(FRotator(0, 0, -12));
	}
	else if (trans == 9) {
		mesh2->SetRelativeLocation(FVector(Xpos, -590.28418, 25.001522));
		mesh2->SetRelativeRotation(FRotator(0, 0, 1));

		mesh3->SetRelativeLocation(FVector(Xpos, -1181.654175, 45.148521));
		mesh3->SetRelativeRotation(FRotator(0, 0, 2.5));

		mesh4->SetRelativeLocation(FVector(Xpos, -1779.219604, 85.616646));
		mesh4->SetRelativeRotation(FRotator(0, 0, 4));

		mesh5->SetRelativeLocation(FVector(Xpos, -2377.536865, 142.187057));
		mesh5->SetRelativeRotation(FRotator(0, 0, 6));
		///================================================================================================
		mesh6->SetRelativeLocation(FVector(Xpos, 590.28418, 25.001522));
		mesh6->SetRelativeRotation(FRotator(0, 0, -1));

		mesh7->SetRelativeLocation(FVector(Xpos, 1181.654175, 45.148521));
		mesh7->SetRelativeRotation(FRotator(0, 0, -2.5));

		mesh8->SetRelativeLocation(FVector(Xpos, 1779.219604, 85.616646));
		mesh8->SetRelativeRotation(FRotator(0, 0, -4));

		mesh9->SetRelativeLocation(FVector(Xpos, 2377.536865, 142.187057));
		mesh9->SetRelativeRotation(FRotator(0, 0, -6));
	}
		
	else if (trans == 10) {
		

		mesh2->SetRelativeLocation(FVector(Xpos, 600, 20));
		mesh2->SetRelativeRotation(FRotator(0, 0, 0));

		mesh3->SetRelativeLocation(FVector(Xpos, 1200, 20));
		mesh3->SetRelativeRotation(FRotator(0, 0, 0));

		mesh4->SetRelativeLocation(FVector(Xpos, 1800, 20));
		mesh4->SetRelativeRotation(FRotator(0, 0, 0));

		mesh5->SetRelativeLocation(FVector(Xpos, 2400, 20));
		mesh5->SetRelativeRotation(FRotator(0, 0, 0));
		///================================================================================================
		mesh6->SetRelativeLocation(FVector(Xpos, -600, 20));
		mesh6->SetRelativeRotation(FRotator(0, 0, 0));

		mesh7->SetRelativeLocation(FVector(Xpos, -1200, 20));
		mesh7->SetRelativeRotation(FRotator(0, 0, 0));

		mesh8->SetRelativeLocation(FVector(Xpos, -1800, 20));
		mesh8->SetRelativeRotation(FRotator(0, 0, 0));

		mesh9->SetRelativeLocation(FVector(Xpos, -2400, 20));
		mesh9->SetRelativeRotation(FRotator(0, 0, 0));
	}

	mesh1->AddRelativeLocation(FVector(0, 0, -20));
	mesh2->AddRelativeLocation(FVector(0, 0, -20));
	mesh3->AddRelativeLocation(FVector(0, 0, -20));
	mesh4->AddRelativeLocation(FVector(0, 0, -20));
	mesh5->AddRelativeLocation(FVector(0, 0, -20));
	mesh6->AddRelativeLocation(FVector(0, 0, -20));
	mesh7->AddRelativeLocation(FVector(0, 0, -20));
	mesh8->AddRelativeLocation(FVector(0, 0, -20));
	mesh9->AddRelativeLocation(FVector(0, 0, -20));


}


void Ablock_9::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	AC_mainChar* mainC = Cast<AC_mainChar>(OtherActor);

	if (mainC) {

		mainC->boom_predicted_length = 400;
		mainC->boom_predicted_Rot = FRotator(340, 0, 0);
		//mainC->camera_predicted_Rot = FRotator(15, 0, 0);
		Camera_Manupulator->DestroyComponent();
	}


}


void Ablock_9 :: YRoatation(float RotInY) {
	mesh1->SetRelativeRotation(FRotator(RotInY, mesh1->GetRelativeRotation().Yaw, mesh1->GetRelativeRotation().Roll));
	mesh2->SetRelativeRotation(FRotator(RotInY, mesh2->GetRelativeRotation().Yaw, mesh2->GetRelativeRotation().Roll));
	mesh3->SetRelativeRotation(FRotator(RotInY, mesh3->GetRelativeRotation().Yaw, mesh3->GetRelativeRotation().Roll));
	mesh4->SetRelativeRotation(FRotator(RotInY, mesh4->GetRelativeRotation().Yaw, mesh4->GetRelativeRotation().Roll));
	mesh5->SetRelativeRotation(FRotator(RotInY, mesh5->GetRelativeRotation().Yaw, mesh5->GetRelativeRotation().Roll));
	mesh6->SetRelativeRotation(FRotator(RotInY, mesh6->GetRelativeRotation().Yaw, mesh6->GetRelativeRotation().Roll));
	mesh7->SetRelativeRotation(FRotator(RotInY, mesh7->GetRelativeRotation().Yaw, mesh7->GetRelativeRotation().Roll));
	mesh8->SetRelativeRotation(FRotator(RotInY, mesh8->GetRelativeRotation().Yaw, mesh8->GetRelativeRotation().Roll));
	mesh9->SetRelativeRotation(FRotator(RotInY, mesh9->GetRelativeRotation().Yaw, mesh9->GetRelativeRotation().Roll));

}

void Ablock_9 :: Zpos(float val) {
	mesh1->SetRelativeLocation(FVector(mesh1->GetRelativeLocation().X, mesh1->GetRelativeLocation().Y, val));
	mesh2->SetRelativeLocation(FVector(mesh2->GetRelativeLocation().X, mesh2->GetRelativeLocation().Y, val));
	mesh3->SetRelativeLocation(FVector(mesh3->GetRelativeLocation().X, mesh3->GetRelativeLocation().Y, val));
	mesh4->SetRelativeLocation(FVector(mesh4->GetRelativeLocation().X, mesh4->GetRelativeLocation().Y, val));
	mesh5->SetRelativeLocation(FVector(mesh5->GetRelativeLocation().X, mesh5->GetRelativeLocation().Y, val));
	mesh6->SetRelativeLocation(FVector(mesh6->GetRelativeLocation().X, mesh6->GetRelativeLocation().Y, val));
	mesh7->SetRelativeLocation(FVector(mesh7->GetRelativeLocation().X, mesh7->GetRelativeLocation().Y, val));
	mesh8->SetRelativeLocation(FVector(mesh8->GetRelativeLocation().X, mesh8->GetRelativeLocation().Y, val));
	mesh9->SetRelativeLocation(FVector(mesh9->GetRelativeLocation().X, mesh9->GetRelativeLocation().Y, val));

}

