#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DTRotationPlatform.generated.h"

UCLASS()
class DREAMTEAM_API ADTRotationPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ADTRotationPlatform();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	TObjectPtr<USceneComponent> SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item|Components")
	TObjectPtr<UStaticMeshComponent> MeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Value")
	FRotator RotationSpeed;
};
