#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DTTimerPlatform.generated.h"

class USceneComponent;
class UStaticMeshComponent;
class UBoxComponent;

UCLASS()
class DREAMTEAM_API ADTTimerPlatform : public AActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|Value");
	float DisappearDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|Value");
	float RespawnDelay;

public:	
	ADTTimerPlatform();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	TObjectPtr<USceneComponent> SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item|Components")
	TObjectPtr<UStaticMeshComponent> MeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	TObjectPtr<UBoxComponent> BoxCollision;

private:
	UFUNCTION()
	void OnTriggerBeginOverlap(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

	void SetPlatformActive(bool bActive);
	void DisappearPlatform();
	void RespawnPlatform();

	FTimerHandle DisappearTimerHandle;
	FTimerHandle RespawnTimerHandle;
};
