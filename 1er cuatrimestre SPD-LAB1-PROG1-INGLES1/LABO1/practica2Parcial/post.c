#include "linkedList.h"
#include "post.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Post* post_new()
{
    return (Post*) malloc(sizeof(Post));
}
Post* post_newParametros(char* idMensaje,char* mensaje,char* popularidad,char* idUsuario)
{
    Post* this;
    this=post_new();
    if( !post_setIdMensaje(this,atoi(idMensaje)) &&
        !post_setMensaje(this,mensaje) &&
       !post_setPopularidad(this,atoi(popularidad)) &&
        !post_setIdUsuario(this,atoi(idUsuario)))
    {
        return this;
    }
    post_delete(this);
    return NULL;
}
void post_delete(Post* this)
{
    free(this);
}

int post_setIdMensaje(Post* this,int idMensaje)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->idMensaje= idMensaje;
        retorno = 0;
    }
    return retorno;
}
int post_getIdMensaje(Post* this,int* idMensaje)
{
    int retorno = -1;
    if(this != NULL)
    {
        *idMensaje = this->idMensaje;
        retorno = 0;
    }
    return retorno;
}

int post_setMensaje(Post* this,char* mensaje)
{
    int retorno=-1;
    if(this != NULL && mensaje!= NULL)
    {
        strcpy(this->mensaje,mensaje);
        retorno=0;
    }

    return retorno;
}
int post_getMensaje(Post* this,char* mensaje)
{
    int retorno=-1;
    if(this != NULL && mensaje!= NULL)
    {
        strcpy(mensaje,this->mensaje);
        retorno=0;
    }
    return retorno;
}

int post_setPopularidad(Post* this,int popularidad)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->popularidad = popularidad;
        retorno = 0;
    }
    return retorno;
}
int post_getPopularidad(Post* this,int* popularidad)
{
    int retorno = -1;
    if(this != NULL)
    {
        *popularidad = this->popularidad;
        retorno = 0;
    }
    return retorno;
}


int post_setIdUsuario(Post* this,int idUsuario)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->idUsuario = idUsuario;
        retorno = 0;
    }
    return retorno;
}
int post_getIdUsuario(Post* this,int* idUsuario)
{
    int retorno = -1;
    if(this != NULL)
    {
        *idUsuario = this->idUsuario;
        retorno = 0;
    }
    return retorno;
}
void mostrarPost(Post* post)
{
    if(post!=NULL)
    {
        printf("%4d%15d%15d%13s\n",post->idMensaje,post->idUsuario,post->popularidad,post->mensaje);
    }
}
