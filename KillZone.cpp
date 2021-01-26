// Fill out your copyright notice in the Description page of Project Settings.


#include "KillZone.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AKillZone::AKillZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	killMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("killMesh"));
	killMesh->SetCollisionProfileName(TEXT("BlockAll"));
	RootComponent = killMesh;

	killCol = CreateDefaultSubobject<UBoxComponent>(TEXT("Out Of Bounds"));
	killCol->SetCollisionProfileName(TEXT("Trigger"));
	killCol->SetupAttachment(RootComponent);
}

void AKillZone::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		UGameplayStatics::OpenLevel(this, "GameOver");
	}
}

// Called when the game starts or when spawned
void AKillZone::BeginPlay()
{
	Super::BeginPlay();
	killCol->OnComponentBeginOverlap.AddDynamic(this, &AKillZone::BeginOverlap);

}

// Called every frame
void AKillZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

