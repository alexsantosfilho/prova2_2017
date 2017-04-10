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
	bool Verificar(class AMatrixGame* Click);
	void GameOver();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
private:

	UPROPERTY(EditAnywhere)
	
		USceneComponent* Root;
	
	TSubclassOf<class UUserWidget> GameOverWidget;

	TSubclassOf<class AMemoryMatrix> Um;




	int Index;

	TArray<class AMemoryMatrix*> Matrix;
	
	TArray<int> Sequence;

	void Pisca();

	bool bLight;

	int NumOfClicks;

	bool bFreeze;

	FTimerHandle MCard;

	void Show();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
