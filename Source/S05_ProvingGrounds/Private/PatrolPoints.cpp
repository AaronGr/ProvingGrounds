// Copyright Aaron Gravelle

#include "PatrolPoints.h"

TArray<AActor*> UPatrolPoints::GetPatrolPoints() const
{
	return PatrolPointsCPP;
}
