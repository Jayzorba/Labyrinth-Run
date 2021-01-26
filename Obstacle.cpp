// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	obstacleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("obstacleMesh"));
	obstacleMesh->SetWorldScale3D(FVector(1.0f, randScale, 1.0f));
	obstacleMesh->SetCollisionProfileName(TEXT("Trigger"));

	//obstacleMesh->SetRelativeScale3D(FVector(1.0f, randScale, 1.0f));
	RootComponent = obstacleMesh;

	obstacleCol = CreateDefaultSubobject<UBoxComponent>(TEXT("Obstacle"));
	obstacleCol->SetWorldScale3D(FVector(1.0f, randScale, 1.0f));
	obstacleCol->SetCollisionProfileName(TEXT("Trigger"));
	//obstacleCol->OnComponentBeginOverlap.AddDynamic(this, &AObstacle::BeginOverlap);
	obstacleCol->SetupAttachment(RootComponent);


	//obstacleCol->SetRelativeScale3D(FVector(1.0f, randScale, 1.0f));
}

void AObstacle::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		UE_LOG(LogTemp, Warning, TEXT("GameOverPing"));
		UGameplayStatics::OpenLevel(this, "GameOver");


	}
}


// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();

	obstacleCol->OnComponentBeginOverlap.AddDynamic(this, &AObstacle::BeginOverlap);

	SetLifeSpan(3.0f);

	if (APlayerChar::score <= 5000)
	{
		stage = 10;
	}
	else if (APlayerChar::score <= 4500)
	{
		stage = 9;
	}
	else if (APlayerChar::score <= 4000)
	{
		stage = 8;
	}
	else if (APlayerChar::score <= 3500)
	{
		stage = 7;
	}
	else if (APlayerChar::score <= 3000)
	{
		stage = 6;
	}
	else if (APlayerChar::score <= 2500)
	{
		stage = 5;
	}
	else if (APlayerChar::score <= 2000)
	{
		stage = 4;
	}
	else if (APlayerChar::score <= 1500)
	{
		stage = 3;
	}
	else if (APlayerChar::score <= 1000)
	{
		stage = 2;
	}
	else
	{
		stage = 1;
	}
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (int i = 1; i == stage; i++)
	{
		levelSpeed = levelSpeed * stage;
	}

	FVector obstacleLocation = GetActorLocation();

	obstacleLocation -= GetActorForwardVector() * levelSpeed * DeltaTime;

	SetActorLocation(obstacleLocation);
}

