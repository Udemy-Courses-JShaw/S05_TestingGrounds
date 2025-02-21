// MetalMuffin Entertainmnent ©2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolRouteComponent.generated.h"

/**
**  A component that give the AI a list of points to navigate to
*/

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class S05_TESTINGGROUNDS_API UPatrolRouteComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	TArray<AActor*> GetPatrolPoints() const;

private:	
	UPROPERTY(EditInstanceOnly, Category = "Patrol Route")
	TArray<AActor*> PatrolPointsCPP;

		
};
