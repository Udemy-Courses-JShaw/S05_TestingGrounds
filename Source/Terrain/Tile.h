// MetalMuffin Entertainmnent ©2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

UCLASS()
class S05_TESTINGGROUNDS_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void PlaceActors(TSubclassOf<AActor> ToSpawn, float Radius = 500.f, float MinScale = 1.f, float MaxScale = 1.f);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void RemovePlacedActors(TArray<AActor*> ActorsOnTile);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup", meta = (AllowPrivateAccess = "true"))
	TArray<AActor*> ActorsPlacedOnTile; //Store reference to actor to garbage collect upon Destroy Tile

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool FindEmptyLocation(FVector& OutLocation, float Radius);

	void SpawnActorInWorld(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint, float Scale);

	bool CanSpawnAtLocation(FVector Location, float Radius);

};
