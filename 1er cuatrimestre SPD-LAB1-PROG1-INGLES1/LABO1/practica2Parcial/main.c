#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "linkedList.h"
int main()
{
    LinkedList* listaPost;
    LinkedList* listaUsuario;
    listaPost=ll_newLinkedList();
listaUsuario=ll_newLinkedList();


    controller_loadFromTextUsuario("usuarios.csv",listaUsuario);
    controller_loadFromTextPost("mensajes.csv",listaPost);
printf("hola");
    //controller_ListPost(listaPost);
//controller_ListUsuario(listaUsuario);
ordenamiento(listaPost,listaUsuario);
controller_guardarOrdenamiento("feed.csv",listaPost,listaUsuario);
}
