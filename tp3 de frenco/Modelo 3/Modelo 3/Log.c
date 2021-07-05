#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Log.h"
#include "Service.h"
#include "input.h"

LogEntry* LogEntry_new()
{
    return (LogEntry*) malloc(sizeof(LogEntry));
}
LogEntry* LogEntry_newParametros(char* fecha, char* hora, char* serviceId, char* gravedad, char* msg)
{
    int flag = 0;
    LogEntry* aux = LogEntry_new();
    if(aux != NULL)
    {
        if(!LogEntry_setFecha(aux, fecha) &&
                !LogEntry_setHora(aux, hora) &&
                !LogEntry_setServiceId(aux, serviceId) &&
                !LogEntry_setGravedad(aux, gravedad) &&
                !LogEntry_setMsg(aux, msg))
        {
            flag = 1;
        }
        if(flag == 0)
        {
            free(aux);
            aux = NULL;
        }
    }
    return aux;
}
void LogEntry_mostrar(void* this, LinkedList* listaServicios)
{
    char fecha[11];
    char hora[6];
    int ServiceId;
    int gravedad;
    char msg[65];

    char name[33];
    Service* aux;
    if(this != NULL)
    {
        LogEntry_getFecha(this, fecha);
        LogEntry_getHora(this, hora);
        LogEntry_getServiceId(this, &ServiceId);
        LogEntry_getGravedad(this, &gravedad);
        LogEntry_getMsg(this, msg);

        aux = (Service*) ll_get(listaServicios, Service_buscarPorId(listaServicios, ServiceId));

        if(aux != NULL)
        {
            Service_getName(aux, name);
            printf("\n%14s|\t%8s|\t%15s|\t%4d|\t%s", fecha, hora, name, gravedad, msg);
        }
    }
}
int LogEntry_setServiceId(LogEntry* this, char* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->ServiceId = atoi(id);
        retorno = 0;
    }
    return retorno;
}
int LogEntry_setGravedad(LogEntry* this, char* gravedad)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->gravedad = atoi(gravedad);
        retorno = 0;
    }
    return retorno;
}
int LogEntry_setFecha(LogEntry* this, char* fecha)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(this->fecha, fecha);
        retorno = 0;
    }
    return retorno;
}
int LogEntry_setHora(LogEntry* this, char* hora)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(this->hora, hora);
        retorno = 0;
    }
    return retorno;
}
int LogEntry_setMsg(LogEntry* this, char* msg)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(this->msg, msg);
        retorno = 0;
    }
    return retorno;
}

int LogEntry_getServiceId(LogEntry* this, int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->ServiceId;
        retorno = 0;
    }
    return retorno;
}
int LogEntry_getGravedad(LogEntry* this, int* gravedad)
{
    int retorno = -1;
    if(this != NULL)
    {
        *gravedad = this->gravedad;
        retorno = 0;
    }
    return retorno;
}
int LogEntry_getFecha(LogEntry* this, char* fecha)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(fecha, this->fecha);
        retorno = 0;
    }
    return retorno;
}
int LogEntry_getHora(LogEntry* this, char* hora)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(hora, this->hora);
        retorno = 0;
    }
    return retorno;
}
int LogEntry_getMsg(LogEntry* this, char* msg)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(msg, this->msg);
        retorno = 0;
    }
    return retorno;
}

int LogEntry_filtrarGravedadMenor3(void* pElement)
{
    int returnAux = 0;
    int gravedad;

    if(pElement != NULL)
    {
        LogEntry_getGravedad(pElement, &gravedad);
        if(gravedad < 3)
        {
            returnAux = 1;
        }
    }

    return returnAux;
}
int LogEntry_filtrarGravedadIgual3(void* pElement)
{
    int returnAux = 0;
    int gravedad;
    int id;

    if(pElement != NULL)
    {
        LogEntry_getGravedad(pElement, &gravedad);
        LogEntry_getServiceId(pElement, &id);
        if(gravedad == 3 && id != 45)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}
int LogEntry_filtrarGravedadDe4a7(void* pElement)
{
    int returnAux = 0;
    int gravedad;

    if(pElement != NULL)
    {
        LogEntry_getGravedad(pElement, &gravedad);
        if(gravedad >= 4 && gravedad <= 7)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}
int LogEntry_filtrarGravedadMayor7(void* pElement)
{
    int returnAux = 0;
    int gravedad;

    if(pElement != NULL)
    {
        LogEntry_getGravedad(pElement, &gravedad);
        if(gravedad > 7)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}
