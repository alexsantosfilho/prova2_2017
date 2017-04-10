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


	void SetIndex(int NewIndex);
	
	
	int GetIndex();

	void SetOwnerGrid(class AMemoryMatrixGrid* Grid);

	void ChangeSprite();

	

private:

	UPROPERTY(EditAnywhere)
		class UPaperSpriteComponent* Sprite;

	UPROPERTY(EditAnywhere)
		class UPaperSprite* SpriteOff;


	UFUNCTION()
		void OnTouchBegin(ETouchIndex::Type Type, UPrimitiveComponent* TouchedComponent);

	class AMemoryMatrixGrid* OwnerGrid;

	UPROPERTY(EditAnywhere)
		class UPaperSprite* FirstSprite;
	UPROPERTY(EditAnywhere)
		class UPaperSprite* ShineSprite;

	int Index;
	FTimerHandle ShowClicked;
	
};
