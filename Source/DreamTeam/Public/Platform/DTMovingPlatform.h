#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DTMovingPlatform.generated.h"

class USceneComponent;
class UStaticMeshComponent;

UCLASS()
class DREAMTEAM_API ADTMovingPlatform : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Value")
	FVector MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Value")
	float MaxRange;

public:	
	ADTMovingPlatform();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Item|Components")
	TObjectPtr<USceneComponent> SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item|Components")
	TObjectPtr<UStaticMeshComponent> MeshComp;

private:
	FVector StartLocation;

};
