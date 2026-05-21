#include "GDConstructorNivel.h"
#include "UGDRegistroNivel.h" 
#include "GDSectorAbstractFactory.h" // Incluimos la base abstracta
#include "GDDecoradorVida.h"
#include "Engine/World.h"

void UGDConstructorNivel::SetRegistro(UUGDRegistroNivel* EnRegistro)
{
	RegistroActual = EnRegistro;
}

void UGDConstructorNivel::SetFabricaActual(UGDSectorAbstractFactory* NuevaFabrica)
{
	FabricaActual = NuevaFabrica;
}

void UGDConstructorNivel::ConstruirFondoEspacial()
{
	UE_LOG(LogTemp, Warning, TEXT("Constructor: Levantando entorno galáctico..."));
}

void UGDConstructorNivel::ConstruirMeteoritos()
{
	UWorld* World = GetWorld();
	if (!World || !RegistroActual || !FabricaActual) return;

	UE_LOG(LogTemp, Warning, TEXT("Constructor: Generando obstáculos con la fábrica del sector actual..."));

	for (int32 i = 0; i < 5; i++)
	{
		float PosY = FMath::RandRange(-1500.0f, 1500.0f);
		float PosZ = FMath::RandRange(-800.0f, 800.0f);
		FVector Posicion = FVector(2000.0f + (i * 600.0f), PosY, PosZ);
		FRotator Rotacion = FRotator(FMath::RandRange(0.0f, 360.0f), FMath::RandRange(0.0f, 360.0f), FMath::RandRange(0.0f, 360.0f));

		// La misma función sirve para cualquier nivel gracias al Abstract Factory
		AActor* NuevoObstaculo = FabricaActual->CrearObstaculoPrincipal(World, Posicion, Rotacion);
		if (NuevoObstaculo)
		{
			RegistroActual->RegistrarObstaculo(NuevoObstaculo);
		}
	}
}

void UGDConstructorNivel::ConstruirEnemigosBasicos()
{
	UWorld* World = GetWorld();
	if (!World || !RegistroActual || !FabricaActual) return;

	UE_LOG(LogTemp, Warning, TEXT("Constructor: Desplegando escuadron enemigo distribuido por codigo..."));

	// Automatizamos la creación de 3 naves enemigas esparcidas en el espacio
	for (int32 i = 0; i < 3; i++)
	{
		// Explicación de las coordenadas automáticas:
		// X = Profundidad (Se escalona con 'i * 800' para que unas naves estén más adelante que otras)
		// Y = Ancho del mapa (Izquierda a derecha de la pantalla)
		// Z = Altura del mapa (Arriba y abajo de la pantalla)
		float PosY = FMath::RandRange(-1200.0f, 1200.0f);
		float PosZ = FMath::RandRange(-600.0f, 600.0f);
		FVector PosicionAleatoria = FVector(2500.0f + (i * 800.0f), PosY, PosZ);

		FRotator Rotacion = FRotator::ZeroRotator;

		// La fábrica polimórfica manufactura la nave correspondiente al nivel actual
		AActor* NuevoEnemigo = FabricaActual->CrearEnemigoPrincipal(World, PosicionAleatoria, Rotacion);

		if (NuevoEnemigo)
		{
			// Se añade al contenedor para que la Fachada vigile su existencia
			RegistroActual->RegistrarEnemigo(NuevoEnemigo);
		}
	}
}

void UGDConstructorNivel::ConstruirPowerUps()
{
	UWorld* World = GetWorld();
	if (!World || !RegistroActual || !FabricaActual) return;

	for (int32 i = 0; i < 2; i++)
	{
		float PosY = FMath::RandRange(-1000.0f, 1000.0f);
		float PosZ = FMath::RandRange(-500.0f, 500.0f);
		FVector Posicion = FVector(3000.0f + (i * 1000.0f), PosY, PosZ);

		// EL ARREGLO: Cambiamos Rotacion::ZeroRotator por FRotator::ZeroRotator
		AActor* NuevoPowerUp = FabricaActual->CrearPowerUpPrincipal(World, Posicion, FRotator::ZeroRotator);

		if (NuevoPowerUp)
		{
			RegistroActual->RegistrarPowerUp(NuevoPowerUp);
		}
	}
}