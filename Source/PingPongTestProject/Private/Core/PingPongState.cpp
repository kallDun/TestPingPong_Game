#include "Core/PingPongState.h"
#include "Net/UnrealNetwork.h"


APingPongState::APingPongState()
{
	bReplicates = true;
}

void APingPongState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(APingPongState, FirstPlayerScore);
	DOREPLIFETIME(APingPongState, SecondPlayerScore);
	DOREPLIFETIME(APingPongState, GameReady);
	DOREPLIFETIME(APingPongState, Ball);
}

void APingPongState::OnRep_FirstPlayerScore() const
{
	OnFirstPlayerScoreChanged.Broadcast(FirstPlayerScore);
}

void APingPongState::OnRep_SecondPlayerScore() const
{
	OnSecondPlayerScoreChanged.Broadcast(SecondPlayerScore);
}

void APingPongState::OnRep_GameReady() const
{
	OnGameReadyChanged.Broadcast(GameReady);
}
