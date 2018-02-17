// Copyright Aaron Gravelle

#include "MyBTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolPoints.h"

EBTNodeResult::Type UMyBTTaskNode::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	// Get patrol points
	auto AIController = OwnerComp.GetAIOwner();
	if (!AIController) { return EBTNodeResult::Failed; }
	auto ControlledPawn = AIController->GetPawn();
	if (!ControlledPawn) { return EBTNodeResult::Failed; }
	auto PatrolPointsComponent = ControlledPawn->FindComponentByClass<UPatrolPoints>();
	if (!PatrolPointsComponent) { return EBTNodeResult::Failed; }
	auto PatrolPoints = PatrolPointsComponent->GetPatrolPoints();
	if (PatrolPoints.Num() == 0) {
		UE_LOG(LogTemp, Warning, TEXT("Guard is missing patrol points"))
		return EBTNodeResult::Failed; 
	}

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
