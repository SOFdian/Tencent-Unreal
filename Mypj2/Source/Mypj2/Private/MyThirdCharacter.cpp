// Fill out your copyright notice in the Description page of Project Settings.


#include "MyThirdCharacter.h"

// Sets default values
AMyThirdCharacter::AMyThirdCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyThirdCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyThirdCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyThirdCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

