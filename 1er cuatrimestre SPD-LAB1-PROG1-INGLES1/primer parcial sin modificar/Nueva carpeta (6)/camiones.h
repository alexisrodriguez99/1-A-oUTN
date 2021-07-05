#include <stdio.h>
#include <stdlib.h>

#include "choferes.h"
#define LIBRE -1
#define OCUPADO 1


typedef struct
{
    char patente[20];
  char marca[20];
  int anio;
  float peso;
  int cantidadRuedas;
  char tipo[20];
  int estado;
  int id;
  int idChofer;


} eCamion;
void hardCodearCamion(eCamion listado[],int tam);
void mostrarUnCamion (eCamion listado,eChofer chofer[],int tamChofer);
void mostrarTodosLosCamiones (eCamion listado[], int tam,eChofer chofer[], int tamChofer);
void mostrarSoloCamion(eCamion listado);
void inicializarCamion(eCamion listado[], int tam);

int buscarLibreCamion(eCamion listado[],int tam);
int generadorDeIdCamion(eCamion lista[],int tam);
int bajaCamion(eCamion listadoCamion[],int tamCamion,eChofer listadoChofer[],int tamChofer);
int buscarCamion(eCamion listado[],int tam, int id);
//int pedirEntero(char mensaje[]);
int pedirMarca(eCamion listado[],int tam);
float promedioAnios(eCamion listado[],int tam);
void mostrarPromedioAnios(eCamion listado[],int tam);
