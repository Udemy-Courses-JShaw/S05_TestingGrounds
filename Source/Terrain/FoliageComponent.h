// MetalMuffin Entertainmnent ©2020

#pragma once

#include "CoreMinimal.h"
#include "FoliageInstancedStaticMeshComponent.h"
#include "FoliageComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class S05_TESTINGGROUNDS_API UFoliageComponent : public UFoliageInstancedStaticMeshComponent
{
	GENERATED_BODY()

public:
	//Sets Defaults
	UFoliageComponent();
	
	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FBox SpawningExtents;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	int SpawnCount;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	//Called at Gmae Start
	virtual void TickComponent(float DeltaTime, ELevelTick TickTypes, FActorComponentTickFunction* ThisTickFunction) override;

private:
	void SpawnFoliage();





};
