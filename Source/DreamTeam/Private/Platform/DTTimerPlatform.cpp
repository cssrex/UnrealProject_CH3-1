// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform/DTTimerPlatform.h"

// Sets default values
ADTTimerPlatform::ADTTimerPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADTTimerPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADTTimerPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

