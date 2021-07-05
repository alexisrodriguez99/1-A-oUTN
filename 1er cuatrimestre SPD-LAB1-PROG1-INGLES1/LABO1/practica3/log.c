#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"
LogEntry* log_new()
{
    return (LogEntry*) malloc(sizeof(LogEntry));
}
LogEntry* log_newParametros(char* date,char* time,char* serviceId,char* gravedad,char* msg)
{
    LogEntry* this;
    this=log_new();
    if(
        !logEntry_setDate(this,date) &&
       !logEntry_setTime(this,time) &&
        !logEntry_setServiceId(this,atoi(serviceId))&&
       !logEntry_setGravedad(this,atoi(gravedad)) &&
        !logEntry_setMsg(this,msg) )

    {
        return this;
    }
    log_delete(this);
    return NULL;
}
void log_delete(LogEntry* this)
{
    free(this);
}
int logEntry_setDate(LogEntry* this,char* date)
{
    int retorno=-1;
    if(this != NULL && date!= NULL)
    {
        strcpy(this->date,date);
        retorno=0;
    }

    return retorno;
}
int logEntry_getDate(LogEntry* this,char* date)
{
    int retorno=-1;
    if(this != NULL && date!= NULL)
    {
        strcpy(date,this->date);
        retorno=0;
    }
    return retorno;
}

int logEntry_setTime(LogEntry* this,char* time)
{
    int retorno=-1;
    if(this != NULL && time!= NULL)
    {
        strcpy(this->time,time);
        retorno=0;
    }

    return retorno;
}
int logEntry_getTime(LogEntry* this,char* time)
{
    int retorno=-1;
    if(this != NULL && time!= NULL)
    {
        strcpy(time,this->time);
        retorno=0;
    }
    return retorno;
}

int logEntry_setServiceId(LogEntry* this,int serviceId)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->serviceId = serviceId;
        retorno = 0;
    }
    return retorno;
}
int logEntry_getServiceId(LogEntry* this,int* serviceId)
{
    int retorno = -1;
    if(this != NULL)
    {
        *serviceId = this->serviceId;
        retorno = 0;
    }
    return retorno;
}


int logEntry_setGravedad(LogEntry* this,int gravedad)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->gravedad = gravedad;
        retorno = 0;
    }
    return retorno;
}

int logEntry_getGravedad(LogEntry* this,int* gravedad)
{
    int retorno = -1;
    if(this != NULL)
    {
        *gravedad = this->gravedad;
        retorno = 0;
    }
    return retorno;
}


int logEntry_setMsg(LogEntry* this,char* msg)
{
    int retorno=-1;
    if(this != NULL && msg!= NULL)
    {
        strcpy(this->msg,msg);
        retorno=0;
    }

    return retorno;
}
int logEntry_getMsg(LogEntry* this,char* msg)
{
    int retorno=-1;
    if(this != NULL && msg!= NULL)
    {
        strcpy(msg,this->msg);
        retorno=0;
    }
    return retorno;
}

