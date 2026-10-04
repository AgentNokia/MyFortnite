// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerVolumeQuestCondition.h"

#include "Quest.h"

void UTriggerVolumeQuestCondition::StartCondition()
{
  AQuest *Quest = Cast<AQuest>(GetOuter());
  if (bCompleteOnExit)
    Quest->OnActorEndOverlap.AddDynamic(this, &UTriggerVolumeQuestCondition::StartOverlap);
  else
    Quest->OnActorBeginOverlap.AddDynamic(this, &UTriggerVolumeQuestCondition::StartOverlap);
}

void UTriggerVolumeQuestCondition::StopCondition()
{
  AQuest *Quest = Cast<AQuest>(GetOuter());
  Quest->OnActorBeginOverlap.RemoveDynamic(this, &UTriggerVolumeQuestCondition::StartOverlap);
  Quest->OnActorEndOverlap.RemoveDynamic(this, &UTriggerVolumeQuestCondition::StartOverlap);
}

void UTriggerVolumeQuestCondition::StartOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
  if (OtherActor->ActorHasTag(OtherTag))
  {
    Complete();
  }

}
