// Fill out your copyright notice in the Description page of Project Settings.

#include "Prova.h"
#include "MemoryMatrix.h"
#include "MemoryMatrixGrid.h"
#include "MemoryMatrixPawn.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "MemoryMatrixPlayerController.h"

#include "Runtime/UMG/Public/Blueprint/WidgetBlueprintLibrary.h"


// Sets default values
AMemoryMatrixGrid::AMemoryMatrixGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	ConstructorHelpers::FClassFinder<UUserWidget> Widget(TEXT("WidgetBlueprint'/Game/blueprint/umg/GameOver.GameOver_C'"));
	if (Widget.Succeeded()) {
		GameOver = Widget.Class;
	}

	ConstructorHelpers::FObjectFinder<UClass> OBP(TEXT("Blueprint'/Game/blueprint/MyMemoryMatrix.MyMemoryMatrix_C'"));
	UE_LOG(LogTemp, Warning, TEXT("construtor"));

	if (OBP.Succeeded()) {
		Um = Cast<UClass>(OBP.Object);
		UE_LOG(LogTemp, Warning, TEXT("Succeeded"));
	}

}

// Called when the game starts or when spawned
void AMemoryMatrixGrid::BeginPlay()
{
	Super::BeginPlay();


	UWorld* World = GetWorld();
	if (World) {

		FActorSpawnParameters SpawnParameters;

	
			AMemoryMatrix* P1 = World->SpawnActor<AMemoryMatrix>(Um, FVector(1000.0f, 0.0f, 0.0f), FRotator::ZeroRotator, SpawnParameters);
			AMemoryMatrix* P2 = World->SpawnActor<AMemoryMatrix>(Um, FVector(1000.0f, 0.0f, 1000.0f), FRotator::ZeroRotator, SpawnParameters);
			AMemoryMatrix* P3 = World->SpawnActor<AMemoryMatrix>(Um, FVector(1000.0f, 0.0f, 2000.0f), FRotator::ZeroRotator, SpawnParameters);
			AMemoryMatrix* P4 = World->SpawnActor<AMemoryMatrix>(Um, FVector(-1000.f, 0.0f, 0.0f), FRotator::ZeroRotator, SpawnParameters);
			AMemoryMatrix* P5 = World->SpawnActor<AMemoryMatrix>(Um, FVector(-1000.0f, 0.0f, 1000.0f), FRotator::ZeroRotator, SpawnParameters);
			AMemoryMatrix* P6 = World->SpawnActor<AMemoryMatrix>(Um, FVector(-1000.0f, 0.0f, 2000.0f), FRotator::ZeroRotator, SpawnParameters);
			AMemoryMatrix* P7 = World->SpawnActor<AMemoryMatrix>(Um, FVector(0, 0.0f, 2000.0f), FRotator::ZeroRotator, SpawnParameters);
			AMemoryMatrix* P8 = World->SpawnActor<AMemoryMatrix>(Um, FVector(0, 0.0f, 1000.0f), FRotator::ZeroRotator, SpawnParameters);
			AMemoryMatrix* P9 = World->SpawnActor<AMemoryMatrix>(Um, FVector(0, 0.0f, -0.f), FRotator::ZeroRotator, SpawnParameters);


			P1->SetIndex(0);
			P2->SetIndex(1);
			P3->SetIndex(2);
			P4->SetIndex(3);
			P5->SetIndex(4);
			P6->SetIndex(5);
			P7->SetIndex(6);
			P8->SetIndex(7);
			P9->SetIndex(8);

			P1->SetOwnerGrid(this);
			P2->SetOwnerGrid(this);
			P3->SetOwnerGrid(this);
			P4->SetOwnerGrid(this);
			P5->SetOwnerGrid(this);
			P6->SetOwnerGrid(this);
			P7->SetOwnerGrid(this);
			P8->SetOwnerGrid(this);
			P9->SetOwnerGrid(this);
			
			Matrix.Add(P1);
			Matrix.Add(P2);
			Matrix.Add(P3);
			Matrix.Add(P4);
			Matrix.Add(P5);
			Matrix.Add(P6);
			Matrix.Add(P7);
			Matrix.Add(P8);
			Matrix.Add(P9);
			



			Pisca();

	}
	
}

// Called every frame
void AMemoryMatrixGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AMemoryMatrixGrid::Verificar(AMemoryMatrix * Click)
{
	if (Sequence[NumOfClicks] == Click->GetIndex()) {
		NumOfClicks=3;
		if (NumOfClicks == Sequence.Num()) {
			UWorld* World = GetWorld();
			if (World) {
				APawn* MPawn = UGameplayStatics::GetPlayerController(World, 0)->GetPawn();
				AMemoryMatrixPawn* MatrixPawn = Cast<AMemoryMatrixPawn>(MPawn);
				MatrixPawn->SetPonto(MatrixPawn->GetPonto() + 100);
				UGameplayStatics::OpenLevel(World, "Mapa2");
			UE_LOG(LogTemp, Warning, TEXT("Foi Level 2!"));

			}
		}

		return true;
	}
	NumOfClicks = 1;
	if (NumOfClicks <= Sequence.Num()) {
		UWorld* World = GetWorld();
		if (World) {

			APlayerController* PlayerController = UGameplayStatics::GetPlayerController(World, 0);
			if (PlayerController && GameOver != NULL) {
				PlayerController->SetPause(true);
				UUserWidget* UserW = UWidgetBlueprintLibrary::Create(World, GameOver, PlayerController);
				if (UserW) {
					UserW->AddToViewport();
				}
			}
			UE_LOG(LogTemp, Warning, TEXT("NumOfClicks != Sequence.Num!"));
			//UGameplayStatics::OpenLevel(World, "Mapa2");

			// open o level 				UGameplayStatics::OpenLevel(World, "Mapa2");

		}
	}

	return false;
}

void AMemoryMatrixGrid::SetFreeze(bool NewFreeze) {
	bFreeze = NewFreeze;
}

bool AMemoryMatrixGrid::GetFreeze() {
	return bFreeze;
}

void AMemoryMatrixGrid::Pisca() {
	int Random = FMath::RandRange(1, 2);
	int Random2 = FMath::RandRange(3, 5);
	int Random3 = FMath::RandRange(6, 8);


	//if (!bTurned) {
	if (Random ) {
		Sequence.Add(Random);
		Index = 0;
		bLight = false;
		NumOfClicks = 0;
		bFreeze = true;
		UE_LOG(LogTemp, Warning, TEXT("Random"));

		
	}if (Random2) {
		Index = 0;
		bLight = false;
		NumOfClicks = 0;
		bFreeze = true;
		Sequence.Add(Random2);
		UE_LOG(LogTemp, Warning, TEXT("Random2"));

		
	}
	if (Random3) {
		Index = 0;
		bLight = false;
		NumOfClicks = 0;
		bFreeze = true;
		Sequence.Add(Random3);
		UE_LOG(LogTemp, Warning, TEXT("Random3"));

		
	}


	UWorld* World = GetWorld();
	if (World) {
		//Show();
		GetWorldTimerManager().SetTimer(MCard, this, &AMemoryMatrixGrid::Show, 1.0f, true);
		Random++;
	}

}



void AMemoryMatrixGrid::Show() {
	
	int ActualSequence = Sequence[Index];
	Matrix[ActualSequence]->ChangeSprite();

	if (bLight) {
		bLight = false;
		GetWorldTimerManager().ClearTimer(MCard);
		Index++;
		if (Index < Sequence.Num()) {
			GetWorldTimerManager().SetTimer(MCard, this, &AMemoryMatrixGrid::Show, 1.0f, true);
		}
		else {
			bFreeze = false;
		}
	}
	else {
		bLight = true;
		GetWorldTimerManager().ClearTimer(MCard);
		GetWorldTimerManager().SetTimer(MCard, this, &AMemoryMatrixGrid::Show, 1.0f, true);
	}


}

void AMemoryMatrixGrid::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if ((OtherActor != nullptr) && (OtherActor->IsA(AMemoryMatrixPawn::StaticClass()))) {
		AMemoryMatrixPawn* Pawn = Cast<AMemoryMatrixPawn>(OtherActor);
		UWorld* World = GetWorld();
		if (Pawn->GetPonto() == 100 && World != nullptr) {
			UGameplayStatics::OpenLevel(World, "Mapa2");
			UE_LOG(LogTemp, Warning, TEXT("Pox. Level"));
		}
	}
}

