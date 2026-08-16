#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DTPlatformManager.generated.h"

class USceneComponent;
class UBoxComponent;

UCLASS()
class DREAMTEAM_API ADTPlatformManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ADTPlatformManager();

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	TObjectPtr<USceneComponent> SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Components")
	TObjectPtr<UBoxComponent> SpawnArea;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Value")
	TSubclassOf<AActor> PlatformClasses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Value")
	int32 SpawnCount;

private:
	void SpawnPlatform();

};
