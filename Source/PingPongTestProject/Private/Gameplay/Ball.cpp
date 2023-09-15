#include "Gameplay/Ball.h"


ABall::ABall()
{
	bReplicates = true;
	AActor::SetReplicateMovement(true);
	PrimaryActorTick.bCanEverTick = true;
}

