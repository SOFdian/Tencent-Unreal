// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(("Camera"));
	//��������Unity�У���SpringArm��ΪCamera�ĸ�����
	Camera->SetupAttachment(SpringArm);


}



// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//�����������к����󣬾Ϳ�������Ŀ����->��ӳ���У�����MoveForward��Ӧ�ļ�λ
	//����W->ӳ�䵽MoveForward->MoveForward��&AMyCharacter::MoveForward���ˣ�����MoveForward
	PlayerInputComponent->BindAxis("MoveForward",this,&AMyCharacter::MoveForward);

	//Yaw��ˮƽ�ģ�Pitch�Ǵ�ֱ��
	//Pitch��Y����ת��Yaw��Z����ת��Roll��X����ת
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	//��Ҫ����ʹ�ÿ���������Pitch������Ч��bUseControllerRotationYawһ��ʼ����true��
	bUseControllerRotationPitch = true;
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);


	//��ӡ��Ϣ
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, TEXT("Hello world"));
	
}

//����Ŀ����->��ӳ�������������ţ�����Ϊ-1�Ļ���Value����-1
void AMyCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

