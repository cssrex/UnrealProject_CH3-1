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
	
public:	
	ADTTimerPlatform();

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	TObjectPtr<USceneComponent> SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item|Components")
	TObjectPtr<UStaticMeshComponent> MeshComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	TObjectPtr<UBoxComponent> BoxCollision;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|Value");
	float DisappearDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item|Value");
	float RespawnDelay;

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
