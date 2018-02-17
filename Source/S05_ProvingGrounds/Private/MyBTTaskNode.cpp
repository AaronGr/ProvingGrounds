// Copyright Aaron Gravelle

#include "MyBTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h"

EBTNodeResult::Type UMyBTTaskNode::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	

	// Get patrol points
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	if (!PatrollingGuard) {return EBTNodeResult::Failed;}
	auto PatrolPoints = PatrollingGuard->GetPatrolPoints();

	// Set Next Waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

	// Cycle Index
	++Index;
	if (Index % PatrolPoints.Max() == 0) { Index = 0;}
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index);

	// UE_LOG(LogTemp, Warning, TEXT("Waypoint Value: %s"), *(PatrolPoints[Index].ToString()))
	return EBTNodeResult::Succeeded;
}
