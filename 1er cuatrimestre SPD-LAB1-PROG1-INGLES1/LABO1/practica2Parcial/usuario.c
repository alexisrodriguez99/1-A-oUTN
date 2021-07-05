#include "linkedList.h"
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Usuario* usuario_new()
{
    return (Usuario*) malloc(sizeof(Usuario));
}
Usuario* usuario_newParametros(char* idUsuario,char* nick,char* popularidad)
{
    Usuario* this;
    this=usuario_new();
    if( !usuario_setIdUsuario(this,atoi(idUsuario)) &&
        !usuario_setNick(this,nick) &&
       !usuario_setPopularidad(this,atoi(popularidad)))
    {
        return this;
    }
    usuario_delete(this);
    return NULL;
}
void usuario_delete(Usuario* this)
{
    free(this);
}
int usuario_setIdUsuario(Usuario* this,int idUsuario)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->idUsuario = idUsuario;
        retorno = 0;
    }
    return retorno;
}
int usuario_getIdUsuario(Usuario* this,int* idUsuario)
{
    int retorno = -1;
    if(this != NULL)
    {
        *idUsuario = this->idUsuario;
        retorno = 0;
    }
    return retorno;
}

int usuario_setNick(Usuario* this,char* nick)
{
    int retorno=-1;
    if(this != NULL && nick!= NULL)
    {
        strcpy(this->nick,nick);
        retorno=0;
    }

    return retorno;
}
int usuario_getNick(Usuario* this,char* nick)
{
    int retorno=-1;
    if(this != NULL && nick!= NULL)
    {
        strcpy(nick,this->nick);
        retorno=0;
    }
    return retorno;
}

int usuario_setPopularidad(Usuario* this,int popularidad)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->popularidad = popularidad;
        retorno = 0;
    }
    return retorno;
}
int usuario_getPopularidad(Usuario* this,int* popularidad)
{
    int retorno = -1;
    if(this != NULL)
    {
        *popularidad = this->popularidad;
        retorno = 0;
    }
    return retorno;
}
void mostrarUsuario(Usuario* usuario)
{
    if(usuario!=NULL)
    {
        printf("%4d%15s%15d\n",usuario->idUsuario,usuario->nick,usuario->popularidad);
    }
}
int buscarUsuarioId(LinkedList* listaUsuario,int id)
{

    int idComparar;
    int i;
    int retorno;
    Usuario* usuario;
    for(i=0;i<ll_len(listaUsuario);i++)
    {
        usuario=ll_get(listaUsuario,i);
        usuario_getIdUsuario(usuario,&idComparar);
        if(idComparar==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
