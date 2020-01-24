// Copyright 2020


#include "AI/ChooseNextWaypoint_CPP.h"

EBTNodeResult::Type UChooseNextWaypoint_CPP::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//UE_LOG(LogTemp, Warning, TEXT("BTTask CPP here.."));
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();


	return EBTNodeResult::Succeeded;
}