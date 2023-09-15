


#include "Gameplay/CustomPlayerController.h"


// Sets default values
ACustomPlayerController::ACustomPlayerController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

