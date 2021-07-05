#include "linkedList.h"
#include "parse.h"
#include "usuario.h"
#include "post.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parser_postTxt(FILE* pFile , LinkedList* listaPost)
{
     Post* post;
    char idMensaje[40];
    char mensaje[99999];
    char popularidad[40];
    char idUsuario[40];

    int retorno=0;
    printf("hola3");
    if(pFile!=NULL && listaPost!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idMensaje,idUsuario,popularidad,mensaje);

    do
    {
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idMensaje,idUsuario,popularidad,mensaje)==4)
        {
            post=post_newParametros(idMensaje,mensaje,popularidad,idUsuario);
            ll_add(listaPost,post);
                            retorno=1;

        }
        else
        {
            break;
        }
    }while(!feof(pFile));

    }

    return retorno;
}

int parser_usiaroTxt(FILE* pFile , LinkedList* listaUsuario)
{
     Usuario* usuario;
    char idUsuario[50];
    char nick[50];
    char popularidad[50];

    int retorno=0;
    if(pFile!=NULL && listaUsuario!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idUsuario,nick,popularidad);

    do
    {
        if(fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idUsuario,nick,popularidad)==3)
        {
            usuario=usuario_newParametros(idUsuario,nick,popularidad);
            ll_add(listaUsuario,usuario);
                            retorno=1;

        }
        else
        {
            break;
        }
    }while(!feof(pFile));

    }

    return retorno;
}
