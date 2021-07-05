#include <string.h>

#define LIBRE -1
#define OCUPADO 1

typedef struct
{
    char nombre[20];
  char apellido[20];
  char dni[20];
  int legajo;
  char nacionalidad[20];
  char telefono[20];
  int edad;
  char sexo;
  int estado;
  int id;


} eChofer;
void hardCodearChofer(eChofer listado[],int tam);
void mostrarUnChofer (eChofer listado);
void mostrarTodosLosChofer (eChofer listado[], int tam);
eChofer buscarChoferId(eChofer lista[],int tam, int idChofer);
void mostrarNombreChofer(eChofer listado);
int cargarChofer(eChofer listado[],int tam);
int buscarLibreChofer(eChofer listado[],int tam);
int inicializarChofer(eChofer listado[], int tam);
int generadorDeIdChofer(eChofer listado[],int tam);
//void pedirCadena(char mensaje[], char mensajeError[], char laCadena[]);
//int pedirFlotante(char mensaje[]);
//int pedirEntero(char mensaje[]);
char pedirCaracter(char mensaje[]);
void guardarChofer(eChofer listado[],char nombre[],char apellido[],char dni[],int legajo, char nacionalidad[],char telefono[],int edad,char sexo,int estado,int indice);
