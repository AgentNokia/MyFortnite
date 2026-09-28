// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestCondition.h"
#include "TriggerVolumeQuestCondition.generated.h"

/**
 * 
 */
UCLASS()
class MYFORTNITE_API UTriggerVolumeQuestCondition : public UQuestCondition
{
	GENERATED_BODY()
public:
	virtual void StartCondition() override;
	virtual void StopCondition() override;

	UFUNCTION()
	void StartOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(EditAnywhere)
	FName OtherTag;
};
