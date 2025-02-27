// MetalMuffin Entertainmnent ©2020


#include "InfiniteTerrainGameMode.h"
#include "EngineUtils.h"
#include "NavMesh/NavMeshBoundsVolume.h"

void AInfiniteTerrainGameMode::PopulateBoundsVolumePool()
{
	auto VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (VolumeIterator)
	{
		AddToPool(*VolumeIterator);
		++VolumeIterator;
	}
}


void AInfiniteTerrainGameMode::AddToPool(ANavMeshBoundsVolume *VolumeToAdd)
{
	UE_LOG(LogTemp, Warning, TEXT("Found Actor: %s"), *VolumeToAdd->GetName());
}