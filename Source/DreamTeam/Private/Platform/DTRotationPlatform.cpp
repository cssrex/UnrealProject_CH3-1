// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform/DTRotationPlatform.h"

// Sets default values
ADTRotationPlatform::ADTRotationPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADTRotationPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADTRotationPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

