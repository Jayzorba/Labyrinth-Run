// Fill out your copyright notice in the Description page of Project Settings.


#include "Floor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AFloor::AFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	floorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor Mesh"));
	floorMesh->SetCollisionProfileName(TEXT("BlockAll"));
	RootComponent = floorMesh;

	//actorToSpawn = actorToSpawn->CreateDefaultSubobject > (TEXT("Floor Spawn"));

	//3 lanes, if player is in lane 0 or 4 then game over.

	//floorCol = CreateDefaultSubobject<UBoxComponent>(TEXT("Floor Collider"));
	//floorCol->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	//floorCol->SetCollisionProfileName(TEXT("Trigger"));
	//floorCol->SetupAttachment(RootComponent);

	//outOfBoundCol = CreateDefaultSubobject<UBoxComponent>(TEXT("Out Of Bounds"));
	//outOfBoundCol->InitBoxExtent(outOfBoundsBoxScale);
	//outOfBoundCol->SetCollisionProfileName(TEXT("Trigger"));
	//outOfBoundCol->SetupAttachment(RootComponent);


}
//
//void AFloor::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//
//	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
//	{
//		//TODO: spawn next platform
//		UGameplayStatics::OpenLevel(this, "GameOver");
//	}
//}
// Called when the game starts or when spawned
void AFloor::BeginPlay()
{
	Super::BeginPlay();
//	outOfBoundCol->OnComponentBeginOverlap.AddDynamic(this, &AFloor::BeginOverlap);
	SetLifeSpan(2);
}

// Called every frame
void AFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (int i = 1; i == stage; i++)
	{
		levelSpeed = levelSpeed * stage;
	}
	
	FVector floorLocation = GetActorLocation();

	floorLocation -= GetActorForwardVector() * levelSpeed * DeltaTime;

	SetActorLocation(floorLocation);
}

