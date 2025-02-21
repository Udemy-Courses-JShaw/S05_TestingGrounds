// MetalMuffin Entertainmnent ©2020

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

class UInputComponent;

UCLASS()
class S05_TESTINGGROUNDS_API AWeapon : public AActor
{
	GENERATED_BODY()

public:	
	// Character
	//UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	//class USkeletalMeshComponent* CharacterMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = "Mesh")
	class USkeletalMeshComponent* Weapon;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(BlueprintReadOnly, Category = "Mesh")
	class USceneComponent* Weapon_MuzzleLocation;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AS05_TestingGroundsProjectile> ProjectileClass;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	FVector GunOffset;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	class USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	class UAnimMontage* FireAnimation1p;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay")
	class UAnimMontage* FireAnimation3p;
	
	UPROPERTY(/*EditAnywhere, BlueprintReadWrite, Category = "Gameplay"*/)
	class UAnimInstance* AnimInstance1p;

	UPROPERTY(/*EditAnywhere, BlueprintReadWrite, Category = "Gameplay"*/)
	class UAnimInstance* AnimInstance3p;

	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void Fire();

};
