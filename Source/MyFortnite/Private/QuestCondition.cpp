// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestCondition.h"

DEFINE_LOG_CATEGORY(LogQuest)

void UQuestCondition::Complete()
{
  UE_LOG(LogQuest, Log, TEXT("Quest completed"));
	bCompleted = true;
	OnQuestConditionCompleted.Broadcast();
  StopCondition();
}
