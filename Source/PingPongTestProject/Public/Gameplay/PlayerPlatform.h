#pragma once
#include "CoreMinimal.h"
#include <GameFramework/Pawn.h>
#include "PlayerPlatform.generated.h"

class AGoal;

UCLASS(Abstract, Blueprintable, BlueprintType)
class PINGPONGTESTPROJECT_API APlayerPlatform : public APawn
{
	GENERATED_BODY()

public:
	APlayerPlatform();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UStaticMeshComponent* Root;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* PlatformMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MinPlatformRelativePosition;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxPlatformRelativePosition;
	
	UPROPERTY(BlueprintReadOnly)
	int PlayerIndex = 0;

	UPROPERTY(BlueprintReadWrite, Replicated, ReplicatedUsing=OnRep_CenterPosition)
	FVector CenterPosition;

	UPROPERTY(BlueprintReadWrite, Replicated, ReplicatedUsing=OnRep_PlatformRelativePosition)
	float PlatformRelativePosition;

protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(BlueprintCallable, Server, Reliable)
	void AddPlatformRelativePosition(const float Value);
	
	UFUNCTION()
	void OnRep_CenterPosition();

	UFUNCTION()
	void OnRep_PlatformRelativePosition();
};
