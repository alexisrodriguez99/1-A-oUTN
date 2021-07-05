#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vuelo.h"
#include "piloto.h"
Vuelo* vuelo_new()
{
    return (Vuelo*) malloc(sizeof(Vuelo));
}
Vuelo* vuelo_newParametros(char* idVuelo,char* idAvion,char* idPiloto,char* fecha,char* destino,char* cantPasajeros,char* horaDespegue,char* horaLlegada)
{
    Vuelo* this;
    this=vuelo_new();
    if( !vuelo_setId(this,atoi(idVuelo)) &&
        !vuelo_setIdAvion(this,atoi(idAvion)) &&
        !vuelo_setIdPiloto(this,atoi(idPiloto)) &&
        !vuelo_setFecha(this,fecha) &&
       !vuelo_setDestino(this,destino) &&
        !vuelo_setCantPasajeros(this,atoi(cantPasajeros))&&
       !vuelo_setHoraDespegue(this,atoi(horaDespegue)) &&
        !vuelo_setHoraLlegada(this,atoi(horaLlegada)))
    {
        return this;
    }
    vuelo_delete(this);
    return NULL;
}
void vuelo_delete(Vuelo* this)
{
    free(this);
}
int vuelo_setId(Vuelo* this,int id)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int vuelo_getId(Vuelo* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int vuelo_setIdAvion(Vuelo* this,int idAvion)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->idAvion = idAvion;
        retorno = 0;
    }
    return retorno;
}
int vuelo_getIdAvion(Vuelo* this,int* idAvion)
{
    int retorno = -1;
    if(this != NULL)
    {
        *idAvion = this->idAvion;
        retorno = 0;
    }
    return retorno;
}

int vuelo_setIdPiloto(Vuelo* this,int idPiloto)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->idPiloto = idPiloto;
        retorno = 0;
    }
    return retorno;
}
int vuelo_getIdPiloto(Vuelo* this,int* idPiloto)
{
    int retorno = -1;
    if(this != NULL)
    {
        *idPiloto = this->idPiloto;
        retorno = 0;
    }
    return retorno;
}

int vuelo_setFecha(Vuelo* this,char* fecha)
{
    int retorno=-1;
    if(this != NULL && fecha!= NULL)
    {
        strcpy(this->fecha,fecha);
        retorno=0;
    }

    return retorno;
}
int vuelo_getFecha(Vuelo* this,char* fecha)
{
    int retorno=-1;
    if(this != NULL && fecha!= NULL)
    {
        strcpy(fecha,this->fecha);
        retorno=0;
    }
    return retorno;
}

int vuelo_setDestino(Vuelo* this,char* destino)
{
    int retorno=-1;
    if(this != NULL && destino!= NULL)
    {
        strcpy(this->destino,destino);
        retorno=0;
    }

    return retorno;
}
int vuelo_getDestino(Vuelo* this,char* destino)
{
    int retorno=-1;
    if(this != NULL && destino!= NULL)
    {
        strcpy(destino,this->destino);
        retorno=0;
    }
    return retorno;
}

int vuelo_setCantPasajeros(Vuelo* this,int cantPasajeros)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->cantPasajeros = cantPasajeros;
        retorno = 0;
    }
    return retorno;
}
int vuelo_getCantPasajeros(Vuelo* this,int* cantPasajeros)
{
    int retorno = -1;
    if(this != NULL)
    {
        *cantPasajeros = this->cantPasajeros;
        retorno = 0;
    }
    return retorno;
}

int vuelo_setHoraDespegue(Vuelo* this,int horaDespegue)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->horaDespegue = horaDespegue;
        retorno = 0;
    }
    return retorno;
}
int vuelo_getHoraDespegue(Vuelo* this,int* horaDespegue)
{
    int retorno = -1;
    if(this != NULL)
    {
        *horaDespegue = this->horaDespegue;
        retorno = 0;
    }
    return retorno;
}

int vuelo_setHoraLlegada(Vuelo* this,int horaLlegada)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->horaLlegada = horaLlegada;
        retorno = 0;
    }
    return retorno;
}
int vuelo_getHoraLlegada(Vuelo* this,int* horaLlegada)
{
    int retorno = -1;
    if(this != NULL)
    {
        *horaLlegada = this->horaLlegada;
        retorno = 0;
    }
    return retorno;
}
/*int buscarNombrePiloto(Vuelo* vuelo,char* nombrePiloto)
{
    int i;
    Piloto* piloto;
    int idPiloto;
    int idPilotoAvion;
    int* id;
    vuelo_getIdPiloto(vuelo,&idPilotoAvion);
    for(i=0;i<5;i++)
    {
     piloto_getId()
        if(idPilotoAvion=)
    }
}*/
void mostrarUnVuelo(Vuelo* vuelo,LinkedList* listaPiloto)
{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[50];
    char destino[50];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
    int indice;
    Piloto* piloto;
    char nombrePiloto[50];
    if(vuelo!=NULL)
    {
        vuelo_getId(vuelo,&idVuelo);
        vuelo_getIdAvion(vuelo,&idAvion);
        vuelo_getIdPiloto(vuelo,&idPiloto);
        vuelo_getFecha(vuelo,fecha);
        vuelo_getDestino(vuelo,destino);
        vuelo_getCantPasajeros(vuelo,&cantPasajeros);
        vuelo_getHoraDespegue(vuelo,&horaDespegue);
        vuelo_getHoraLlegada(vuelo,&horaLlegada);

        indice=buscarPiltoId(listaPiloto,idPiloto);
        //printf("el indice es %d",indice);
        piloto=ll_get(listaPiloto,indice);
        piloto_getNombre(piloto,nombrePiloto);

        printf("%8d %8d %16s %15s %15s %16d %16d %16d\n",idVuelo,idAvion,nombrePiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
    }
}
int cantPasajeros(void* pElemento)
{
    int cantidad=0;

    if(pElemento!=NULL)
    {
        vuelo_getCantPasajeros(pElemento,&cantidad);
    }
    return cantidad;
}
void mostrarCantPasajeros(LinkedList* listaVuelo)
{
    int total;
    if(listaVuelo!=NULL)
    {
        total=ll_count(listaVuelo,cantPasajeros);
        printf("La cantidad de pasajeros total es de: %d\n",total);
    }
}
int cantPasajerosIrlanda(void* pElemento)
{
    int cantPasajeros=0;
    char destino[50];
    if(pElemento!=NULL)

    {vuelo_getDestino(pElemento,destino);
        if(strcmp(destino,"Irlanda")==0)
        {
          vuelo_getCantPasajeros(pElemento,&cantPasajeros);
        }
    }
    return cantPasajeros;
}
void mostrarCantPasIrlanda(LinkedList* listaVuelo)
{

    int total;

    if(listaVuelo!=NULL)
    {
        total=ll_count(listaVuelo,cantPasajerosIrlanda);
        printf("La cantidad de pasajeros a Irlanda son: %d\n",total);
    }
}
int filtrarVueloCorto(void* pElemento)
{
    int retorno=0;
    int horaLlegada;
    int horaDespegue;

    if(pElemento!=NULL)
    {
        vuelo_getHoraDespegue(pElemento,&horaDespegue);
        vuelo_getHoraLlegada(pElemento,&horaLlegada);
        if((horaLlegada-horaDespegue)<3)
        {
            retorno=1;
        }
    }
    return retorno;
}
int filtrarVuelosPortugal(void* pElemento)
{
    char destino[50];
    int retorno=0;
    if(pElemento!=NULL)
    {
        vuelo_getDestino(pElemento,destino);
            if(strcmp(destino,"Portugal")==0)
            {
                retorno=1;
            }
    }
    return retorno;
}
/*void mostrarListaPortugal(LinkedList* listaVuelo,LinkedList* listaPiloto)
{
    LinkedList* listaPortual;

    listaPortual=ll_newLinkedList();
    if(listaVuelo!=NULL)
    {
        controller_ListVuelo(listaPortual,listaPiloto);

    }
}*/
int filtrarVuelosNoAlex(void* pElemento)
{
    int idPiloto;
    int retorno=0;
    if(pElemento!=NULL)
    {
        vuelo_getIdPiloto(pElemento,&idPiloto);
        if(idPiloto!=1)
        {
            retorno=1;
        }
    }
    return retorno;
}




/*int filtarVueloPorNomPiloto(void* pElemnto,char* nombre,void* pElementoPiloto)
{
    char nombrePiloto[50];
    int idPiloto;
    int indexPiloto;
    Piloto piloto;
    int retorno=0;
    if(pElemnto!=NULL)
    {
        vuelo_getId(pElemnto,&idPiloto);
        indexPiloto=buscarPiltoId(pElementoPiloto,idPiloto);
        piloto=ll_get(pElementoPiloto,indexPiloto);
        piloto_getNombre(piloto,nombrePiloto);
        if(strcmp(nombrePiloto,nombre)==0)
        {
            retorno=1;
        }

    }
    return retorno;
}*/
