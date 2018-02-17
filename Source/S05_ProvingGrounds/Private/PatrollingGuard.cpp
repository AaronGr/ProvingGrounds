// Copyright Aaron Gravelle

#include "PatrollingGuard.h"

TArray<AActor*> APatrollingGuard::GetPatrolPoints() const
{
	return PatrolPointsCPP;
}


