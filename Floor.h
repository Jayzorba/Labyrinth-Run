// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floor.generated.h"

UCLASS()
class LABYRINTHESCAPE_API AFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloor();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floor Mesh")
		class UStaticMeshComponent* floorMesh;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Out of Bounds Col")
	//	class UBoxComponent* outOfBoundCol;

	//UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Spawner")
	//	class TSubclassOf<AFloor> actorToSpawn;

	//UFUNCTION()
	//	void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	//		AActor* OtherActor,
	//		UPrimitiveComponent* OtherComp,
	//		int32 OtherBodyIndex,
	//		bool bFromSweep,
	//		const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int stage = 1;

	float levelSpeed = 750.0f;

	//FVector outOfBoundsBoxScale = FVector(25.0f, 200.0f, 25.0f);
};
