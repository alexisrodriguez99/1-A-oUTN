#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Piloto.h"
#include "Input.h"


typedef struct
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[11];
    char destino[50];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}Vuelo;

void* Vuelo_new();
void* Vuelo_newParametro(char* idVuelo, char* idAvion, char* idPiloto, char* fecha, char* destino, char* cantPasajeros, char* horaDespegue, char* horaLlegada);
void Vuelo_mostrarVuelo(Vuelo* this, LinkedList* listaPilotos);
void Vuelo_listar(LinkedList* lista, LinkedList* listaPilotos);

int Vuelo_cargarDeTexto(LinkedList* lista);
int parser_VueloFromText(FILE* pFile, LinkedList* lista);
int Vuelo_guardar(LinkedList* lista);

int Vuelo_setDestino(Vuelo* this, char* destino);
int Vuelo_setFecha(Vuelo* this, char* fecha);
int Vuelo_setIdVuelo(Vuelo* this, char* id);
int Vuelo_setIdAvion(Vuelo* this, char* id);
int Vuelo_setIdPiloto(Vuelo* this, char* id);
int Vuelo_setCantPasajeros(Vuelo* this, char* num);
int Vuelo_setHoraDespegue(Vuelo* this, char* num);
int Vuelo_setHoraLlegada(Vuelo* this, char* num);


int Vuelo_getDestino(Vuelo* this, char* destino);
int Vuelo_getFecha(Vuelo* this, char* fecha);
int Vuelo_getIdVuelo(Vuelo* this, int* id);
int Vuelo_getIdAvion(Vuelo* this, int* id);
int Vuelo_getIdPiloto(Vuelo* this, int* id);
int Vuelo_getCantPasajeros(Vuelo* this, int* num);
int Vuelo_getHoraDespegue(Vuelo* this, int* num);
int Vuelo_getHoraLlegada(Vuelo* this, int* num);

int contarPasajeros(void*);
int filtrarIrlanda(void*);
int filtrarPortugal(void*);
int filtrarMenos3Horas(void* pelement);
int filtrarPiloto(void*);
