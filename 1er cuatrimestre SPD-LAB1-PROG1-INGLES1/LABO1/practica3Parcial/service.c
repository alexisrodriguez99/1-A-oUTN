#include "service.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Service* servise_new()
{
    return (Service*) malloc(sizeof(Service));
}
Service* servise_newParametros(char* id,char* name,char* email)
{
    Service* this;
    this=servise_new();
    if( !service_setId(this,atoi(id)) &&

        !service_getName(this,name) &&
       !service_setEmail(this,email) )
    {
        return this;
    }
    service_delete(this);
    return NULL;
}
void service_delete(Service* this)
{
    free(this);
}
int service_setId(Service* this,int id)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}
int service_getId(Service* this,int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}


int service_setName(Service* this,char* name)
{
    int retorno=-1;
    if(this != NULL && name!= NULL)
    {
        strcpy(this->name,name);
        retorno=0;
    }

    return retorno;
}
int service_getName(Service* this,char* name)
{
    int retorno=-1;
    if(this != NULL && name!= NULL)
    {
        strcpy(name,this->name);
        retorno=0;
    }
    return retorno;
}

int service_setEmail(Service* this,char* email)
{
    int retorno=-1;
    if(this != NULL && email!= NULL)
    {
        strcpy(this->email,email);
        retorno=0;
    }

    return retorno;
}
int service_getEmail(Service* this,char* email)
{
    int retorno=-1;
    if(this != NULL && email!= NULL)
    {
        strcpy(email,this->email);
        retorno=0;
    }
    return retorno;
}
