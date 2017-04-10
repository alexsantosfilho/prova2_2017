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
#include "Runtime/UMG/Public/Blueprint/WidgetBlueprintLibrary.h"


// Sets default values
AMemoryMatrixGrid::AMemoryMatrixGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

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

		//AMemoryMatrix* P1 = World->SpawnActor<AMemoryMatrix>(Um, FVector(1000.0f, 0.0f, 000.0f), FRotator::ZeroRotator, SpawnParameters);
	
		for (int i = 1; i < ((MatrixCol*MatrixRow) + 1); i++) {
			FActorSpawnParameters SpawnParameters;
			AMemoryMatrix* P1 = World->SpawnActor<AMemoryMatrix>(Um, FVector(X, 0, Z), FRotator::ZeroRotator, SpawnParameters);
			AMemoryMatrix* P2 = World->SpawnActor<AMemoryMatrix>(Um, FVector(X, 0, Z), FRotator::ZeroRotator, SpawnParameters);
			AMemoryMatrix* P3 = World->SpawnActor<AMemoryMatrix>(Um, FVector(X, 0, Z), FRotator::ZeroRotator, SpawnParameters);
			AMemoryMatrix* P4 = World->SpawnActor<AMemoryMatrix>(Um, FVector(X, 0, Z), FRotator::ZeroRotator, SpawnParameters);
			AMemoryMatrix* P5 = World->SpawnActor<AMemoryMatrix>(Um, FVector(X, 0, Z), FRotator::ZeroRotator, SpawnParameters);
			AMemoryMatrix* P6 = World->SpawnActor<AMemoryMatrix>(Um, FVector(X, 0, Z), FRotator::ZeroRotator, SpawnParameters);
			AMemoryMatrix* P7 = World->SpawnActor<AMemoryMatrix>(Um, FVector(X, 0, Z), FRotator::ZeroRotator, SpawnParameters);
			AMemoryMatrix* P8 = World->SpawnActor<AMemoryMatrix>(Um, FVector(X, 0, Z), FRotator::ZeroRotator, SpawnParameters);
			AMemoryMatrix* P9 = World->SpawnActor<AMemoryMatrix>(Um, FVector(X, 0, Z), FRotator::ZeroRotator, SpawnParameters);

			

			
			
			P1->SetIndex(0);
			P2->SetIndex(1);
			P3->SetIndex(2);
			P4->SetIndex(3);
			P5->SetIndex(4);
			P6->SetIndex(5);
			P7->SetIndex(6);
			P8->SetIndex(7);
			P9->SetIndex(8);

			Matrix.Add(P1);
			Matrix.Add(P2);
			Matrix.Add(P3);
			Matrix.Add(P4);
			Matrix.Add(P5);
			Matrix.Add(P6);
			Matrix.Add(P7);
			Matrix.Add(P8);
			Matrix.Add(P9);




			X += 1000.0f;



			if (i % MatrixCol == 0) {
				Z -= 1000.0f;
				X = 0;
			}
		}
		
		/*	AMemoryMatrix* P2 = World->SpawnActor<AMemoryMatrix>(Um, FVector(1000.0f, 0.0f, 1000.0f), FRotator::ZeroRotator, SpawnParameters);
		AMemoryMatrix* P3 = World->SpawnActor<AMemoryMatrix>(Um, FVector(1000.0f, 0.0f, 2000.f), FRotator::ZeroRotator, SpawnParameters);
		AMemoryMatrix* P4 = World->SpawnActor<AMemoryMatrix>(Um, FVector(-1000.0f, 0.0f, 0.0f), FRotator::ZeroRotator, SpawnParameters);
		AMemoryMatrix* P5 = World->SpawnActor<AMemoryMatrix>(Um, FVector(-1000.0f, 0.0f, 1000.0f), FRotator::ZeroRotator, SpawnParameters);
		AMemoryMatrix* P6 = World->SpawnActor<AMemoryMatrix>(Um, FVector(-1000.0f, 0.0f, 2000.f), FRotator::ZeroRotator, SpawnParameters);
		AMemoryMatrix* P7 = World->SpawnActor<AMemoryMatrix>(Um, FVector(0.0f, 0.0f, 0.0f), FRotator::ZeroRotator, SpawnParameters);
		AMemoryMatrix* P8 = World->SpawnActor<AMemoryMatrix>(Um, FVector(0.0f, 0.0f, 1000.0f), FRotator::ZeroRotator, SpawnParameters);
		AMemoryMatrix* P9 = World->SpawnActor<AMemoryMatrix>(Um, FVector(0.0f, 0.0f, 2000.f), FRotator::ZeroRotator, SpawnParameters);

		if (P1 != nullptr) {

			UE_LOG(LogTemp, Warning, TEXT("if do begin play P1"));

		}

		if (P2 != nullptr) {

			UE_LOG(LogTemp, Warning, TEXT("if do begin play P2"));

		}

	
		UE_LOG(LogTemp, Warning, TEXT("if do begin play"));
		P1->SetIndex(0);
		P1->SetOwnerGrid(this);
		Matrix.Add(P1);

		P2->SetIndex(1);
		P2->SetOwnerGrid(this);
		Matrix.Add(P2);

		P3->SetIndex(2);
		P3->SetOwnerGrid(this);
		Matrix.Add(P3);


		P4->SetIndex(3);
		P4->SetOwnerGrid(this);
		Matrix.Add(P4);



		P5->SetIndex(4);
		P5->SetOwnerGrid(this);
		Matrix.Add(P5);


		P6->SetIndex(5);
		P6->SetOwnerGrid(this);
		Matrix.Add(P6);

		*/
	}
	Pisca();
	
}

// Called every frame
void AMemoryMatrixGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AMemoryMatrixGrid::SetFreeze(bool NewFreeze) {
	bFreeze = NewFreeze;
}

bool AMemoryMatrixGrid::GetFreeze() {
	return bFreeze;
}

void AMemoryMatrixGrid::Pisca() {

	int ActualSequence = Sequence[Index];
	Matrix[ActualSequence]->ChangeSprite();
	FaseCont++;

	if (FaseCont % 2 == 0) {
		MatrixCol = MatrixCol + 1;
	}
	else {
		MatrixRow = MatrixRow + 1;
	}

	int Random = FMath::RandRange(0, 2);
	int Random2 = FMath::RandRange(3, 5);
	int Random3 = FMath::RandRange(6, 8);




	if (Random) {

		Sequence.Add(Random);
		Index = 0;
		bLight = false;
		NumOfClicks = 0;
		bFreeze = true;
	}
	if (Random2) {

		Sequence.Add(Random2);
		Index = 0;
		bLight = false;
		NumOfClicks = 0;
		bFreeze = true;
	}
	if (Random3) {

		Sequence.Add(Random3);
		Index = 0;
		bLight = false;
		NumOfClicks = 0;
		bFreeze = true;
	}


	UWorld* World = GetWorld();
	if (World) {
	//GetWorldTimerManager().SetTimer(MCard, this, &AMemoryMatrixGrid::Show, 1.0f, true);
		//Show();
		Random++;

	}
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



void AMemoryMatrixGrid::Show() {


	
}

bool AMemoryMatrixGrid::Verificar(class AMemoryMatrix * Click)
{

	if (Sequence[NumOfClicks] == Click->GetIndex()) {
		NumOfClicks++;
		if (NumOfClicks == Sequence.Num()) {
			UWorld* World = GetWorld();
			if (World) {
				APawn* MPawn = UGameplayStatics::GetPlayerController(World, 0)->GetControlledPawn();
				AMemoryMatrixPawn* MemoryMatrixPawn = Cast<AMemoryMatrixPawn>(MPawn);
				MemoryMatrixPawn->SetPonto(MemoryMatrixPawn->GetPonto() + 100);
				UE_LOG(LogTemp, Warning, TEXT("Pontos: %d"));
			}
		}
		return true;
	}


	return false;
}

void AMemoryMatrixGrid::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {

	if ((OtherActor != nullptr) && (OtherActor->IsA(AMemoryMatrixPawn::StaticClass()))) {
		AMemoryMatrixPawn* Grid = Cast<AMemoryMatrixPawn>(OtherActor);
		UWorld* World = GetWorld();
		if (Grid->GetPonto() == 100 && World != nullptr) {
			UGameplayStatics::OpenLevel(World, "Mapa2");
		}
	}
}


