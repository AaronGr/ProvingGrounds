// Copyright Aaron Gravelle

#include "MyBTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"

//EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
//{
//	UE_LOG(LogTemp, Warning, TEXT("ExecuteTask is working."))
//	return EBTNodeResult::Succeeded;
//}

EBTNodeResult::Type UMyBTTaskNode::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	UE_LOG(LogTemp, Warning, TEXT("Waypoint index: %i"), Index)
	return EBTNodeResult::Succeeded;
}
