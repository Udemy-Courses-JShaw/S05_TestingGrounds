// MetalMuffin Entertainmnent ©2020

#pragma once

#include "CoreMinimal.h"
#include "GameMode/S05_TestingGroundsGameMode.h"
#include "NavMesh/NavMeshBoundsVolume.h"
//Last
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API AInfiniteTerrainGameMode : public AS05_TestingGroundsGameMode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

private:
	void AddToPool(class ANavMeshBoundsVolume* VolumeToAdd);

};
