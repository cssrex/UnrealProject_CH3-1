#include "Platform/DTTimerPlatform.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

ADTTimerPlatform::ADTTimerPlatform()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MeshComp->SetupAttachment(SceneRoot);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(SceneRoot);
	BoxCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxCollision->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxCollision->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	BoxCollision->SetGenerateOverlapEvents(true);

	DisappearDelay = 1.0f;
	RespawnDelay = 5.0f;
}

void ADTTimerPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ADTTimerPlatform::OnTriggerBeginOverlap);
}

void ADTTimerPlatform::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 플랫폼을 밟으면 DisappearDelay초 뒤에 사라짐
	GetWorld()->GetTimerManager().SetTimer(DisappearTimerHandle, this, &ADTTimerPlatform::DisappearPlatform, DisappearDelay, false);
}

void ADTTimerPlatform::SetPlatformActive(bool bActive)
{
	SetActorHiddenInGame(!bActive);
	SetActorEnableCollision(bActive);
}

void ADTTimerPlatform::DisappearPlatform()
{
	SetPlatformActive(false);

	// 사라진 뒤 RespawnDelay초 후에 나타남
	GetWorld()->GetTimerManager().SetTimer(RespawnTimerHandle, this, &ADTTimerPlatform::RespawnPlatform, RespawnDelay, false);
}

void ADTTimerPlatform::RespawnPlatform()
{
	SetPlatformActive(true);
}


