#include <stdio.h>
#include <stdlib.h>

#include "choferes.h"
#define LIBRE -1
#define OCUPADO 1
typedef struct
{
    int idMarca;
    char nombre[20];
  char pais[20];


} eMarca;

typedef struct
{
    char patente[20];
  int idMarca;
  int anio;
  float peso;
  int cantidadRuedas;
  char tipo[20];
  int estado;
  int id;
  int idChofer;


} eCamion;
void hardCodearMarca(eMarca listado[],int tamMarca);
void hardCodearCamion(eCamion listado[],int tam);
void mostrarUnCamion (eCamion listado,eChofer chofer[],int tamChofer,eMarca marca[],int tamMarca);
void mostrarTodosLosCamiones (eCamion listado[], int tam,eChofer chofer[], int tamChofer,eMarca marca[],int tamMarca);
void mostrarSoloCamion(eCamion listado,eMarca marca[],int tamMarca);
void inicializarCamion(eCamion listado[], int tam);

int buscarLibreCamion(eCamion listado[],int tam);
int generadorDeIdCamion(eCamion lista[],int tam);
int bajaCamion(eCamion listadoCamion[],int tamCamion,eChofer listadoChofer[],int tamChofer,eMarca listaMarca[],int tamMarca);
int buscarCamion(eCamion listado[],int tam, int id);
//int pedirEntero(char mensaje[]);
int pedirMarca(eCamion listado[],int tam,eMarca marca[],int tamMarca);
float promedioAnios(eCamion listado[],int tam);
void mostrarPromedioAnios(eCamion listado[],int tam);
