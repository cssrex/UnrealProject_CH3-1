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

	MoveSpeed = 100.0f;

	Destination = FVector(0.0f, 1000.0f, 0.0f);
}

void ADTMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
	EndLocation = StartLocation + GetActorTransform().TransformVectorNoScale(Destination);
}

void ADTMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//// 시작점을 중심으로 왕복해서 움직임
	//if (!MoveSpeed.IsNearlyZero())
	//{
	//	AddActorWorldOffset(MoveSpeed * DeltaTime);

	//	// 시작 지점으로부터 MaxRange보다 멀어지면 속도 뒤집기
	//	if (FVector::Dist(StartLocation, GetActorLocation()) > MaxRange)
	//	{
	//		MoveSpeed *= -1;
	//	}
	//}

	if (MoveSpeed <= 0.0f || Destination.IsNearlyZero())
	{
		return;
	}

	const float Distance = FVector::Dist(StartLocation, EndLocation);

	if (Distance <= KINDA_SMALL_NUMBER)
	{
		return;
	}

	Alpha += (MoveSpeed / Distance) * DeltaTime * Direction;

	if (Alpha >= 1.0f)
	{
		Alpha = 1.0f;
		Direction = -1.0f;
	}
	else if (Alpha <= 0.0f)
	{
		Alpha = 0.0f;
		Direction = 1.0f;
	}

	const float SmoothAlpha = (1.0f - FMath::Cos(Alpha * PI)) * 0.5f;

	SetActorLocation(FMath::Lerp(StartLocation, EndLocation, SmoothAlpha));
}

