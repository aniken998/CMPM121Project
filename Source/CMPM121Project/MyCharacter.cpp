// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

#include "ConstructorHelpers.h"

#include "SpwanActor.h"

#include "Animation/AnimBlueprint.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	ConstructorHelpers::FObjectFinder <USkeletalMesh> MeshContainer(TEXT("SkeletalMesh'/Game/MyContent/Character/akai_e_espiritu.akai_e_espiritu'"));
	if (MeshContainer.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(MeshContainer.Object);
		GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -102.0f));
		GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	}
	ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimObj(TEXT("AnimBlueprint'/Game/MyContent/Character/Animation/AkaiAnimationBP.AkaiAnimationBP'"));
	if(AnimObj.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(AnimObj.Object->GeneratedClass);
	}

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 600.0f;
	GetCharacterMovement()->AirControl = 0.2f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);

	CameraBoom->TargetArmLength = 300.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->MaxWalkSpeed = 300.0f;

	Tags.Add(FName(TEXT("Player")));

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AMyCharacter::OnOverlapBegin);
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
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Running", IE_Pressed, this, &AMyCharacter::Running);
	PlayerInputComponent->BindAction("Running", IE_Released, this, &AMyCharacter::StopRunning);
}


void AMyCharacter::MoveForward(float Axis)
{
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(Direction, Axis);
}

void AMyCharacter::MoveRight(float Axis)
{
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(Direction, Axis);
}

void AMyCharacter::Running()
{
	if (powerUp)
	{
		GetCharacterMovement()->MaxWalkSpeed = 1000.0f;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	}
}

void AMyCharacter::StopRunning()
{
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;

}

void AMyCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<ASpwanActor>(OtherActor) != NULL)
	{
		OtherActor->Destroy();
		powerUp = true;
		if (GetCharacterMovement()->MaxWalkSpeed == 600)
		{
			GetCharacterMovement()->MaxWalkSpeed = 1000.0f;
		}
	}
}







