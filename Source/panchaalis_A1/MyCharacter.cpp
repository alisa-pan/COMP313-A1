// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "AppleActor.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//tutorial code 
	//Create a first person camera component
	TPCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCamera"));
	check(TPCameraComponent != nullptr);

	//attach camera component to the character's capsule component (the little capsule-shaped cage around them)
	TPCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));

	//position camera
	TPCameraComponent->SetRelativeLocation(FVector(-75.0f, 0.0f, 25.0f));

	//enable pawn to control camera rotation
	TPCameraComponent->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	//code from tutorial: https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/ProgrammingWithCPP/CPPTutorials/FirstPersonShooter/2/
	//checks that this MyCharacter class is being used by printing a message onscreen when the game starts 
	check(GEngine != nullptr);

	//Display a debug message for 5 seconds
	//The -1 "Key" value argument prevents the message from being updated or refreshed
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("We are using MyCharacter."));
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

	//tutorial code (link above)
	
	//Set up "movement" bindings.
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);

	//Set up "look" bindings
	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput); //side-to-side
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::AddControllerPitchInput); //up-and-down

	//Set up "action" bindings 
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJump);
}

//tutorial code (link above)
void AMyCharacter::MoveForward(float Value)
{
	// Find out which way is "forward" and record that the player wants to move that way
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AMyCharacter::MoveRight(float Value)
{
	// Find out which way is "Right" and record that the player wants to move that way 
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AMyCharacter::StartJump() {
	bPressedJump = true;
}

void AMyCharacter::StopJump() {
	bPressedJump = false;
}
//end tutorial code

