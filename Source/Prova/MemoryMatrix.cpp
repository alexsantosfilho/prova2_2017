// Fill out your copyright notice in the Description page of Project Settings.

#include "Prova.h"
#include "MemoryMatrix.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "MemoryMatrixGrid.h"

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

	ChangeSprite();
	if (!OwnerGrid->GetFreeze()) {
		if (OwnerGrid->Verificar(this)) {
			Sprite->SetSprite(SpriteOn);
			OwnerGrid->SetFreeze(true);
			UWorld* World = GetWorld();
			if (World) {
				GetWorldTimerManager().SetTimer(ShowClicked, this,
					&AMemoryMatrix::WaitColorOn, 0.5f, true);
			}
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("GAME OVER!"));
			OwnerGrid->GameOver();
		}
	}

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

void AMemoryMatrix::SetOwnerGrid(class AMemoryMatrixGrid* Grid) {
	OwnerGrid = Grid;
}

void AMemoryMatrix::ChangeSprite() {
	
	UWorld* World = GetWorld();
	
	if (Sprite->GetSprite() == FirstSprite && World) {
		Sprite->SetSprite(ShineSprite);
		
		GetWorldTimerManager().SetTimer(ShowClicked, this,
			&AMemoryMatrix::ChangeSprite, 0.5f, true);
	}
	else {
		Sprite->SetSprite(FirstSprite);
	}
}

void AMemoryMatrix::WaitColorOn() {
	Sprite->SetSprite(SpriteOff);
	OwnerGrid->SetFreeze(false);
	GetWorldTimerManager().ClearTimer(ShowClicked);
}