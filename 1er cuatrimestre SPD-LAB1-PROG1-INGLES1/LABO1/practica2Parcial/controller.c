#include "controller.h"
#include "parse.h"
#include "linkedList.h"
#include "post.h"
#include "usuario.h"

int controller_loadFromTextPost(char* archivo, LinkedList* listaPost)
{

    FILE* pFile;
    int vacio;
    int retorno=0;
    pFile=fopen(archivo,"r");
    if(pFile!=NULL && listaPost!=NULL)
    {
        vacio=ll_isEmpty(listaPost);
        if(vacio==1)
        {
            printf("hola2");
            retorno=parser_postTxt(pFile,listaPost);

        }

    }
    fclose(pFile);
    return retorno;
}
int controller_loadFromTextUsuario(char* archivo, LinkedList* listaUsuario)
{

    FILE* pFile;
    int vacio;
    int retorno=0;
    pFile=fopen(archivo,"r");
    if(pFile!=NULL && listaUsuario!=NULL)
    {
        vacio=ll_isEmpty(listaUsuario);
        if(vacio==1)
        {
            retorno=parser_usiaroTxt(pFile,listaUsuario);
        }

    }
    fclose(pFile);
    return retorno;
}
int controller_ListPost(LinkedList* listaPost)
{
    int retorno=-1;
    int i;
    int cantidad;
    Post* post;
    cantidad=ll_len(listaPost);
    if(listaPost!=NULL)
    {
        retorno=1;
        printf("%4s%15s%20s%8s\n","Id","Nombre","HorasTrabajadas","Sueldo");

        for(i=0; i<cantidad; i++)
        {
            post=ll_get(listaPost,i);
            mostrarPost(post);

        }
    }
    return retorno;
}
int controller_ListUsuario(LinkedList* listaUsuario)
{
    int retorno=-1;
    int i;
    int cantidad;
    Usuario* usuario;
    cantidad=ll_len(listaUsuario);
    if(listaUsuario!=NULL)
    {
        retorno=1;
        printf("%4s%15s%20s%8s\n","Id","Nombre","HorasTrabajadas","Sueldo");

        for(i=0; i<cantidad; i++)
        {
            usuario=ll_get(listaUsuario,i);
            mostrarUsuario(usuario);

        }
    }
    return retorno;
}

int ordenamiento(LinkedList* listaPost,LinkedList* listaUsuario)
{
   Usuario* usuario1;
      Usuario* usuario2;

    Post* post1;
    Post* post2;
    int i;
    int j;
    int menPopu1;
    int menPopu2;
    int usuarioPop1;
    int usuarioPop2;
    int id1;
    int id2;
    int idUsuario1;
    int idUsuario2;
    Post* mensajeAux;
    for(i=0;i<ll_len(listaPost)-1;i++)
    {
        for(j=i+1;j<ll_len(listaPost);j++)
        {
           /* */

            post1=ll_get(listaPost,i);
            post2=ll_get(listaPost,j);

            post_getPopularidad(post1,&menPopu1);
            post_getPopularidad(post2,&menPopu2);

            post_getIdUsuario(post1,&id1);
            post_getIdUsuario(post2,&id2);

            idUsuario1=buscarUsuarioId(listaUsuario,id1);
            idUsuario2=buscarUsuarioId(listaUsuario,id2);

            usuario1=ll_get(listaUsuario,idUsuario1);
            usuario2=ll_get(listaUsuario,idUsuario2);



            usuario_getPopularidad(usuario1,&usuarioPop1);
            usuario_getPopularidad(usuario2,&usuarioPop2);
            if((usuarioPop2>usuarioPop1) || (usuarioPop1==usuarioPop2 && menPopu2>menPopu1))
            {
                mensajeAux=ll_get(listaPost,i);
                ll_set(listaPost,i,ll_get(listaPost,j));
                ll_set(listaPost,j,mensajeAux);
            }

        }


    }
    return 1;
}
int controller_guardarOrdenamiento(char* archivo,LinkedList* listaPost,LinkedList* listaUsario)
{
    FILE* pFIle;
    pFIle=fopen(archivo,"w");
    int cantidad;
    int i;
    int idMensaje;
    char mensaje[50000];
    int popularidadMsg;
    int idUsuario;
    char nick[100];
    int popularidad;
    int retorno=-1;
    Post* post;
    Usuario* usuario;
    if(pFIle!=NULL && listaPost!=NULL)
    {
        cantidad=ll_len(listaPost);
        fprintf(pFIle,"%s, %s, %s, %s\n","ID","NOMBRE","HORAS TABAJADAS","SUELDO");
        for(i=0;i<cantidad;i++)
        {
            post=(Post*)ll_get(listaPost,i);

            post_getIdMensaje(post,&idMensaje);
            post_getIdUsuario(post,&idUsuario);
            post_getPopularidad(post,&popularidadMsg);
            post_getMensaje(post,mensaje);

            usuario=ll_get(listaUsario,buscarUsuarioId(listaUsario,idUsuario));

            usuario_getNick(usuario,nick);
            usuario_getPopularidad(usuario,&popularidad);

            fprintf(pFIle, "%d,||%d,||%d||,%d,%s,%s\n", idMensaje,popularidad,popularidadMsg,idUsuario,nick,mensaje);
        }
        retorno=1;
    }
    fclose(pFIle);

    return retorno;
}
