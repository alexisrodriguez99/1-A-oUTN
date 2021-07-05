#include "linkedList.h"

typedef struct
{
    int id;
    int idAvion;
    int idPiloto;
    char fecha[20];
    char destino[50];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
}Vuelo;

Vuelo* vuelo_new();
Vuelo* vuelo_newParametros(char* idVuelo,char* idAvion,char* idPiloto,char* fecha,char* destino,char* cantPasajeros,char* horaDespegue,char* horaLlegada);
void vuelo_delete(Vuelo* this);

int vuelo_setId(Vuelo* this,int id);
int vuelo_getId(Vuelo* this,int* id);

int vuelo_setIdAvion(Vuelo* this,int idAvion);
int vuelo_getIdAvion(Vuelo* this,int* idAvion);

int vuelo_setIdPiloto(Vuelo* this,int idPiloto);
int vuelo_getIdPiloto(Vuelo* this,int* idPiloto);

int vuelo_setFecha(Vuelo* this,char* fecha);
int vuelo_getFecha(Vuelo* this,char* fecha);

int vuelo_setDestino(Vuelo* this,char* destino);
int vuelo_getDestino(Vuelo* this,char* destino);

int vuelo_setCantPasajeros(Vuelo* this,int cantPasajeros);
int vuelo_getCantPasajeros(Vuelo* this,int* cantPasajeros);

int vuelo_setHoraDespegue(Vuelo* this,int horaDespegue);
int vuelo_getHoraDespegue(Vuelo* this,int* horaDespegue);

int vuelo_setHoraLlegada(Vuelo* this,int horaLlegada);
int vuelo_getHoraLlegada(Vuelo* this,int* horaLlegada);

//int buscarNombrePiloto(Vuelo* vuelo,char* nombrePiloto);
void mostrarUnVuelo(Vuelo* vuelo,LinkedList* listaPiloto);

int cantPasajeros(void* pElemento);
void mostrarCantPasajeros(LinkedList* listaVuelo);

int cantPasajerosIrlanda(void* pElemento);
void mostrarCantPasIrlanda(LinkedList* listaVuelo);

int filtrarVueloCorto(void* pElemento);

int filtrarVuelosPortugal(void* pElemento);
//void mostrarListaPortugal(LinkedList* listaVuelo,LinkedList* listaPiloto);
int filtrarVuelosNoAlex(void* pElemento);




//int filtarVueloPorNomPiloto(void* pElemnto,char* nombre,void* pElementoPiloto);
