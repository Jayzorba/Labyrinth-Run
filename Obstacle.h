// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerChar.h"
#include "Obstacle.generated.h"

UCLASS()
class LABYRINTHESCAPE_API AObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObstacle();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floor Mesh")
		class UStaticMeshComponent* obstacleMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "obstacle Col")
		class UBoxComponent* obstacleCol;


	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int stage = 1;

	float levelSpeed = 750.0f;

	float randScale = FMath::RandRange(1.0f, 3.0f);
};
