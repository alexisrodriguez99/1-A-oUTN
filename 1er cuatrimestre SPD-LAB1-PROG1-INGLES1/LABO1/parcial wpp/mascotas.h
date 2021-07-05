#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"

typedef struct
{
  char nombre[20];
  int tipo;
  char raza[20];
  int edad;
  int peso;
  char sexo;
  int estado;
  int id;
  int idCliente;
} eMascota;
void hardCodearMascota(eMascota listado[],int tam);
void mostrarSoloMascota(eMascota listado);
void mostarTodasSoloMascota(eMascota listado[],int tam);
void mostarUnaMascota (eMascota listado,eCliente cliente[],int tamCliente);
void mostarTodasLasMascotas (eMascota listado[], int tam,eCliente cliente[],int tamCliente);
int buscarLibre(eMascota listado[], int tam);
void inicializarMascota(eMascota listado[],int tam);
