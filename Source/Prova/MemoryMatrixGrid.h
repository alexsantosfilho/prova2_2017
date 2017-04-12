// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MemoryMatrixGrid.generated.h"

UCLASS()
class PROVA_API AMemoryMatrixGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMemoryMatrixGrid();

	bool Verificar(class AMemoryMatrix* Click);
	void SetFreeze(bool NewFreeze);
	bool GetFreeze();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
private:

	UPROPERTY(EditAnywhere)
		USceneComponent* Root;
	/*UPROPERTY(EditAnywhere)
	bool bTurned;*/

	TSubclassOf<class AMemoryMatrix> Um;


	TArray<class AMemoryMatrix*> Matrix;
	TArray<int> Sequence;

	int Index;
	bool bFreeze;
	bool bLight;
	FTimerHandle MCard;
	int NumOfClicks;


	void Pisca();
	void Show();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
