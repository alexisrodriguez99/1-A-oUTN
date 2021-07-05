#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
typedef struct
{
    int id;
    char nombre[50];

}Piloto;
void hardCodearPiloto(LinkedList* this);
int piloto_getId(Piloto* this,int* id);

int piloto_getNombre(Piloto* this,char* nombre);
Piloto* piloto_new();
int buscarPiltoId(LinkedList* this, int idPiloto);
int filtrarPiloto(void* pElemento,char* nombre);
void mostrarUnPiloto(Piloto* piloto);
int piloto_setId(Piloto* this,int id);

int piloto_setNombre(Piloto* this,char* nombre);
void piloto_delete(Piloto* this);

Piloto* piloto_newParametros(char* id,char* nombre);
//int filtrarPiloto2(void* pElemento,char* nombre);
