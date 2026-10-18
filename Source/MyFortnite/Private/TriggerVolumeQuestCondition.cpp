// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerVolumeQuestCondition.h"
#include "QuestSystemComponent.h"
#include "Quest.h"

void UTriggerVolumeQuestCondition::StartCondition()
{
    AQuest* Quest = Cast<AQuest>(GetOuter());
    if (!Quest) return;

    Quest->OnActorBeginOverlap.AddDynamic(this, &UTriggerVolumeQuestCondition::StartOverlap);
    Quest->OnActorEndOverlap.AddDynamic(this, &UTriggerVolumeQuestCondition::StopOverlap);
}

void UTriggerVolumeQuestCondition::StopCondition()
{
    AQuest* Quest = Cast<AQuest>(GetOuter());
    if (!Quest) return;

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
        }
    }
}

