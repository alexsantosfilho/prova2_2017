// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MemoryMatrix.generated.h"

UCLASS()
class PROVA_API AMemoryMatrix : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMemoryMatrix();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

private:

	UFUNCTION()
		void OnTouchBegin(ETouchIndex::Type Type, UPrimitiveComponent* TouchedComponent);

	
};
