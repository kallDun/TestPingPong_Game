// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PingPongTestProjectGameModeBase.generated.h"

class APingPongPlayerController;
class AGoal;
class APlayerPlatform;
class ABall;

UCLASS()
class PINGPONGTESTPROJECT_API APingPongTestProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PingPong")
	TSubclassOf<ABall> BallClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PingPong")
	TSubclassOf<AGoal> GoalClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PingPong")
	FVector BallSpawnLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PingPong")
	FVector FirstPlayerPosition;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PingPong")
	FVector SecondPlayerPosition;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PingPong")
	FVector FirstGoalPosition;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PingPong")
	FVector SecondGoalPosition;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PingPong")
	int MaxScore = 10;

protected:
	UPROPERTY(BlueprintReadOnly)
	TArray<APingPongPlayerController*> Players = {};
	
	UPROPERTY(BlueprintReadOnly)
	TArray<APlayerPlatform*> PlayerPlatforms = {};

public:
	UFUNCTION(BlueprintCallable)
	void AddScore(const int PlayerIndex) const;

protected:
	UFUNCTION()
	void SetupPlayers();

	UFUNCTION(BlueprintCallable)
	void SetupGoal(FVector GoalPosition, int EnemyPlayerIndex);

	UFUNCTION(BlueprintCallable)
	void SpawnBall() const;
	
	UFUNCTION()
	void StartNewGame() const;
	
	virtual void PostLogin(APlayerController* NewPlayer) override;
};
