// Copyright Epic Games, Inc. All Rights Reserved.

#include "Core/PingPongTestProjectGameModeBase.h"
#include "Core/PingPongState.h"
#include "Gameplay/Ball.h"
#include "Gameplay/Goal.h"
#include "Gameplay/PingPongPlayerController.h"
#include "Gameplay/PlayerPlatform.h"

void APingPongTestProjectGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	if (APingPongPlayerController* Player = Cast<APingPongPlayerController>(NewPlayer))
	{
		Players.Add(Player);
	}
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,
		FString::Printf(TEXT("Player %d Post Login"), Players.Num()));
	if (Players.Num() == 2)
	{
		SetupPlayers();
		StartNewGame();
	}
}

void APingPongTestProjectGameModeBase::SetupPlayers()
{
	PlayerPlatforms.Add(Cast<APlayerPlatform>(Players[0]->GetPawn()));
	PlayerPlatforms.Add(Cast<APlayerPlatform>(Players[1]->GetPawn()));
	PlayerPlatforms[0]->PlayerIndex = 1;
	PlayerPlatforms[1]->PlayerIndex = 2;
	SetupGoal(FirstGoalPosition, 2);
	SetupGoal(SecondGoalPosition, 1);
}

void APingPongTestProjectGameModeBase::StartNewGame() const
{
	PlayerPlatforms[0]->CenterPosition = FirstPlayerPosition;
	PlayerPlatforms[1]->CenterPosition = SecondPlayerPosition;

	APingPongState* PingPongState = GetGameState<APingPongState>();
	if (PingPongState)
	{
		if (PingPongState->Ball == nullptr)
		{
			SpawnBall();
		}
		PingPongState->FirstPlayerScore = 0;
		PingPongState->SecondPlayerScore = 0;
		PingPongState->GameReady = true;
		PingPongState->Ball->SetActorLocation(BallSpawnLocation);
	}
}

void APingPongTestProjectGameModeBase::SpawnBall() const
{
	APingPongState* PingPongState = GetGameState<APingPongState>();
	if (PingPongState)
	{
		auto Params = FActorSpawnParameters();
		Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		PingPongState->Ball = GetWorld()->SpawnActor<ABall>(BallClass, BallSpawnLocation, FRotator::ZeroRotator, Params);
	}
}

void APingPongTestProjectGameModeBase::AddScore(const int PlayerIndex) const
{
	APingPongState* PingPongState = GetGameState<APingPongState>();
	if (PingPongState)
	{
		if (PlayerIndex == 1)
		{
			PingPongState->FirstPlayerScore++;
		}
		else if (PlayerIndex == 2)
		{
			PingPongState->SecondPlayerScore++;
		}
		PingPongState->Ball->SetActorLocation(BallSpawnLocation);
		
		if (PingPongState->FirstPlayerScore == MaxScore || PingPongState->SecondPlayerScore == MaxScore)
		{
			StartNewGame();
		}
	}
}

void APingPongTestProjectGameModeBase::SetupGoal(const FVector GoalPosition, const int EnemyPlayerIndex)
{
	auto Params = FActorSpawnParameters();
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AGoal* Goal = GetWorld()->SpawnActor<AGoal>(GoalClass, GoalPosition, FRotator::ZeroRotator, Params);
	Goal->GameMode = this;
	Goal->EnemyPlayerIndex = EnemyPlayerIndex;
}
