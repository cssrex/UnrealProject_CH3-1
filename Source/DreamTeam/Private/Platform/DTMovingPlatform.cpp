#include "Platform/DTMovingPlatform.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

ADTMovingPlatform::ADTMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComp->SetupAttachment(SceneRoot);

	MoveSpeed = FVector(0, 100.0f, 0);

	MaxRange = 1000.f;
}

void ADTMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

void ADTMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (!MoveSpeed.IsNearlyZero())
	{
		AddActorWorldOffset(MoveSpeed * DeltaTime);

		if (FVector::Dist(StartLocation, GetActorLocation()) > MaxRange)
		{
			MoveSpeed *= -1;
		}
	}
}

