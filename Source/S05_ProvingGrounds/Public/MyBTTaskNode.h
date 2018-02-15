// Copyright Aaron Gravelle

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "MyBTTaskNode.generated.h"

/**
 * AI Patrol Behavior
 */
UCLASS()
class S05_PROVINGGROUNDS_API UMyBTTaskNode : public UBTTaskNode
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override; // TODO perhaps change protection level

};
