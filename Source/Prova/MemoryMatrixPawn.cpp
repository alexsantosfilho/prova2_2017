// Fill out your copyright notice in the Description page of Project Settings.

#include "Prova.h"
#include "MemoryMatrixPawn.h"


// Sets default values
AMemoryMatrixPawn::AMemoryMatrixPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->ProjectionMode = ECameraProjectionMode::Orthographic;
	Camera->OrthoWidth = 10019.0f;
	Camera->SetupAttachment(RootComponent);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void AMemoryMatrixPawn::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMemoryMatrixPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMemoryMatrixPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMemoryMatrixPawn::SetPonto(int NewPonto) {
	Ponto = NewPonto;
}

int AMemoryMatrixPawn::GetPonto() {
	return Ponto;
}