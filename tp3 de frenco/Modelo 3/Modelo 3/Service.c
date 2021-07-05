#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Service.h"
#include "input.h"

Service* Service_new()
{
    return (Service*) malloc(sizeof(Service));
}
Service* Service_newParametros(char* id, char* name, char* mail)
{
    int flag = 0;
    Service* aux = Service_new();
    if(aux != NULL)
    {
        if(!Service_setId(aux, id) &&
            !Service_setName(aux, name) &&
            !Service_setMail(aux, mail))
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
void Service_mostrar(void* this, LinkedList* lista2)
{
    int id;
    char name[33];
    char mail[65];

    if(this != NULL)
    {
        Service_getId(this, &id);
        Service_getName(this, name);
        Service_getMail(this, mail);

        printf("\n%4d|\t %14s|\t%8s|", id, name, mail);
    }
}
int Service_setId(Service* this, char* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->id = atoi(id);
        retorno = 0;
    }
    return retorno;
}
int Service_setName(Service* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(this->name, nombre);
        retorno = 0;
    }
    return retorno;
}
int Service_setMail(Service* this, char* mail)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(this->mail, mail);
        retorno = 0;
    }
    return retorno;
}

int Service_getId(Service* this, int* id)
{
    int retorno = -1;
    if(this != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}
int Service_getName(Service* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(nombre, this->name);
        retorno = 0;
    }
    return retorno;
}
int Service_getMail(Service* this, char* mail)
{
    int retorno = -1;
    if(this != NULL)
    {
        strcpy(mail, this->mail);
        retorno = 0;
    }
    return retorno;
}

int Service_buscarPorId(LinkedList* lista, int id)
{
    int retorno = -1;
    int idBuscar;
    Service* aux;
    if(lista != NULL && ll_len(lista) > 0)
    {
        retorno = -2;
        for(int i = 0; i < ll_len(lista); i++)
        {
            aux = ll_get(lista, i);
            Service_getId(aux, &idBuscar);
            if(idBuscar == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
