// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Goal.generated.h"

class APingPongTestProjectGameModeBase;

UCLASS(Abstract, Blueprintable, BlueprintType)
class PINGPONGTESTPROJECT_API AGoal : public AActor
{
	GENERATED_BODY()

public:
	AGoal();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UBoxComponent* BoxComponent;

	UPROPERTY(BlueprintReadOnly)
	APingPongTestProjectGameModeBase* GameMode;
	
	UPROPERTY(BlueprintReadOnly)
	int EnemyPlayerIndex = 0;

private:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
