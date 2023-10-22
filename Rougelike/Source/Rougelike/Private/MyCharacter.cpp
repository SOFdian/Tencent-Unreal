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
	//类似于在Unity中，让SpringArm作为Camera的父物体
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

	//有了下面这行函数后，就可以在项目设置->轴映射中，设置MoveForward对应的键位
	//按下W->映射到MoveForward->MoveForward和&AMyCharacter::MoveForward绑定了，调用MoveForward
	PlayerInputComponent->BindAxis("MoveForward",this,&AMyCharacter::MoveForward);

	//Yaw是水平的，Pitch是垂直的
	//Pitch绕Y轴旋转。Yaw绕Z轴旋转。Roll绕X轴旋转
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	//还要允许使用控制器控制Pitch才能生效（bUseControllerRotationYaw一开始就是true）
	bUseControllerRotationPitch = true;
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);


	//打印信息
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Yellow, TEXT("Hello world"));
	
}

//在项目设置->轴映射中设置了缩放，缩放为-1的话，Value就是-1
void AMyCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

