#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DTPlatformManager.generated.h"

UCLASS()
class DREAMTEAM_API ADTPlatformManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ADTPlatformManager();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
