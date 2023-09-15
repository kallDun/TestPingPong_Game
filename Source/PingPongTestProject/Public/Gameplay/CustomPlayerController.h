#pragma once

#include "CoreMinimal.h"
#include <GameFramework/Actor.h>
#include "CustomPlayerController.generated.h"

UCLASS()
class PINGPONGTESTPROJECT_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACustomPlayerController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
