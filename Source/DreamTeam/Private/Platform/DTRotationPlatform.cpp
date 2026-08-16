#include "Platform/DTRotationPlatform.h"

ADTRotationPlatform::ADTRotationPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComp->SetupAttachment(SceneRoot);

	RotationSpeed = FRotator(0, 100.0f, 0);
}

void ADTRotationPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADTRotationPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!RotationSpeed.IsNearlyZero())
	{
		AddActorWorldRotation(RotationSpeed * DeltaTime);
	}
}

