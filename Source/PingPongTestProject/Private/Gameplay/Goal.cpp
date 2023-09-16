// Fill out your copyright notice in the Description page of Project Settings.

#include "Gameplay/Goal.h"
#include "Components/BoxComponent.h"
#include "Core/PingPongTestProjectGameModeBase.h"
#include "Gameplay/Ball.h"


AGoal::AGoal()
{
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AGoal::OnOverlapBegin);
}

void AGoal::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (auto Ball = Cast<ABall>(OtherActor))
	{
		if (GameMode)
		{
			GameMode->AddScore(EnemyPlayerIndex);
		}
	}
}

