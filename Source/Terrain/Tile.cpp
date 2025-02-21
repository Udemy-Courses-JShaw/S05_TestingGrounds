// MetalMuffin Entertainmnent ©2020


#include "Tile.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Math/Box.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();


}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATile::PlaceActors(TSubclassOf<AActor> ToSpawn, float Radius, float MinScale, float MaxScale)
{
	FVector SpawnPoint;
	float RandomScale = FMath::RandRange(MinScale, MaxScale);
	bool found = FindEmptyLocation(SpawnPoint, Radius * RandomScale);
	if (found)
	{
		SpawnActorInWorld(ToSpawn, SpawnPoint, RandomScale);
	}
}

bool ATile::FindEmptyLocation(FVector& OutLocation, float Radius)
{
	FVector Min(0, -2000, 0);
	FVector Max(4000, 2000, 0);
	FBox Bounds(Min, Max);
	const int MAX_ATTEMPTS = 25;


	for (size_t i = 0; i < MAX_ATTEMPTS; i++)
	{
		FVector CandidatePoint = FMath::RandPointInBox(Bounds);
		if (CanSpawnAtLocation(CandidatePoint, Radius))
		{
			OutLocation = CandidatePoint;
			return true;
		}
	}

	return false;
}

void ATile::SpawnActorInWorld(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint, float Scale)
{
	float RandRotation = FMath::RandRange(0.f, 360.f);
	FRotator SpawnRotation = {0.f, RandRotation, 0.f };

	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ToSpawn);
	SpawnedActor->SetActorRelativeRotation(SpawnRotation);
	SpawnedActor->SetActorRelativeLocation(SpawnPoint);
	SpawnedActor->SetActorScale3D(FVector(Scale));
	SpawnedActor->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));

	//ActorsPlacedOnTile.Add(SpawnedActor);
}

//Returns true if hit in radius
bool ATile::CanSpawnAtLocation(FVector Location, float Radius)
{
	FHitResult HitResult;
	FVector GlobalLocation = ActorToWorld().TransformPosition(Location);
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		GlobalLocation,
		GlobalLocation,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2, //SpawnTest custom channel
		FCollisionShape::MakeSphere(Radius)
	);

	FColor HitColor;
	if (HasHit) 
	{
		HitColor = FColor::Red;
	}
	else
	{
		HitColor = FColor::Green;
	}

	/*		// Saving for later use if needed
	DrawDebugSphere(
		GetWorld(),
		GlobalLocation,
		Radius,
		20,
		HitColor,
		true,
		100.f
		);
	*/

	return !HasHit;
}

void ATile::RemovePlacedActors(TArray<AActor*> ActorsOnTile)
{
	for (size_t i = 0; i < ActorsOnTile.Num(); i++)
	{
		ActorsOnTile[i]->Destroy();
	}
}
