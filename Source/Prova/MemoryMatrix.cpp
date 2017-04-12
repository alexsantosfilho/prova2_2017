// Fill out your copyright notice in the Description page of Project Settings.

#include "Prova.h"
#include "MemoryMatrix.h"
#include "PaperSprite.h"
#include "MemoryMatrixGrid.h"
#include "MemoryMatrixPawn.h"
#include "Blueprint/UserWidget.h"
#include "PaperSpriteComponent.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Blueprint/WidgetBlueprintLibrary.h"


// Sets default values
AMemoryMatrix::AMemoryMatrix()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	Sprite->SetSprite(FirstSprite);
	Sprite->OnInputTouchBegin.AddDynamic(this, &AMemoryMatrix::OnTouchBegin);
	RootComponent = Sprite;


	ConstructorHelpers::FClassFinder<UUserWidget> Widget(TEXT("WidgetBlueprint'/Game/blueprint/umg/GameOver.GameOver_C'"));
	if (Widget.Succeeded()) {
		GameOver = Widget.Class;
	}

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
	//UE_LOG(LogTemp, Warning, TEXT("It works!"));


	UWorld* World = GetWorld();
	if (World != nullptr) {
		AMemoryMatrixPawn* Pawn = Cast<AMemoryMatrixPawn>(UGameplayStatics::GetPlayerController(World, 0)->GetPawn());
	}

	//if (!OwnerGrid->GetFreeze()) {
		if (OwnerGrid->Verificar(this)) {
			Sprite->SetSprite(ShineSprite);
			OwnerGrid->SetFreeze(true);

			if (World) {
				GetWorldTimerManager().SetTimer(ShowClicked, this, &AMemoryMatrix::WaitPls, 10.5f, true);
				Sprite->SetSprite(ShineSprite);
				UE_LOG(LogTemp, Warning, TEXT("Certo!"));
			//}
		}
		else if (World != nullptr) {

			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(World, 0);
			if (PlayerController && GameOver != NULL) {
				PlayerController->SetPause(true);
				UUserWidget* UserW = UWidgetBlueprintLibrary::Create(World, GameOver, PlayerController);
				if (UserW) {
					UserW->AddToViewport();
				}
			}
			UE_LOG(LogTemp, Warning, TEXT("GameOver!"));
		}
	}
	ChangeSprite();

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

	if (Sprite->GetSprite() == FirstSprite) {
		Sprite->SetSprite(ShineSprite);
	}
	else {
		Sprite->SetSprite(FirstSprite);
	}
}

void AMemoryMatrix::WaitPls() {
	//Sprite->SetSprite(SpriteOff);
//	OwnerGrid->SetFreeze(false);
}