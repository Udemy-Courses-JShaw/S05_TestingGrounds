// MetalMuffin Entertainmnent ©2020


#include "PatrolRouteComponent.h"

TArray<AActor*> UPatrolRouteComponent::GetPatrolPoints() const
{
	return PatrolPointsCPP;
}
