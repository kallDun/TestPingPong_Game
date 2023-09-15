#pragma once
#include "CoreMinimal.h"
#include <GameFramework/Actor.h>
#include "Ball.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class PINGPONGTESTPROJECT_API ABall : public AActor
{
	GENERATED_BODY()

public:
	ABall();
};
