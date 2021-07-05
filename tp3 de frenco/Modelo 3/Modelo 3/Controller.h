#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int controller_load(LinkedList* , int (*pFunc)(FILE*, LinkedList*), char* path);
int controller_list(LinkedList*, LinkedList* lista2, void (*pFunc)(void*, LinkedList*));
int controller_escribirLista(LinkedList* listaLog, LinkedList* listaService, char* path);
int controller_procesarInfo(LinkedList* listaLog, LinkedList* listaService);
int controller_mostrarEstadistica(LinkedList* listaLog, LinkedList* listaService);
