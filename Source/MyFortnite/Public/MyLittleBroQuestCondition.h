// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "QuestCondition.h"
#include "MyLittleBroQuestCondition.generated.h"

/**
 * 
 */
UCLASS()
class MYFORTNITE_API UMyLittleBroQuestCondition : public UQuestCondition
{
	GENERATED_BODY()
public:
	virtual void StartCondition() override;
	virtual void StopCondition() override;	
};
