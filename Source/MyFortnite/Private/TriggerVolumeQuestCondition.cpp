// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerVolumeQuestCondition.h"
#include "QuestSystemComponent.h"
#include "Quest.h"

void UTriggerVolumeQuestCondition::StartCondition()
{
    AQuest* Quest = Cast<AQuest>(GetOuter());
    if (!Quest) return;

    UE_LOG(LogQuest, Log, TEXT("Started conditions"));
    Quest->OnActorBeginOverlap.AddDynamic(this, &UTriggerVolumeQuestCondition::StartOverlap);
    Quest->OnActorEndOverlap.AddDynamic(this, &UTriggerVolumeQuestCondition::StopOverlap);
}

void UTriggerVolumeQuestCondition::StopCondition()
{
    AQuest* Quest = Cast<AQuest>(GetOuter());
    if (!Quest) return;

    UE_LOG(LogQuest, Log, TEXT("Stopped conditions"));
    Quest->OnActorBeginOverlap.RemoveDynamic(this, &UTriggerVolumeQuestCondition::StartOverlap);
    Quest->OnActorEndOverlap.RemoveDynamic(this, &UTriggerVolumeQuestCondition::StopOverlap);
}

void UTriggerVolumeQuestCondition::StartOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
    if (OtherActor && OtherActor->ActorHasTag(OtherTag))
    {
        if (!bCompleteOnExit)
        {
            Complete();
            UE_LOG(LogQuest, Log, TEXT("Trigger Volume Quest Condition completed"));
        }
    }
}

void UTriggerVolumeQuestCondition::StopOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
    if (OtherActor && OtherActor->ActorHasTag(OtherTag))
    {
        if (bCompleteOnExit)
        {
            Complete();
            UE_LOG(LogQuest, Log, TEXT("Trigger Volume Quest Condition completed"));
        }
    }
}

