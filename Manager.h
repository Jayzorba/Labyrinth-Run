// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Manager.generated.h"

UCLASS()
class LABYRINTHESCAPE_API AManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floor Mesh")
		class UStaticMeshComponent* managerMesh;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floor Collider")
	//	class UBoxComponent* floorCol;




	//UFUNCTION()
	//	void DestroyActor();

	/*UFUNCTION()
		void spawnFloor();*/
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//FTimerHandle destroyHandle;
	//FTimerDelegate TimerDel;
	//FTimerHandle TimerHandle;




public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
