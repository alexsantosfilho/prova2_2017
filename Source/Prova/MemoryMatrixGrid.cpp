// Fill out your copyright notice in the Description page of Project Settings.

#include "Prova.h"
#include "MemoryMatrixGrid.h"
#include "MemoryMatrixPawn.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetBlueprintLibrary.h"


// Sets default values
AMemoryMatrixGrid::AMemoryMatrixGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	ConstructorHelpers::FObjectFinder<UClass> OBP(TEXT("Blueprint'/Game/blueprint/MyMemoryMatrix.MyMemoryMatrix'"));


	if (OBP.Succeeded()) {
		OSprite = Cast<UClass>(OBP.Object);
	}

}

// Called when the game starts or when spawned
void AMemoryMatrixGrid::BeginPlay()
{
	Super::BeginPlay();


	UWorld* World = GetWorld();
	if (World) {
		FActorSpawnParameters SpawnParameters;

		//AMemoryMatrix* P1 = World->SpawnActor<AMemoryMatrix>(OSprite, FVector(0.0f, 0.0f, 0.0f), FRotator::ZeroRotator, SpawnParameters);
		//AMemoryMatrix* P2 = World->SpawnActor<AMemoryMatrix>(OSprite, FVector(250.0f, 0.0f, 0.0f), FRotator::ZeroRotator, SpawnParameters);
		//AMemoryMatrix* P3 = World->SpawnActor<AMemoryMatrix>(OSprite, FVector(0.0f, 0.0f, 250.0f), FRotator::ZeroRotator, SpawnParameters);
		/*
		P1->SetIndex(0);
		P2->SetIndex(1);
		P3->SetIndex(2);

		P1->SetOwnerGrid(this);
		P2->SetOwnerGrid(this);
		P3->SetOwnerGrid(this);

		GeniusParts.Add(P1);
		GeniusParts.Add(P2);
		GeniusParts.Add(P3);
		*/
	}
	
}

// Called every frame
void AMemoryMatrixGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

