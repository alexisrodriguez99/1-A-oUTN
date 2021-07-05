#include "linkedList.h"
int controller_loadFromTextPost(char* archivo, LinkedList* listaPost);

int controller_loadFromTextUsuario(char* archivo, LinkedList* listaUsuario);
int controller_ListPost(LinkedList* listaPost);
int controller_ListUsuario(LinkedList* listaUsuario);
int controller_guardarOrdenamiento(char* archivo,LinkedList* listaPost,LinkedList* listaUsario);
int ordenamiento(LinkedList* listaPost,LinkedList* listaUsuario);
