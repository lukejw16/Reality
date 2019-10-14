// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "RealityCharacter.h"
#include "VelocityChange.generated.h"

UCLASS()
class REALITY_API AVelocityChange : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVelocityChange();
	FVector AddAmount = FVector(100.0f, 10.0f, 300.0f);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float SpeedChange = 9000.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlapComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		UStaticMeshComponent* SphereMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = Collision)
		UBoxComponent* BoxCollision;

	UPROPERTY()
		ARealityCharacter* Character;

	UPROPERTY(EditDefaultsOnly)
		bool bIsForward;

	UPROPERTY(EditDefaultsOnly)
		bool bIsPlus;

	bool Reverse;

	FTimerHandle FOVTimer;

	void ChangeFieldOfView();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* BoostSound;
};
