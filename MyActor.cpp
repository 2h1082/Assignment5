// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	start = FVector2D(0.0f, 0.0f);
	evCnt = 0;
	toDist = 0;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Hello, World!"));
	UE_LOG(LogTemp, Warning, TEXT("Starting Point : X=%.0f, Y=%.0f"), start.X, start.Y);
	move();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::move() {
	for (int i = 0; i < 10; i++) {
		FVector2D temp = start;
		int eventOccured = createEvent();
		start.X += step();
		start.Y += step();
		float dist = distance(temp, start);
		toDist += dist;
		evCnt += eventOccured;
		UE_LOG(LogTemp, Warning, TEXT("%d -> Moved : X=%.0f, Y=%.0f"), i+1, start.X, start.Y);
		UE_LOG(LogTemp, Warning, TEXT("Distance : % f, Event(1:Occured, 0:Not occured) : % d"), dist, eventOccured);
	}
	UE_LOG(LogTemp, Warning, TEXT("Total moved distance : %f, Event count : %d"), toDist, evCnt);
}

int32 AMyActor::step() {
	int32 RandomValue = FMath::RandRange(0, 1);
	return RandomValue;
}

float AMyActor::distance(FVector2D first, FVector2D second) {
	float dx = second.X - first.X;
	float dy = second.Y - first.Y;
	return FMath::Sqrt(dx * dx + dy * dy);
}

int32 AMyActor::createEvent() {
	int32 RandomValue = FMath::RandRange(1, 100);
	if (RandomValue > 50) { //Event occured
		return 1;
	}
	else { //Event not occured
		return 0;
	}
}