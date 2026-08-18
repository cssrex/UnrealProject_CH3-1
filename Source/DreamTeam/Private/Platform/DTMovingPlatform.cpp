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
	
	// 시작점을 중심으로 왕복해서 움직임
	if (!MoveSpeed.IsNearlyZero())
	{
		AddActorWorldOffset(MoveSpeed * DeltaTime);

		// 시작 지점으로부터 MaxRange보다 멀어지면 속도 뒤집기
		if (FVector::Dist(StartLocation, GetActorLocation()) > MaxRange)
		{
			MoveSpeed *= -1;
		}
	}
}

