#pragma once
#include <Animation/BlendSpaceBase.h>
#include "CoreMinimal.h"
#include <GameFramework/Actor.h>
#include "GameFramework/GameStateBase.h"
#include "PingPongState.generated.h"

class ABall;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FScoreChanged, int, Score);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBoolChanged, bool, State);

UCLASS(Blueprintable, BlueprintType)
class PINGPONGTESTPROJECT_API APingPongState : public AGameStateBase
{
	GENERATED_BODY()

public:
	APingPongState();

	UPROPERTY(BlueprintReadOnly, Category = "PingPong", Replicated, ReplicatedUsing=OnRep_FirstPlayerScore)
	int FirstPlayerScore;

	UPROPERTY(BlueprintReadOnly, Category = "PingPong", Replicated, ReplicatedUsing=OnRep_SecondPlayerScore)
	int SecondPlayerScore;
	
	UPROPERTY(BlueprintReadOnly, Category = "PingPong", Replicated, ReplicatedUsing=OnRep_GameReady)
	bool GameReady;

	UPROPERTY(BlueprintReadOnly, Replicated)
	ABall* Ball;

	UPROPERTY(BlueprintAssignable)
	FScoreChanged OnFirstPlayerScoreChanged;
	
	UPROPERTY(BlueprintAssignable)
	FScoreChanged OnSecondPlayerScoreChanged;
	
	UPROPERTY(BlueprintAssignable)
	FBoolChanged OnGameReadyChanged;
	
protected:
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UFUNCTION()
	void OnRep_FirstPlayerScore() const;

	UFUNCTION()
	void OnRep_SecondPlayerScore() const;
	
	UFUNCTION()
	void OnRep_GameReady() const;
};
