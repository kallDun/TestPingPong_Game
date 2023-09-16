#include "Gameplay/Ball.h"

#include "Gameplay/Goal.h"
#include "Gameplay/PlayerPlatform.h"


ABall::ABall()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	bReplicates = true;
	AActor::SetReplicateMovement(true);
	PrimaryActorTick.bCanEverTick = true;
}

void ABall::BeginPlay()
{
	Super::BeginPlay();
	if (HasAuthority())
	{
		const float RandomX = FMath::RandBool() ? -1 : 1;
		const float RandomY = FMath::RandBool() ? -1 : 1;
		Direction = FVector(RandomX, RandomY, 0.0f);

		Mesh->OnComponentBeginOverlap.AddDynamic(this, &ABall::OnMeshBeginOverlap);
	}
}

void ABall::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (HasAuthority())
	{
		const FVector NewLocation = GetActorLocation() + Direction * Speed * DeltaSeconds;
		SetActorLocation(NewLocation);
	}
}

void ABall::OnMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (HasAuthority())
	{
		if (Cast<AGoal>(OtherActor))
		{
			return;
		}
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow,
FString::Printf(TEXT("Collision with %s"), *OtherComp->GetName()));
		if (Cast<APlayerPlatform>(OtherActor))
		{
			Direction = FVector(-Direction.X, Direction.Y, Direction.Z);
			GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Emerald,
				FString::Printf(TEXT("Collision platform!")));
		}
		else
		{
			Direction = FVector(Direction.X, -Direction.Y, Direction.Z);
		}
	}
}
