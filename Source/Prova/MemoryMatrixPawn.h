// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "MemoryMatrixPawn.generated.h"

UCLASS()
class PROVA_API AMemoryMatrixPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMemoryMatrixPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetPonto(int NewPonto);
	
	
	UFUNCTION(BluePrintCallable, Category = "Ponto")
	int GetPonto();
	
private:

	UPROPERTY(EditAnywhere)
		UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere)
		int Ponto = 100;
};
