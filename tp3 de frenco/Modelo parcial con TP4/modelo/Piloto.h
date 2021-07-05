#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

typedef struct
{
    int idPiloto;
    char nombre[100];
}Piloto;

void hardcodearPilotos(LinkedList* this);
void* Piloto_new();

int Piloto_setNombre(Piloto* this, char* nombre);
int Piloto_setId(Piloto* this, int nombre);

int Piloto_getNombre(Piloto* this, char*);
int Piloto_getId(Piloto* this, int*);

void Piloto_listar(LinkedList* lista);
void Piloto_Mostrar(Piloto* this);

int Piloto_buscarPorId(LinkedList* lista, int id);
