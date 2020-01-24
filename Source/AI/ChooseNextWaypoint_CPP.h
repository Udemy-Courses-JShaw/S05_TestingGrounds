// Copyright 2020

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ChooseNextWaypoint_CPP.generated.h"

/**
 *	Used by AI to choose the next waypoint while on Patrol
 */
UCLASS()
class S05_TESTINGGROUNDS_API UChooseNextWaypoint_CPP : public UBTTaskNode
{
	GENERATED_BODY()

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector Index;
	
};
