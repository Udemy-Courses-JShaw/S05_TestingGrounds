// MetalMuffin Entertainmnent ©2020


#include "Weapon.h"
#include "Animation/AnimInstance.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"
#include "Weapons/S05_TestingGroundsProjectile.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a gun mesh component
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Weapon"));
	RootComponent = Weapon;
	Weapon->bCastDynamicShadow = false;
	Weapon->CastShadow = false;
	Weapon->SetupAttachment(RootComponent);

	Weapon_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
	Weapon_MuzzleLocation->SetupAttachment(Weapon);
	Weapon_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();

	//Attach gun mesh component to Skeleton, doing it here because the skeleton is not yet created in the constructor
	//Weapon->AttachToComponent(CharacterMesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));

	
}

// Called every frame
void AWeapon::Fire()
{
	//UE_LOG(LogTemp, Warning, TEXT("Trigger pulled!"));
	if (!ensure(ProjectileClass)) 
	{ 
		UE_LOG(LogTemp, Error, TEXT("No Projectile BP set!"));
		return; 
	}

	// try and fire a projectile
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		const FRotator SpawnRotation = Weapon_MuzzleLocation->GetComponentRotation();
		// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
		const FVector SpawnLocation = Weapon_MuzzleLocation->GetComponentLocation();

		////Set Spawn Collision Handling Override
		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		// spawn the projectile at the muzzle
		World->SpawnActor<AS05_TestingGroundsProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
	}

	// try and play the sound if specified
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	// Get the animation object for the arms mesh
	if (FireAnimation1p != nullptr && AnimInstance1p != nullptr)
	{
		AnimInstance1p->Montage_Play(FireAnimation1p, 1.f);
	}

	if (FireAnimation3p != nullptr && AnimInstance3p != nullptr)
	{
		AnimInstance3p->Montage_Play(FireAnimation3p, 1.f);
	}
	

}

