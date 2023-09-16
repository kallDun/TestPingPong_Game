#include "Gameplay/PlayerPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"


APlayerPlatform::APlayerPlatform()
{
	Root = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
	RootComponent = Root;
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	PlatformMesh->SetupAttachment(RootComponent);
	bReplicates = true;
	AActor::SetReplicateMovement(true);
}

void APlayerPlatform::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(APlayerPlatform, CenterPosition);
	DOREPLIFETIME(APlayerPlatform, PlatformRelativePosition);
}

void APlayerPlatform::AddPlatformRelativePosition_Implementation(const float Value)
{
	PlatformRelativePosition = FMath::Clamp(PlatformRelativePosition + Value, MinPlatformRelativePosition, MaxPlatformRelativePosition);
	PlatformMesh->SetRelativeLocation(FVector(0.0f, PlatformRelativePosition, 0.0f));
}

void APlayerPlatform::SetCenterPosition(const FVector& Value)
{
	CenterPosition = Value;
	SetActorLocation(CenterPosition);
}

void APlayerPlatform::OnRep_CenterPosition()
{
	SetActorLocation(CenterPosition);
}

void APlayerPlatform::OnRep_PlatformRelativePosition() const
{
	PlatformMesh->SetRelativeLocation(FVector(0.0f, PlatformRelativePosition, 0.0f));
}
