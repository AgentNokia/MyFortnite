// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerVolumeQuestCondition.h"

#include "Quest.h"

void UTriggerVolumeQuestCondition::StartCondition()
{
  AQuest *Quest = Cast<AQuest>(GetOuter());
  Quest->OnActorBeginOverlap.AddDynamic(this, &UTriggerVolumeQuestCondition::StartOverlap);
}

void UTriggerVolumeQuestCondition::StopCondition()
{
}

void UTriggerVolumeQuestCondition::StartOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
  if (OtherActor->ActorHasTag(OtherTag))
  {
    bCompleted = true;
  }

}
