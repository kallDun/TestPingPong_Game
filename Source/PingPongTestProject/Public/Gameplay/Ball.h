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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Speed = 1000.0f;

	UPROPERTY(BlueprintReadOnly)
	FVector Direction = FVector::ZeroVector;

protected:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
	void OnMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
