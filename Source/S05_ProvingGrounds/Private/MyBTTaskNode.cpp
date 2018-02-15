// Copyright Aaron Gravelle

#include "MyBTTaskNode.h"

//EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
//{
//	UE_LOG(LogTemp, Warning, TEXT("ExecuteTask is working."))
//	return EBTNodeResult::Succeeded;
//}

EBTNodeResult::Type UMyBTTaskNode::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	UE_LOG(LogTemp, Warning, TEXT("ExecuteTask is working."))
	return EBTNodeResult::Succeeded;
}
