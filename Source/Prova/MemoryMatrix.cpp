// Fill out your copyright notice in the Description page of Project Settings.

#include "Prova.h"
#include "MemoryMatrix.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"

// Sets default values
AMemoryMatrix::AMemoryMatrix()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	Sprite->SetSprite(SpriteOff);
	Sprite->OnInputTouchBegin.AddDynamic(this, &AMemoryMatrix::OnTouchBegin);
	RootComponent = Sprite;
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



void AMemoryMatrix::SetIndex(int NewIndex)
{
	Index = NewIndex;

}

int AMemoryMatrix::GetIndex()
{
	return Index;
}

void AMemoryMatrix::SetOwnerGrid(AMemoryMatrixGrid * Grid)
{

	//OwnerGrid = Grid;

}
