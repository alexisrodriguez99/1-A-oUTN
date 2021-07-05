#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

int controller_Rodriguez_loadFromText(char* archivo, LinkedList* pArrayListVuelo);
int controller_Rodriguez_ListVuelo(LinkedList* pArrayListVuelo, LinkedList* pArrayListPiloto);
int controller_Rodriguez_guardarVuelosCortos(char* nombreArchivo,LinkedList* listaVuelo);
void controller_Rodriguez_mostrarListaPortugal(LinkedList* listaVuelo,LinkedList* listaPiloto);
void controller_Rodriguez_mostrarListaNoAlex(LinkedList* listaVuelo,LinkedList* listaPiloto);
void controller_Rodriguez_mostrarListFilPil(LinkedList* listaPiloto);
int controller_Rodriguez_listPiloto(LinkedList* listaPiloto);

//int controller_Rodriguez_loadFromTextPiloto(char* archivo, LinkedList* listaPiloto);
