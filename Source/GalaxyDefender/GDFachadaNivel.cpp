#include "GDFachadaNivel.h"
#include "UGDRegistroNivel.h"
#include "GDConstructorNivel.h"
#include "GDDirectorNivel.h"

AGDFachadaNivel::AGDFachadaNivel()
{
	// ¡CAMBIO CRITICO! Ahora la Fachada puede "pensar" cada frame
	PrimaryActorTick.bCanEverTick = true;

	NivelActual = 1;
	bNivelEnProgreso = false;
}

void AGDFachadaNivel::BeginPlay()
{
	Super::BeginPlay();

	Registro = NewObject<UUGDRegistroNivel>(this);
	Constructor = NewObject<UGDConstructorNivel>(this);
	Director = NewObject<UGDDirectorNivel>(this);

	Constructor->SetRegistro(Registro);
	UE_LOG(LogTemp, Warning, TEXT("Fachada: Sistema Operacion Nebulosa inicializado y listo."));

	NivelActual = 1;
	IniciarNivel(NivelActual);
}

void AGDFachadaNivel::IniciarNivel(int32 NumeroNivel)
{
	if (Director && Constructor)
	{
		bNivelEnProgreso = false; // Pausamos la vigilancia mientras construimos

		UE_LOG(LogTemp, Warning, TEXT("Fachada: Construyendo Nivel %d..."), NumeroNivel);
		LimpiarNivelActual();
		Director->ConstruirNivel(NumeroNivel, Constructor);

		bNivelEnProgreso = true; // Reanudamos la vigilancia
	}
}

void AGDFachadaNivel::LimpiarNivelActual()
{
	if (Registro)
	{
		Registro->LimpiarRegistro();
	}
}

// ¡LA MAGIA DEL GAME LOOP!
void AGDFachadaNivel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Solo vigilamos si hay un nivel jugándose y si el registro existe
	if (bNivelEnProgreso && Registro)
	{
		int32 EnemigosVivos = 0;

		// Contamos cuántos enemigos siguen vivos en la lista
		for (AActor* Enemigo : Registro->Enemigos)
		{
			if (IsValid(Enemigo)) // Si no ha sido destruido por el jugador...
			{
				EnemigosVivos++;
			}
		}

		// Condición de victoria: El nivel empezó (hay items en la lista) pero vivos quedan 0
		if (EnemigosVivos == 0 && Registro->Enemigos.Num() > 0)
		{
			bNivelEnProgreso = false; // Bloqueamos para no saltar niveles de golpe
			NivelActual++; // Subimos de nivel

			if (NivelActual <= 3)
			{
				UE_LOG(LogTemp, Warning, TEXT("Fachada: ¡ZONA DESPEJADA! Avanzando al Nivel %d..."), NivelActual);
				IniciarNivel(NivelActual);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Fachada: ¡TODOS LOS NIVELES COMPLETADOS! VICTORIA MAGISTRAL."));
			}
		}
	}
}