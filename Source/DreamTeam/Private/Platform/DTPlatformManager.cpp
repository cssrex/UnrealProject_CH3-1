#include "Platform/DTPlatformManager.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"

ADTPlatformManager::ADTPlatformManager()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	SpawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	SpawnArea->SetupAttachment(SceneRoot);
	SpawnArea->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	SpawnCount = 10;
}

void ADTPlatformManager::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnPlatform();
}

void ADTPlatformManager::SpawnPlatform()
{
	if (!IsValid(PlatformClasses))
	{
		return;
	}

	const FVector AreaCenter = SpawnArea->GetComponentLocation();
	const FVector AreaExtent = SpawnArea->GetScaledBoxExtent();

	for (int32 i = 0; i < SpawnCount; i++)
	{
		const float RandomX = FMath::RandRange(AreaCenter.X - AreaExtent.X, AreaCenter.X + AreaExtent.X);
		const float RandomY = FMath::RandRange(AreaCenter.Y - AreaExtent.Y, AreaCenter.Y + AreaExtent.Y);

		FVector SpawnLocation(RandomX, RandomY, GetActorLocation().Z);

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

		GetWorld()->SpawnActor<AActor>(PlatformClasses, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
	}

}

