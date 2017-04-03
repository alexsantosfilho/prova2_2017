// Fill out your copyright notice in the Description page of Project Settings.

#include "Prova.h"
#include "MemoryMatrix.h"


// Sets default values
AMemoryMatrix::AMemoryMatrix()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMemoryMatrix::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMemoryMatrix::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMemoryMatrix::OnTouchBegin(ETouchIndex::Type Type, UPrimitiveComponent * TouchedComponent)
{


	UE_LOG(LogTemp, Warning, TEXT("clicou"));

}

