// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"

// Sets default values
AManager::AManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	managerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor Mesh"));
	managerMesh->SetCollisionProfileName(TEXT("BlockAll"));
	RootComponent = managerMesh;

	//actorToSpawn = actorToSpawn->CreateDefaultSubobject > (TEXT("Floor Spawn"));

	//3 lanes, if player is in lane 0 or 4 then game over.

	//floorCol = CreateDefaultSubobject<UBoxComponent>(TEXT("Floor Collider"));
	//floorCol->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	//floorCol->SetCollisionProfileName(TEXT("Trigger"));
	//floorCol->SetupAttachment(RootComponent);










}




//void AManager::spawnFloor()
//{
//
//	actorToSpawn->GetWorld()->SpawnActor<AManager>(actorToSpawn, GetActorLocation(), GetActorRotation());
//	UE_LOG(LogTemp, Warning, TEXT("SpawnPing"));
//}

// Called when the game starts or when spawned
void AManager::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void AManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

