#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DTRotationPlatform.generated.h"

class USceneComponent;
class UStaticMeshComponent;

UCLASS()
class DREAMTEAM_API ADTRotationPlatform : public AActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Value")
	FRotator RotationSpeed;

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


};
