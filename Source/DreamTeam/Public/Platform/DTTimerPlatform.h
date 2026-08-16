#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DTTimerPlatform.generated.h"

UCLASS()
class DREAMTEAM_API ADTTimerPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	ADTTimerPlatform();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
