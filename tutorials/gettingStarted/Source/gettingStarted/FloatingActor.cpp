// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"

// Sets default values
// constructor of functions
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    // set VisualMesh reference to a static mesh component
    VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
    // attach to the Actor
    VisualMesh -> SetupAttachment(RootComponent);
    // load the asset
    static ConstructorHelpers::FObjectFinder<UStaticMesh>
        CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
    // if asset successfully loaded
    if (CubeVisualAsset.Succeeded())
    {
        // set it to the cube mesh from starter assets to the Actor
        VisualMesh -> SetStaticMesh(CubeVisualAsset.Object);
        // set the start position of Actor
        VisualMesh -> SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    }
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
    // fetch the current location of Actor
    FVector NewLocation = GetActorLocation();
    // fetch the current rotation of Actor
    FRotator NewRotation = GetActorRotation();
    // values for calculations
    float RunningTime = GetGameTimeSinceCreation();
    float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
    // Scale height by factor of 20
    NewLocation.Z += DeltaHeight * 20.0f;
    // Rotate by 20 degrees per second
    float DeltaRotation = DeltaTime * 20.0f;
    NewRotation.Yaw += DeltaRotation;
    // set the updated location and rotation of Actor
    SetActorLocationAndRotation(NewLocation, NewRotation);
}

